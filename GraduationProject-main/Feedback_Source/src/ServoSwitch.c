/* $Date:  $
 * $Revision: 0.99 $
 * $Author: EZ $
 *
 * File: ServoDac.c
 *
 * Abstract:
 *      S-Function device driver 
 *      for the Feedback Servo Trainer SW5 (switch on board) via PCI1751
 *
 * Copyright (c) 
 */

#define S_FUNCTION_NAME	ServoSwitch
#define S_FUNCTION_LEVEL 2


#include <stdio.h>
#include  <stdlib.h>     /* malloc(), free(), strtoul() */
#include "simstruc.h"    /* the simstruct access macros */


/*=========================================================================*
 * Number of S-function Parameters and macros to access from the SimStruct *
 *=========================================================================*/
#define NUM_PARAMS                 (3)
#define SWITCH_CUTOFF              (ssGetSFcnParam(S,0))
#define SAMPLE_TIME_PARAM          (ssGetSFcnParam(S,1))
#define ACCESS_HW_PARAM            (ssGetSFcnParam(S,2))

/*==================================================*
 * Macros to access the S-function parameter values *
 *==================================================*/
#define CUTOFF				((real_T) mxGetPr(SWITCH_CUTOFF)[0])
#define SAMPLE_TIME         ((real_T) mxGetPr(SAMPLE_TIME_PARAM)[0])

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
	// One input port for the turn on/off comment
	// and one output port to indicate the position of the switch 
    ssSetNumInputPorts   ( S, 2);
	ssSetNumOutputPorts  ( S, 2); 
	ssSetInputPortWidth  ( S, 0, 1);
	ssSetInputPortWidth  ( S, 1, 1);
	
	ssSetOutputPortWidth ( S, 0, 1);
	ssSetOutputPortWidth ( S, 1, 1);

	 
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
  InputRealPtrsType  uPtrs1  = ssGetInputPortRealSignalPtrs(S,0);
  InputRealPtrsType  uPtrs2  = ssGetInputPortRealSignalPtrs(S,1);

  real_T *y1                 = ssGetOutputPortRealSignal(S,0);
  real_T *y2                 = ssGetOutputPortRealSignal(S,1);

  if (ACCESS_HW && (ssGetSimMode(S) != SS_SIMMODE_RTWGEN)) 
  {
	  real_T value1, value2;
	  int mode;
	  uint_T  baseAddr = ssGetIWorkValue(S,0);	 

	  value1 = (*uPtrs1[0]);
	  value2 = (*uPtrs2[0]);
	  
	  
	  if ((value1 >= CUTOFF) && (value2 >= CUTOFF) )
	  {	  mode = 3;
		  y1[0] = 1.0;
		  y2[0] = 1.0;
	  }
	  else if ((value1 < CUTOFF) && (value2 >= CUTOFF))  
	  { mode = 2;
	    y1[0] = 0.0;
		y2[0] = 1.0;
	  }
	  else if ((value1 >= CUTOFF) && (value2 < CUTOFF))
	  { mode = 1;
	    y1[0] = 1.0;
		y2[0] = 0.0;
	  }
	  else 
	  { mode = 0;
	    y1[0] = 0.0;
		y2[0] = 0.0;
	  }
 
	  servoTrainer_SwitchControl(baseAddr, mode);
	}
  
  }


/* Function: mdlTerminate =======================================================
 *
 */
static void mdlTerminate(SimStruct *S)
{
   int mode = 0;
   
  if (ACCESS_HW && (ssGetSimMode(S) != SS_SIMMODE_RTWGEN)) 
  {
	uint_T  baseAddr = ssGetIWorkValue(S,0);
	//servoTrainer_SwitchSW5(baseAddr, mode);
	servoTrainer_BcontrolMode(baseAddr, mode);

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
