/*
 * Real-Time Workshop code generation for Simulink model "rtvdp.mdl".
 *
 * Model Version                        : 1.9
 * Real-Time Workshop file version      : 5.0 $Date: 2002/05/30 19:21:33 $
 * Real-Time Workshop file generated on : Sat Mar 14 23:10:17 2009
 * TLC version                          : 5.0 (Jun 18 2002)
 * C source code generated on           : Sat Mar 14 23:10:17 2009
 */

#include <math.h>
#include <string.h>
#include "rtvdp.h"
#include "rtvdp_private.h"
#include "ext_work.h"

#include "rtvdp_dt.h"
#include "simstruc.h"

/* Block signals (auto storage) */
BlockIO rtB;

/* Continuous states */
ContinuousStates rtX;

/* Block states (auto storage) */
D_Work rtDWork;

/* External output (root outports fed by signals with auto storage) */
ExternalOutputs rtY;

/* Parent Simstruct */
static SimStruct model_S;
SimStruct *const rtS = &model_S;

/* Initial conditions for root system: '<Root>' */
void MdlInitialize(void)
{

  /* Integrator Block: <Root>/Integrator1 */
  rtX.Integrator1_CSTATE = rtP.Integrator1_IC;

  /* Integrator Block: <Root>/Integrator2 */
  rtX.Integrator2_CSTATE = rtP.Integrator2_IC;
}

/* Start for root system: '<Root>' */
void MdlStart(void)
{

  /* Integrator Block: <Root>/Integrator1 */
  (void)memcpy(&rtB.x1, &rtP.Integrator1_IC, 1 * sizeof(real_T));

  /* Integrator Block: <Root>/Integrator2 */
  (void)memcpy(&rtB.x2, &rtP.Integrator2_IC, 1 * sizeof(real_T));

  MdlInitialize();
}

/* Outputs for root system: '<Root>' */
void MdlOutputs(int_T tid)
{

  if (ssIsContinuousTask(rtS, tid)) {   /* Sample time: [0.0, 0.0] */

    /* Integrator: '<Root>/Integrator1' */
    rtB.x1 = rtX.Integrator1_CSTATE;

    /* Outport: '<Root>/Out1' */
    rtY.Out1 = rtB.x1;

    /* Integrator: '<Root>/Integrator2' */
    rtB.x2 = rtX.Integrator2_CSTATE;

    /* Outport: '<Root>/Out2' */
    rtY.Out2 = rtB.x2;

    /* Saturate: '<Root>/Saturation'
     *
     * Regarding '<Root>/Saturation':
     *   Lower limit: rtP.Saturation_LowerSat
     *   Upper limit: rtP.Saturation_UpperSat
     */
    if (rtB.x1 >= rtP.Saturation_UpperSat) {
      rtB.Saturation[0] = rtP.Saturation_UpperSat;
    } else if (rtB.x1 <= rtP.Saturation_LowerSat) {
      rtB.Saturation[0] = rtP.Saturation_LowerSat;
    } else {
      rtB.Saturation[0] = rtB.x1;
    }
    if (rtB.x2 >= rtP.Saturation_UpperSat) {
      rtB.Saturation[1] = rtP.Saturation_UpperSat;
    } else if (rtB.x2 <= rtP.Saturation_LowerSat) {
      rtB.Saturation[1] = rtP.Saturation_LowerSat;
    } else {
      rtB.Saturation[1] = rtB.x2;
    }

    /* Sum: '<Root>/Sum' incorporates:
     *   Gain: '<Root>/Mu'
     *   Product: '<Root>/Product'
     *   Fcn: '<Root>/Fcn'
     *
     * Regarding '<Root>/Mu':
     *   Gain value: rtP.Mu_Gain
     *
     * Regarding '<Root>/Fcn':
     *   Expression: 1 - u*u
     */
    rtB.Sum = - rtB.x1 + (((1.0 - rtB.x1 * rtB.x1 ) * rtB.x2) * rtP.Mu_Gain);
  }
}

/* Update for root system: '<Root>' */
void MdlUpdate(int_T tid)
{
}

/* Derivatives for root system: '<Root>' */
void MdlDerivatives(void)
{
  /* simstruct variables */
  StateDerivatives *rtXdot = (StateDerivatives*) ssGetdX(rtS);

  /* Integrator Block: <Root>/Integrator1 */
  {

    rtXdot->Integrator1_CSTATE = rtB.x2;
  }

  /* Integrator Block: <Root>/Integrator2 */
  {

    rtXdot->Integrator2_CSTATE = rtB.Sum;
  }
}

/* Projection for root system: '<Root>' */
void MdlProjection(void)
{
}

/* Terminate for root system: '<Root>' */
void MdlTerminate(void)
{
  if(rtS != NULL) {
  }
}

/* Function to initialize sizes */
void MdlInitializeSizes(void)
{
  ssSetNumContStates(rtS, 2);           /* Number of continuous states */
  ssSetNumY(rtS, 2);                    /* Number of model outputs */
  ssSetNumU(rtS, 0);                    /* Number of model inputs */
  ssSetDirectFeedThrough(rtS, 0);       /* The model is not direct feedthrough */
  ssSetNumSampleTimes(rtS, 2);          /* Number of sample times */
  ssSetNumBlocks(rtS, 10);              /* Number of blocks */
  ssSetNumBlockIO(rtS, 4);              /* Number of block outputs */
  ssSetNumBlockParams(rtS, 5);          /* Sum of parameter "widths" */
}

/* Function to initialize sample times */
void MdlInitializeSampleTimes(void)
{
  /* task periods */
  ssSetSampleTime(rtS, 0, 0.0);
  ssSetSampleTime(rtS, 1, 0.01);

  /* task offsets */
  ssSetOffsetTime(rtS, 0, 0.0);
  ssSetOffsetTime(rtS, 1, 0.0);
}

/* Function to register the model */
SimStruct *rtvdp(void)
{
  static struct _ssMdlInfo mdlInfo;
  (void)memset((char *)rtS, 0, sizeof(SimStruct));
  (void)memset((char *)&mdlInfo, 0, sizeof(struct _ssMdlInfo));
  ssSetMdlInfoPtr(rtS, &mdlInfo);

  /* timing info */
  {
    static time_T mdlPeriod[NSAMPLE_TIMES];
    static time_T mdlOffset[NSAMPLE_TIMES];
    static time_T mdlTaskTimes[NSAMPLE_TIMES];
    static int_T mdlTsMap[NSAMPLE_TIMES];
    static int_T mdlSampleHits[NSAMPLE_TIMES];

    {
      int_T i;

      for(i = 0; i < NSAMPLE_TIMES; i++) {
        mdlPeriod[i] = 0.0;
        mdlOffset[i] = 0.0;
        mdlTaskTimes[i] = 0.0;
      }
    }
    (void)memset((char_T *)&mdlTsMap[0], 0, 2 * sizeof(int_T));
    (void)memset((char_T *)&mdlSampleHits[0], 0, 2 * sizeof(int_T));

    ssSetSampleTimePtr(rtS, &mdlPeriod[0]);
    ssSetOffsetTimePtr(rtS, &mdlOffset[0]);
    ssSetSampleTimeTaskIDPtr(rtS, &mdlTsMap[0]);
    ssSetTPtr(rtS, &mdlTaskTimes[0]);
    ssSetSampleHitPtr(rtS, &mdlSampleHits[0]);
  }
  ssSetSolverMode(rtS, SOLVER_MODE_SINGLETASKING);

  /*
   * initialize model vectors and cache them in SimStruct
   */

  /* block I/O */
  {
    void *b = (void *) &rtB;
    ssSetBlockIO(rtS, b);

    {
      int_T i;

      b =&rtB.x1;
      for (i = 0; i < 5; i++) {
        ((real_T*)b)[i] = 0.0;
      }
    }
  }

  /* external outputs */
  {
    ssSetY(rtS, &rtY);

    rtY.Out1 = 0.0;
    rtY.Out2 = 0.0;
  }

  /* parameters */
  ssSetDefaultParam(rtS, (real_T *) &rtP);

  /* states */
  {
    int_T i;
    real_T *x = (real_T *) &rtX;
    ssSetContStates(rtS, x);
    for(i = 0; i < (int_T)(sizeof(ContinuousStates)/sizeof(real_T)); i++) {
      x[i] = 0.0;
    }
  }

  /* data type work */
  {
    void *dwork = (void *) &rtDWork;
    ssSetRootDWork(rtS, dwork);
    (void)memset((char_T *) dwork, 0, sizeof(D_Work));
  }

  /* data type transition information (for external mode) */
  {
    static DataTypeTransInfo dtInfo;

    (void)memset((char_T *) &dtInfo, 0, sizeof(dtInfo));
    ssSetModelMappingInfo(rtS, &dtInfo);

    dtInfo.numDataTypes = 13;
    dtInfo.dataTypeSizes = &rtDataTypeSizes[0];
    dtInfo.dataTypeNames = &rtDataTypeNames[0];

    /* Block I/O transition table */
    dtInfo.B = &rtBTransTable;

    /* Parameters transition table */
    dtInfo.P = &rtPTransTable;
  }

  /* Model specific registration */
  ssSetRootSS(rtS, rtS);

  ssSetVersion(rtS, SIMSTRUCT_VERSION_LEVEL2);
  ssSetModelName(rtS, "rtvdp");
  ssSetPath(rtS, "rtvdp");

  ssSetTStart(rtS, 0.0);
  ssSetTFinal(rtS, 999999.0);
  ssSetStepSize(rtS, 0.01);
  ssSetFixedStepSize(rtS, 0.01);

  ssSetChecksumVal(rtS, 0, 1356030225U);
  ssSetChecksumVal(rtS, 1, 55607504U);
  ssSetChecksumVal(rtS, 2, 1788078737U);
  ssSetChecksumVal(rtS, 3, 4222244455U);

  {
    static const EnableStates rtAlwaysEnabled = SUBSYS_ENABLED;

    static RTWExtModeInfo rt_ExtModeInfo;
    static const void *sysModes[1];

    ssSetRTWExtModeInfo(rtS, &rt_ExtModeInfo);
    rteiSetSubSystemModeVectorAddresses(&rt_ExtModeInfo, sysModes);

    sysModes[0] = &rtAlwaysEnabled;

    rteiSetModelMappingInfoPtr(&rt_ExtModeInfo, &ssGetModelMappingInfo(rtS));

    rteiSetChecksumsPtr(&rt_ExtModeInfo, ssGetChecksums(rtS));

    rteiSetTPtr(&rt_ExtModeInfo, ssGetTPtr(rtS));
  }

  return rtS;
}

