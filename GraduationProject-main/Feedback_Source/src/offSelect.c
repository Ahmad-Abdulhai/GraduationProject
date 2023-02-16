/*
 * File : onSelect.c
 * Abstract:
 *      changes the state of the signal when selected
 *      else the state of the signal remains same as previous input
 *
 * Copyright E.Z. 
 * $Revision: 1.0 $
 */

#define S_FUNCTION_NAME  offSelect
#define S_FUNCTION_LEVEL 2

#include <stdio.h>
#include <math.h>
#include  <stdlib.h>     /* malloc(), free(), strtoul() */
#include "simstruc.h"

/*==================================================*
 * Macros to access the S-function parameter values *
 *==================================================*/


// global scope
//  real_T      offSelectpreviousOutput; 

/* Function: mdlInitializeSizes ===============================================
 * Abstract:
 *   Setup sizes of the various vectors.
 */
static void mdlInitializeSizes(SimStruct *S)
{

	ssSetNumSFcnParams(S, 0);
	if (ssGetNumSFcnParams(S) != ssGetSFcnParamsCount(S)) {
        return; /* Parameter mismatch will be reported by Simulink */
    }

    ssSetNumInputPorts   ( S, 2);
	ssSetNumOutputPorts  ( S, 1); 
	
	ssSetInputPortWidth  ( S, 0, 1);
	ssSetInputPortWidth  ( S, 1, 1);
	ssSetOutputPortWidth ( S, 0, 1);
}


/* Function: mdlInitializeSampleTimes =========================================
 * Abstract:
 *    Specifiy that we inherit our sample time from the driving block.
 */
static void mdlInitializeSampleTimes(SimStruct *S)
{
    ssSetSampleTime(S, 0, INHERITED_SAMPLE_TIME);
    ssSetOffsetTime(S, 0, 0.0);
}

#define MDL_START  /* Change to #undef to remove function */
#if defined(MDL_START)
/* Function: mdlStart =========================================================
 *
 */
static void mdlStart(SimStruct *S)
{
	// initialiaze previous input
	//offSelectpreviousOutput = 0.0;
}
#endif /* MDL_START */


/* Function: mdlOutputs =======================================================
 * Abstract:
 *  
 */
static void mdlOutputs(SimStruct *S, int_T tid)
{
	static   real_T      offSelectpreviousOutput=0.0;
	
	InputRealPtrsType trigger2      = ssGetInputPortRealSignalPtrs(S,0);
	InputRealPtrsType inputValue2   = ssGetInputPortRealSignalPtrs(S,1);

    real_T            *offSelectValue    = ssGetOutputPortRealSignal(S,0);

	if (*trigger2[0]==0)
	{
	offSelectValue[0] = *inputValue2[0];
	offSelectpreviousOutput = offSelectValue[0];
	}
	else
	offSelectValue[0] = offSelectpreviousOutput;
    
}


static void mdlTerminate(SimStruct *S)
{

}

/*=============================*
 * Required S-function trailer *
 *=============================*/
#ifdef MATLAB_MEX_FILE
#include "simulink.c"     
#else
#include "cg_sfun.h"
#endif

/* EOF: onSelect.c */
