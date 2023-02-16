/* $Date:  $
 * $Revision: 0.99 $
 * $Author: EZ $
 *
 * File: plc812ad.c
 *
 * Abstract:
 *      S-Function device driver for ADC of PCL812 I/O Board      
 *
 * Copyright (c) 
 */

#define S_FUNCTION_NAME	pcl812ad
#define S_FUNCTION_LEVEL 2

#include <stdio.h>
#include  <stdlib.h>     /* malloc(), free(), strtoul() */
#include "simstruc.h"    /* the simstruct access macros */


/*=========================================================================*
 * Number of S-function Parameters and macros to access from the SimStruct *
 *=========================================================================*/
#define NUM_PARAMS                 (6)
#define BASE_ADDRESS_PARAM         (ssGetSFcnParam(S,0))
// let the user access only one channel per block
#define CHANNEL_TO_USE_PARAM       (ssGetSFcnParam(S,1)) 
#define HW_GAIN_PARAM              (ssGetSFcnParam(S,2))
#define ADC_RANGE                  (ssGetSFcnParam(S,3))
#define SAMPLE_TIME_PARAM          (ssGetSFcnParam(S,4))
#define ACCESS_HW_PARAM            (ssGetSFcnParam(S,5))

/*==================================================*
 * Macros to access the S-function parameter values *
 *==================================================*/
#define SAMPLE_TIME          ((real_T) mxGetPr(SAMPLE_TIME_PARAM)[0])
#define READ_CHANNEL         ((uint_T) mxGetPr(CHANNEL_TO_USE_PARAM)[0])
#define RANGE                ((real_T) mxGetPr(ADC_RANGE)[0])  
#define GAIN                 ((uint_T) mxGetPr(HW_GAIN_PARAM)[0])   


/*========================================================*
 * (Hardware Specific) Macros pertaining to the I/O board *
 *========================================================*/
#ifndef ACCESS_HW
# define ACCESS_HW                  (mxGetPr(ACCESS_HW_PARAM)[0] != 0.0)
#endif

#include "tmwtypes.h"
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
	//real_T    offset;
} ADCInfo;


/*====================*
 * S-function methods *
 *====================*/

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
        ADCInfo *adcInfo = ssGetUserData(S);
        char_T baseAddrStr[BASE_ADDR_PARAM_STRLEN];
        uint_T baseAddr;

        /* Initialize diInfo (pointer saved in the user data) */
        mxGetString(BASE_ADDRESS_PARAM, baseAddrStr, BASE_ADDR_PARAM_STRLEN);
        baseAddr = (uint_T) strtoul(baseAddrStr, NULL, 0);
		
        if (adcInfo != NULL) {
            free(adcInfo);
        }
        if ((adcInfo = malloc(sizeof(ADCInfo))) == NULL) {
            ssSetErrorStatus(S,"Memory Allocation Error\n");
            return;
        }
        adcInfo->baseAddr   = baseAddr;
        ssSetUserData(S, (void*) adcInfo);
  
		// do initialiazation here ...
		// initialize ADC channel nad set the proper gain 
		 pcl812_selectAdcChannel(baseAddr, READ_CHANNEL);
		 pcl812_setAdcGain(baseAddr, GAIN);
	 // printf("PCL812: Hardware Access Enabled\n");
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
	  ADCInfo            *adcInfo  = ssGetUserData(S);
	  InputRealPtrsType  uPtrs  = ssGetInputPortRealSignalPtrs(S,0);
	  uint_T             baseAddr = adcInfo->baseAddr;
	  real_T             adcCountsPerVolts;
      real_T             codeValue;
	  int_T              enough;

	  adcCountsPerVolts = (2048*GAIN) / RANGE ;
	  //start ADC conversion
	  pcl812_startAdcConversion(baseAddr);
	 
	  //wait until the ADC conversion is finished and read in the voltage
	  
	  enough = 0;
	  while ( (enough<10) || (!pcl812_isAdcConversionFinished(baseAddr)) )
	  {
		  // RTWT does not let you do this in a loop ???
	//	  codeValue = getVoltage(baseAddr, adcCountsPerVolts);
		  // so just do busy waiting 
		  enough ++;
	  }

	    codeValue = pcl812_getVoltage(baseAddr, adcCountsPerVolts);

	  y[0] = codeValue;
	  	  
	}
// else do nothing      
}



/* Function: mdlTerminate =====================================================
 *
 */
static void mdlTerminate(SimStruct *S)
{
   ADCInfo *adcInfo = ssGetUserData(S);
   free(adcInfo);
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
