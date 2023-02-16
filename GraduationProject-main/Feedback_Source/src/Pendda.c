/* $Date:  $
 * $Revision: 0.99 $
 * $Author: EZ $
 *
 * File: plc812Enc.c
 *
 * Abstract:
 *      S-Function device driver for DAC of PCL812 I/O Board      
 *
 * Copyright (c) 
 */

#define S_FUNCTION_NAME	pendda
#define S_FUNCTION_LEVEL 2

#include <stdio.h>
#include  <stdlib.h>     /* malloc(), free(), strtoul() */
#include "simstruc.h"    /* the simstruct access macros */


/*=========================================================================*
 * Number of S-function Parameters and macros to access from the SimStruct *
 *=========================================================================*/
#define NUM_PARAMS                 (5)
#define BASE_ADDRESS_PARAM         (ssGetSFcnParam(S,0))
// let the user access only one channel per block
#define CHANNEL_TO_USE_PARAM       (ssGetSFcnParam(S,1)) 
#define DAC_REFERENCE              (ssGetSFcnParam(S,2))
#define SAMPLE_TIME_PARAM          (ssGetSFcnParam(S,3))
#define ACCESS_HW_PARAM            (ssGetSFcnParam(S,4))

/*==================================================*
 * Macros to access the S-function parameter values *
 *==================================================*/
#define SAMPLE_TIME          ((real_T) mxGetPr(SAMPLE_TIME_PARAM)[0])
#define OUT_CHANNEL          ((uint_T) mxGetPr(CHANNEL_TO_USE_PARAM)[0])
#define RANGE                ((real_T) mxGetPr(DAC_REFERENCE)[0])  

/*========================================================*
 * (Hardware Specific) Macros pertaining to the I/O board *
 *========================================================*/
#ifndef ACCESS_HW
# define ACCESS_HW                  (mxGetPr(ACCESS_HW_PARAM)[0] != 0.0)
#endif

#include "pcl812def.h"


/*======================*
 * Miscellaneous macros *
 *======================*/
#define BASE_ADDR_PARAM_STRLEN     (128)

/*======================*
 * S-function User Data *
 *======================*/
typedef struct {
    uint_T    baseAddr;
} DACInfo;


/*====================*
 * S-function methods *
 *====================*/


#define MDL_CHECK_PARAMETERS     /* Change to #undef to remove function */
#if defined(MDL_CHECK_PARAMETERS) && defined(MATLAB_MEX_FILE)

/*===============================================
 * Function: mdlCheckParameters 
 *===============================================
 */
static void mdlCheckParameters(SimStruct *S)
{
    static char_T errMsg[256];
    boolean_T allParamsOK = 1;
    int_T numChannels, initialOutLen, finalOutLen;

    /*
     * Base I/O Address
     */
    if (!mxIsChar(BASE_ADDRESS_PARAM)) {
        sprintf(errMsg, "Base address parameter must be a string.\n");
        allParamsOK = 0;
        goto EXIT_POINT;
    }
    /*
     * Sample Time
     */
    if (mxGetNumberOfElements(SAMPLE_TIME_PARAM) != 1) {
        sprintf(errMsg, "Sample Time must be a positive scalar.\n");
        allParamsOK = 0;
        goto EXIT_POINT;
    }
    /*
     * Access Hardware
     */
    if (ACCESS_HW != 0 && ACCESS_HW != 1) {
        sprintf(errMsg, "Hardware access parameter is %d, expecting 0 or 1.\n",
                ACCESS_HW);
        allParamsOK = 0;
        goto EXIT_POINT;
    }

EXIT_POINT:
    if (!allParamsOK) {
        ssSetErrorStatus(S, errMsg);
    }
}
#endif /* MDL_CHECK_PARAMETERS */




/*=============================================== 
 * Function: mdlInitializeSizes 
 *===============================================
 */
static void mdlInitializeSizes(SimStruct *S)
{
	ssSetNumSFcnParams(S, NUM_PARAMS);
	if (ssGetNumSFcnParams(S) == ssGetSFcnParamsCount(S)) {
		
		if (ssGetErrorStatus(S) != NULL) {
          return;        /* Error reported in mdlCheckParameters */
       }
    } else {
       return; /* Parameter mismatch will be reported by Simulink */
    }

    /* None of this s-functions's parameters are tunable during simulation */
    {
        int_T i;
        for (i=0; i < NUM_PARAMS; i++) {
            ssSetSFcnParamNotTunable(S, i);
        }
    }

    ssSetNumSampleTimes  ( S, 1);
    ssSetNumInputPorts   ( S, 1);
	ssSetInputPortWidth  ( S, 0, 1);
// DAC outputs directly to the port
    ssSetNumOutputPorts  ( S, 0); 
	 
}	



/* Function: mdlInitializeSampleTimes =========================================
 *
 */
static void mdlInitializeSampleTimes(SimStruct *S)
{
    ssSetSampleTime(S, 0, SAMPLE_TIME);
    ssSetOffsetTime(S, 0, 0.0);
}



#define MDL_START  /* Change to #undef to remove function */
#if defined(MDL_START)
/* Function: mdlStart =========================================================
 *
 */
static void mdlStart(SimStruct *S)
{
    if (ACCESS_HW && (ssGetSimMode(S) != SS_SIMMODE_RTWGEN)) {
        DACInfo *diInfo = ssGetUserData(S);
        char_T baseAddrStr[BASE_ADDR_PARAM_STRLEN];
        uint_T baseAddr;
// required for initial voltage selection ...
		real_T	value;
		uint_T  zeroDac;


        /* Initialize diInfo (pointer saved in the user data) */
        mxGetString(BASE_ADDRESS_PARAM, baseAddrStr, BASE_ADDR_PARAM_STRLEN);
        baseAddr = (uint_T) strtoul(baseAddrStr, NULL, 0);
		
        if (diInfo != NULL) {
            free(diInfo);
        }
        if ((diInfo = malloc(sizeof(DACInfo))) == NULL) {
            ssSetErrorStatus(S,"Memory Allocation Error\n");
            return;
        }
        diInfo->baseAddr   = baseAddr;
        ssSetUserData(S, (void*) diInfo);
  
		// do initialiazation here ...


		value = (2.5/RANGE)*4096;
		zeroDac = (uint_T) value;
        
//		printf("PCL812: Hardware Access Enabled\n");
    } else if (ssGetSimMode(S) == SS_SIMMODE_NORMAL) {
        printf("PCL812: Hardware Access Disabled\n");
    }
}
#endif /* MDL_START */

/* Function: mdlOutputs =======================================================
 *
 */
static void mdlOutputs(SimStruct *S, int_T tid)
{
  if (ACCESS_HW && (ssGetSimMode(S) != SS_SIMMODE_RTWGEN)) 
  {
	  DACInfo            *diInfo  = ssGetUserData(S);
	  InputRealPtrsType  uPtrs  = ssGetInputPortRealSignalPtrs(S,0);
	  uint_T             baseAddr = diInfo->baseAddr;
      real_T			 value;
	  uint_T             codeValue;

	  // the main difference between pcl812da and pend812da 
	  value = ((*uPtrs[0]+2.5)/RANGE) *4096 ;
	  codeValue = (uint_T) value;
	  pcl812_writeToDac(baseAddr, OUT_CHANNEL, codeValue);
	}
// else do nothing      
}



/* Function: mdlTerminate =====================================================
 *
 */
static void mdlTerminate(SimStruct *S)
{
   DACInfo *dacInfo = ssGetUserData(S);
	
	if (ACCESS_HW && dacInfo && (ssGetSimMode(S) != SS_SIMMODE_RTWGEN)) 
	{
		uint_T baseAddr = dacInfo->baseAddr;
		real_T	value;
		uint_T  zeroDac;

		value = (2.5/RANGE)*4096;
		zeroDac = (uint_T) value;


		// set both of the outputs to zero 
		pcl812_writeToDac(baseAddr, 0, zeroDac);
		pcl812_writeToDac(baseAddr, 1, zeroDac);

		printf("PCL812: Dac outputs is set to 2.5 Volts \n");  
	}

	free(dacInfo);
    ssSetUserData(S,NULL);
}



/*=============================*
 * Required S-function trailer *
 *=============================*/
#ifdef MATLAB_MEX_FILE
#include "simulink.c"     
#else
#include "cg_sfun.h"
#endif

/* EOF: plc812Enc.c */
