/* $Date:  $
 * $Revision: 0.99 $
 * $Author: EZ $
 *
 * File: plc812ad.c
 *
 * Abstract:
 *      S-Function device driver for ADC of PCI1711 I/O Board      
 *
 * Copyright (c) 
 */

#define S_FUNCTION_NAME	pci1711ad
#define S_FUNCTION_LEVEL 2

#include <stdio.h>
#include  <stdlib.h>     /* malloc(), free(), strtoul() */
#include "simstruc.h"    /* the simstruct access macros */


/*=========================================================================*
 * Number of S-function Parameters and macros to access from the SimStruct *
 *=========================================================================*/
#define NUM_PARAMS                 (4)
#define CHANNEL_TO_USE_PARAM       (ssGetSFcnParam(S,0)) 
#define ADC_RANGE                  (ssGetSFcnParam(S,1))
#define SAMPLE_TIME_PARAM          (ssGetSFcnParam(S,2))
#define ACCESS_HW_PARAM            (ssGetSFcnParam(S,3))

/*==================================================*
 * Macros to access the S-function parameter values *
 *==================================================*/
#define SAMPLE_TIME          ((real_T) mxGetPr(SAMPLE_TIME_PARAM)[0])
#define READ_CHANNEL         ((uint_T) mxGetPr(CHANNEL_TO_USE_PARAM)[0])
#define RANGE_GAIN           ((uint_T) mxGetPr(ADC_RANGE)[0])  


/*========================================================*
 * (Hardware Specific) Macros pertaining to the I/O board *
 *========================================================*/
#ifndef ACCESS_HW
# define ACCESS_HW           (mxGetPr(ACCESS_HW_PARAM)[0] != 0.0)
#endif

#include "tmwtypes.h"
#include "pciheader.h"
#include "pci1711def.h"


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
          return;       
       }
    } else {
       return;
    }

    /* None of this s-functions's parameters are tunable during simulation */
    {
        int_T i;
        for (i=0; i < NUM_PARAMS; i++) {
            ssSetSFcnParamNotTunable(S, i);
        }
    }

	//baseAddress information 
	ssSetNumIWork        ( S, 1);

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
        
		uint_T baseAddr;

	    getPCI1711BaseAddress (&baseAddr);
 	    ssSetIWorkValue(S, 0, baseAddr);

		// do initialiazation here ...
		// select channel
        pci1711_selectAdcChannel(baseAddr, READ_CHANNEL);
		
		//select range gain
		 pci1711_setAdcGain(baseAddr, RANGE_GAIN);
	 
    } else if (ssGetSimMode(S) == SS_SIMMODE_NORMAL) {
        printf("PCI1711: Hardware Access Disabled\n");
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
	  InputRealPtrsType  uPtrs  = ssGetInputPortRealSignalPtrs(S,0);
	  uint_T  baseAddr = ssGetIWorkValue(S,0);

	  int                enough;
	  unsigned char      ucStatus;


  	  //start ADC conversion
	  pci1711_startAdcConversion(baseAddr);
	  
	  enough = 0;
	 do { 
		  ucStatus = pci1711_isAdcConversionFinished(baseAddr);
		  enough++;
		  }while (enough<10 || (ucStatus==1));

	 y[0] = pci1711_getVoltage(baseAddr, RANGE_GAIN);
  }
// else do nothing      
}


/* Function: mdlTerminate =====================================================
 *
 */
static void mdlTerminate(SimStruct *S)
{
// do nothink   
}

/*=============================*
 * Required S-function trailer *
 *=============================*/
#ifdef MATLAB_MEX_FILE
#include "simulink.c"     
#else
#include "cg_sfun.h"
#endif

/* EOF: pci1711ad.c */
