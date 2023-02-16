/* $Date:  $
 * $Revision: 0.99 $
 * $Author: EZ $
 *
 * File: plc812FedEnc.c
 *
 * Abstract:
 *      S-Function device driver for the FeedBack Encoders
  *     Using the  PCL812 I/O Board      
 *
 * Copyright (c) 
 */

#define S_FUNCTION_NAME	pcl812FedEnc
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
#define SAMPLE_TIME_PARAM          (ssGetSFcnParam(S,2))
#define ENC_OFFSET_VALUE           (ssGetSFcnParam(S,3))
#define ACCESS_HW_PARAM            (ssGetSFcnParam(S,4))

/*==================================================*
 * Macros to access the S-function parameter values *
 *==================================================*/
#define SAMPLE_TIME          ((real_T) mxGetPr(SAMPLE_TIME_PARAM)[0])
#define CHANNEL              ((uint_T) mxGetPr(CHANNEL_TO_USE_PARAM)[0])
#define OFFSET               ((real_T) mxGetPr(ENC_OFFSET_VALUE)[0])

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
} DIOInfo;


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
    ssSetNumInputPorts   ( S, 0);
	ssSetNumOutputPorts  ( S, 1);
	ssSetOutputPortWidth (S, 0, 1); // can read only one channel per block
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
        DIOInfo *dioInfo = ssGetUserData(S);
        char_T baseAddrStr[BASE_ADDR_PARAM_STRLEN];
        uint_T baseAddr;

        /* Initialize diInfo (pointer saved in the user data) */
        mxGetString(BASE_ADDRESS_PARAM, baseAddrStr, BASE_ADDR_PARAM_STRLEN);
        baseAddr = (uint_T) strtoul(baseAddrStr, NULL, 0);

        if (dioInfo != NULL) {
            free(dioInfo);
        }
        if ((dioInfo = malloc(sizeof(DIOInfo))) == NULL) {
            ssSetErrorStatus(S,"Memory Allocation Error\n");
            return;
        }
        dioInfo->baseAddr   = baseAddr;
        ssSetUserData(S, (void*) dioInfo);
  
		// do initialiazation here ...
		pcl812_resetEncoder(baseAddr);

    
		//printf("PCL812: Hardware Access Enabled\n");
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
  real_T *y = ssGetOutputPortRealSignal(S,0);

  if (ACCESS_HW && (ssGetSimMode(S) != SS_SIMMODE_RTWGEN)) 
  {
	  DIOInfo            *dioInfo  = ssGetUserData(S);
	  InputRealPtrsType  uPtrs  = ssGetInputPortRealSignalPtrs(S,0);
	  uint_T             baseAddr = dioInfo->baseAddr;
      int_T              count0=0, count1=0;
	//  uint_T             codeValue;
	  real_T             dummy;

	 // code direclt form MES...
	  //make sure count is not latched
	  pcl812_writeLowDigout(baseAddr, 0x07);
	  //latch count read high bytes
	  pcl812_writeLowDigout(baseAddr, 0x04);

	  count0 = inp(baseAddr+6);
	  count0 <<= 8;
 	  count1 = inp(baseAddr+7);
	  count1 <<= 8;
	  //read low bytes
	  pcl812_writeLowDigout(baseAddr, 0x06);
	  count0 += (char)inp(baseAddr+6);
	  count1 += (char)inp(baseAddr+7);
	  // unlatch count
	  pcl812_writeLowDigout (baseAddr, 0x07);

	  //sign extend to negative
	  if (count0 & 0x00008000) {
		  count0 |= 0xFFFF8000;
	  }

	  if (count1 & 0x00008000) {
		  count1 |= 0xFFFF8000;
	  }

// select channel and fed the value back..
	  if (CHANNEL == 0)
	  {
		  dummy = (real_T)count0;
	  }
	  else
	  {
		  dummy = (real_T)count1;
	  }
		  y[0] = dummy + OFFSET;
	
	}
// else do nothing      
}



/* Function: mdlTerminate =====================================================
 *
 */
static void mdlTerminate(SimStruct *S)
{
   DIOInfo *dioInfo = ssGetUserData(S);
	
	free(dioInfo);
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
