/* $Date:  $
 * $Revision: 0.99 $
 * $Author: EZ $
 *
 * File: SMicaDac.c
 *
 * Abstract:
 * S-Function device driver 
 *      for the Feedback Servo Trainer 
 *      Reads the contents of C Lower register
 * Copyright (c) 
 */

#define S_FUNCTION_NAME	SMicaPortAEnc
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
#define BASE_ADDRESS_PARAM         (ssGetSFcnParam(S,0))
#define SAMPLE_TIME_PARAM          (ssGetSFcnParam(S,1))
#define ACCESS_HW_PARAM            (ssGetSFcnParam(S,2))

/*==================================================*
 * Macros to access the S-function parameter values *
 *==================================================*/
#define SAMPLE_TIME          ((real_T) mxGetPr(SAMPLE_TIME_PARAM)[0])

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
	// One input port for the turn on/off comment
	// and one output port to indicate the position of the switch 
    ssSetNumInputPorts   ( S, 1);
	ssSetNumOutputPorts  ( S, 8); 
	
	ssSetInputPortWidth ( S, 0, 1); // for reset information

	ssSetOutputPortWidth ( S, 0, 1);
	ssSetOutputPortWidth ( S, 1, 1);
	ssSetOutputPortWidth ( S, 2, 1);
	ssSetOutputPortWidth ( S, 3, 1);
	ssSetOutputPortWidth ( S, 4, 1);
	ssSetOutputPortWidth ( S, 5, 1);
	ssSetOutputPortWidth ( S, 6, 1);
	ssSetOutputPortWidth ( S, 7, 1);
	 
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
  real_T *bit0    = ssGetOutputPortRealSignal(S,0);
  real_T *bit1    = ssGetOutputPortRealSignal(S,1);
  real_T *bit2    = ssGetOutputPortRealSignal(S,2);
  real_T *bit3    = ssGetOutputPortRealSignal(S,3);
  real_T *bit4    = ssGetOutputPortRealSignal(S,4);
  real_T *bit5    = ssGetOutputPortRealSignal(S,5);
  real_T *bit6    = ssGetOutputPortRealSignal(S,6);
  real_T *bit7    = ssGetOutputPortRealSignal(S,7);

  InputRealPtrsType  uPtrs  = ssGetInputPortRealSignalPtrs(S,0);

  int reset;
  uint_T inputFromPort;

  if (ACCESS_HW && (ssGetSimMode (S) != SS_SIMMODE_RTWGEN)) 
  {
	  AddressInfo  *Info  = ssGetUserData(S);
	  uint_T   baseAddr = Info->baseAddr;
	  
	  if ((*uPtrs[0]) >=1) reset = 1;
	  else reset =0;

	  inputFromPort = Mica_readPortAPositionReadMode(baseAddr, reset);

	  bit0[0] = (real_T)( inputFromPort&0x01) ;
	  bit1[0] = (real_T)( (inputFromPort&0x02) >> 1 ) ;
	  bit2[0] = (real_T)( (inputFromPort&0x04) >> 2 ) ;
	  bit3[0] = (real_T)( (inputFromPort&0x08) >> 3 ) ;	  
	  bit4[0] = (real_T)( (inputFromPort&0x10) >> 4  );
	  bit5[0] = (real_T)( (inputFromPort&0x20) >> 5 ) ;
	  bit6[0] = (real_T)( (inputFromPort&0x40) >> 6 ) ;
	  bit7[0] = (real_T)( (inputFromPort&0x80) >> 7 ) ;	  
		
	  
	  
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
