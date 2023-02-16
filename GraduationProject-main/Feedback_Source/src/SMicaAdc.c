/* $Date:  $
 * $Revision: 0.99 $
 * $Author: EZ $
 *
 * File: SMicaDac.c
 *
 * Abstract:
 *     S-Function device driver 
 *     for the Feedback Servo Trainer ADC using Mica926 
 *
 * Copyright (c) 
 */

#define S_FUNCTION_NAME	SMicaAdc
#define S_FUNCTION_LEVEL 2


#include <stdio.h>
#include  <stdlib.h>     /* malloc(), free(), strtoul() */
#include "simstruc.h"    /* the simstruct access macros */


/*=========================================================================*
 * Number of S-function Parameters and macros to access from the SimStruct *
 *=========================================================================*/
#define NUM_PARAMS                 (4)

// The user can write either the high or low byte of the 
// digital input word
#define BASE_ADDRESS_PARAM         (ssGetSFcnParam(S,0))
#define MODE_PARAM                 (ssGetSFcnParam(S,1))
#define SAMPLE_TIME_PARAM          (ssGetSFcnParam(S,2))
#define ACCESS_HW_PARAM            (ssGetSFcnParam(S,3))

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
#include "MicaHeader.h"


#define PORT_STRLEN     (128)

/*======================*
 * S-function User Data *
 *======================*/
typedef struct {
    uint_T    baseAddr;
} AddressInfo;


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
    if (ACCESS_HW && (ssGetSimMode (S) != SS_SIMMODE_RTWGEN)) {

       AddressInfo *Info = ssGetUserData(S);
       char_T baseAddrStr[PORT_STRLEN];
       uint_T baseAddr;
	   //printf("BaseAddress %d: \n",baseAddr);

        /* Initialize diInfo (pointer saved in the user data) */
        mxGetString(BASE_ADDRESS_PARAM, baseAddrStr, PORT_STRLEN);
        baseAddr = (uint_T) strtoul(baseAddrStr, NULL, 0);
		
        if (Info != NULL) {
            free(Info);
        }
        if ((Info = malloc(sizeof(AddressInfo))) == NULL) {
            ssSetErrorStatus(S,"Memory Allocation Error\n");
            return;
        }
        Info->baseAddr   = baseAddr;
		
        ssSetUserData(S, (void*) Info);

	
		Mica_SetIOConfig (baseAddr);


    } else if (ssGetSimMode(S) == SS_SIMMODE_NORMAL) {
        
		printf("Hardware Access Disabled\n");
    }
}
#endif /* MDL_START */

/* Function: mdlOutputs =======================================================
 *
 */
static void mdlOutputs(SimStruct *S, int_T tid)
{
    real_T *y = ssGetOutputPortRealSignal(S,0);

  if (ACCESS_HW && (ssGetSimMode (S) != SS_SIMMODE_RTWGEN)) 
  {
	  AddressInfo  *Info  = ssGetUserData(S);
	  uint_T   baseAddr = Info->baseAddr;
	  real_T	value;
	  int       mode;
	  uint_T	RawData, finish;
	  real_T hiVolt, loVolt;
	  int enough;
	  

	  hiVolt = 11.0;
	  loVolt = -11.0;
	
	
	// set the input channel (A) to read ADC
	Mica_setInputChannelADC(baseAddr);
	
	// start AD conversion 
	Mica_startADConversion(baseAddr);
	enough = 0;

	// first make sure that the conversion has ended
	do {
	   finish = Mica_isAdcConversionFinished(baseAddr);
	   enough ++;
	} while ( (!finish)||(enough < 10) );

	// now in this step make sure conversion ended bit goes back to 
	// its normal stage ... computer is too fast for the trainer :)
	outp (baseAddr+2, 0x00);
	enough = 0;
   do {
	   finish = Mica_isAdcConversionFinished(baseAddr);
	   enough ++;
	} while ( (finish)||(enough < 10) );

	// 
    RawData = Mica_getAdcValue(baseAddr);


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
   real_T   outValue = 0; //-127;
   int mode = 0;
   
  if (ACCESS_HW && (ssGetSimMode (S) != SS_SIMMODE_RTWGEN) ) 
  {
	AddressInfo  *Info  = ssGetUserData(S);
	uint_T   baseAddr = Info->baseAddr;
 
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
