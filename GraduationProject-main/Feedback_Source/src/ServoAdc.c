/* $Date:  $
 * $Revision: 0.99 $
 * $Author: EZ $
 *
 * File: ServoAdc.c
 *
 * Abstract:
 *      S-Function device driver 
 *      for the Feedback Servo Trainer DAC using PCI1751
 *
 * Copyright (c) 
 */

#define S_FUNCTION_NAME	ServoAdc
#define S_FUNCTION_LEVEL 2


#include <stdio.h>
#include  <stdlib.h>     /* malloc(), free(), strtoul() */
#include "simstruc.h"    /* the simstruct access macros */


/*=========================================================================*
 * Number of S-function Parameters and macros to access from the SimStruct *
 *=========================================================================*/
#define NUM_PARAMS                 (3)
// The user can write either the high or low byte of the 
// digital input word
#define MODE_PARAM                 (ssGetSFcnParam(S,0))
#define SAMPLE_TIME_PARAM          (ssGetSFcnParam(S,1))
#define ACCESS_HW_PARAM            (ssGetSFcnParam(S,2))

/*==================================================*
 * Macros to access the S-function parameter values *
 *==================================================*/
#define SAMPLE_TIME          ((real_T) mxGetPr(SAMPLE_TIME_PARAM)[0])
#define MODE		         ((uint_T) mxGetPr(MODE_PARAM)[0])

/*========================================================*
 * (Hardware Specific) Macros pertaining to the I/O board *
 *========================================================*/
#ifndef ACCESS_HW
# define ACCESS_HW                  (mxGetPr(ACCESS_HW_PARAM)[0] != 0.0)
#endif

#include "tmwtypes.h"
#include "pciheader.h"
#include "pci1751def.h"
#include "ServoTheader.h"


#define PORT_STRLEN     (128)

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
	//baseAddress information 
	ssSetNumIWork        ( S, 1);

    ssSetNumSampleTimes  ( S, 1);
    ssSetNumInputPorts   ( S, 0);
	ssSetNumOutputPorts  ( S, 1); 
	ssSetOutputPortWidth  ( S, 0, 1);
	 
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

		getPCI1751BaseAddress (&baseAddr);
 	    ssSetIWorkValue(S, 0, baseAddr);

		servoTrainer_SetIOConfig (baseAddr);

    } else if (ssGetSimMode(S) == SS_SIMMODE_NORMAL) {
        
		printf("PCI1751 : Hardware Access Disabled\n");
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
	  real_T	value;
	  int       mode;//,i;
	  uint_T	RawData, finish;
	  real_T hiVolt, loVolt;
	  int enough;
//	  uint_T inC, outD;

	  uint_T  baseAddr = ssGetIWorkValue(S,0);	 


	  hiVolt = 11.0;
	  loVolt = -11.0;
	
	
	// set the input channel (A) to read ADC
	servoTrainer_setInputChannelADC(baseAddr);
	
	// start AD conversion 
	servoTrainer_startADConversion(baseAddr);
	enough = 0;

	// first make sure that the conversion has ended
	do {
	   finish = servoTrainer_isAdcConversionFinished(baseAddr);
	   enough ++;
	} while ( (!finish)||(enough < 10) );

	// now in this step make sure conversion ended bit goes back to 
	// its normal stage ... computer is too fast for the trainer :)
	outp (baseAddr+2, 0x00);
	enough = 0;
   do {
	   finish = servoTrainer_isAdcConversionFinished(baseAddr);
	   enough ++;
	} while ( (finish)||(enough < 10) );

	// 
    RawData = servoTrainer_getAdcValue(baseAddr);


    value = (real_T)(RawData)-127 ;
	 
	  if (MODE==2) 
	  {
		  mode = 1;
		  y[0] =  (value/256)*(hiVolt-loVolt);
	  }
	  else
	  {
		  mode = 0;
		  y[0] = value;
	  }
 	  
	}
  
}


/* Function: mdlTerminate =======================================================
 *
 */
static void mdlTerminate(SimStruct *S)
{
  if (ACCESS_HW && (ssGetSimMode(S) != SS_SIMMODE_RTWGEN) ) 
  {
	uint_T  baseAddr = ssGetIWorkValue(S,0);
   // pci1751_resetPorts(baseAddr,0);
  }

}



/*=============================*
 * Required S-function trailer *
 *=============================*/
#ifdef MATLAB_MEX_FILE
#include "simulink.c"     
#else
#include "cg_sfun.h"
#endif

/* EOF: pci11711DigOut.c */
