/* $Date:  $
 * $Revision: 0.99 $
 * $Author: EZ $
 *
 * File: pci1711DigOut.c
 *
 * Abstract:
 *      S-Function device driver for Digital Output of PCL812 I/O Board      
 *
 * Copyright (c) 
 */

#define S_FUNCTION_NAME	pci1711DigOut
#define S_FUNCTION_LEVEL 2

#include  <stdlib.h>     /* malloc(), free(), strtoul() */
#include "simstruc.h"    /* the simstruct access macros */


/*=========================================================================*
 * Number of S-function Parameters and macros to access from the SimStruct *
 *=========================================================================*/
#define NUM_PARAMS                 (3)
// The user can write either the high or low byte of the 
// digital out word
#define BYTE_TO_USE_PARAM          (ssGetSFcnParam(S,0)) 
#define SAMPLE_TIME_PARAM          (ssGetSFcnParam(S,1))
#define ACCESS_HW_PARAM            (ssGetSFcnParam(S,2))

/*==================================================*
 * Macros to access the S-function parameter values *
 *==================================================*/
#define SAMPLE_TIME          ((real_T) mxGetPr(SAMPLE_TIME_PARAM)[0])
// can select either high or low byte of the digital out word
#define OUT_BYTE             ((uint_T)  mxGetPr(BYTE_TO_USE_PARAM)[0])


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
    ssSetNumInputPorts   ( S, 1);
	ssSetInputPortWidth  ( S, 0, 1);
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
         uint_T baseAddr;
		 
		 getPCI1711BaseAddress (&baseAddr);
 	     ssSetIWorkValue(S, 0, baseAddr);
                
        
		// do initialiazation here ...
        
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
  if (ACCESS_HW && (ssGetSimMode(S) != SS_SIMMODE_RTWGEN)) 
  {
	  InputRealPtrsType  uPtrs  = ssGetInputPortRealSignalPtrs(S,0);
	  uint_T  baseAddr = ssGetIWorkValue(S,0);
     
	  real_T	value;
	  uint_T    digitalOutValue;
	  
	  // get the value to output from the input port
	  value = (*uPtrs[0]) ;
	  digitalOutValue = (uint_T) value;

	  pci1711_writeDigout(baseAddr, digitalOutValue, OUT_BYTE);
	  	  
	}
// else do nothing      
}



/* Function: mdlTerminate =====================================================
 *
 */
static void mdlTerminate(SimStruct *S)
{
   uint_T   outvalue = 0;
   
	
	if (ACCESS_HW && (ssGetSimMode(S) != SS_SIMMODE_RTWGEN)) 
	{
		uint_T  baseAddr = ssGetIWorkValue(S,0);
		pci1711_writeDigout(baseAddr, outvalue, OUT_BYTE);
		   
		printf("PCI1711: Selected Digital Output is setted to 0 \n");  
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

/* EOF: pci1711DigOut.c */
