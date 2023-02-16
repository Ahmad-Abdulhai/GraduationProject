/* $Date:  $
 * $Revision: 0.99 $
 * $Author: EZ $
 *
 * File: pci1711FedEnc.c
 *
 * Abstract:
 *      S-Function device driver for Feedback Encoder Readings using
 *      the PCI1711 pic I/O Board      
 *
 * Copyright (c) 
 */

#define S_FUNCTION_NAME	pci1711FedEnc
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
#define CHANNEL_TO_USE_PARAM       (ssGetSFcnParam(S,0)) 
#define ENC_OFFSET_VALUE           (ssGetSFcnParam(S,1))
#define SAMPLE_TIME_PARAM          (ssGetSFcnParam(S,2))
#define ACCESS_HW_PARAM            (ssGetSFcnParam(S,3))

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

		getPCI1711BaseAddress (&baseAddr);
 	    ssSetIWorkValue(S, 0, baseAddr);

			// do initialiazation here ...
		pci1711_resetEncoder(baseAddr);

                
		// do initialiazation here ...
       // printf("PCL812\: Hardware Access Enabled\n");
    } else if (ssGetSimMode(S) == SS_SIMMODE_NORMAL) {
        
		printf("PCI1711 : Hardware Access Disabled\n");
    }
}
#endif /* MDL_START */

/* Function: mdlOutputs =======================================================
 *
 */
static void mdlOutputs(SimStruct *S, int_T tid)
{
	real_T             *y = ssGetOutputPortRealSignal(S,0);

  if (ACCESS_HW && (ssGetSimMode(S) != SS_SIMMODE_RTWGEN)) 
  {
	  uint_T  baseAddr = ssGetIWorkValue(S,0);	 
	  int_T   count0=0, count1=0;
	  real_T  dummy;

	  // here is the Open source code.. 

	  //make sure count is not latched
	  pci1711_writeDigout(baseAddr, 0x07, 0);
	  //latch count read high bytes
	  pci1711_writeDigout(baseAddr, 0x04, 0);

	  count0 = inp(baseAddr+16);
	  count0 <<= 8;
 	  count1 = inp(baseAddr+17);
	  count1 <<= 8;
	  //read low bytes
	  pci1711_writeDigout(baseAddr, 0x06, 0);

	  // read from the low bytes
	  count0 += (char)inp(baseAddr+16);
	  count1 += (char)inp(baseAddr+17);
	  
	  // unlatch count
	  pci1711_writeDigout (baseAddr, 0x07, 0);

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
  else 
  {
	  y[0] = 0.0;
  }
  
}



/* Function: mdlTerminate =====================================================
 *
 */
static void mdlTerminate(SimStruct *S)
{
	// do nothing
}



/*=============================*
 * Required S-function trailer *
 *=============================*/
#ifdef MATLAB_MEX_FILE
#include "simulink.c"     
#else
#include "cg_sfun.h"
#endif

/* EOF: pci11711FedEnc.c */
