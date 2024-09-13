/*
 * Real-Time Workshop code generation for Simulink model "CranePID.mdl".
 *
 * Model Version                        : 1.60
 * Real-Time Workshop file version      : 5.0 $Date: 2002/05/30 19:21:33 $
 * Real-Time Workshop file generated on : Wed Apr 01 15:07:26 2009
 * TLC version                          : 5.0 (Jun 18 2002)
 * C source code generated on           : Wed Apr 01 15:07:26 2009
 */

#include <math.h>
#include <string.h>
#include "CranePID.h"
#include "CranePID_private.h"
#include "ext_work.h"

#include "CranePID_dt.h"
#include "simstruc.h"

/* Block signals (auto storage) */
BlockIO rtB;

/* Continuous states */
ContinuousStates rtX;

/* Block states (auto storage) */
D_Work rtDWork;

/* Parent Simstruct */
static SimStruct model_S;
SimStruct *const rtS = &model_S;

/* Initial conditions for root system: '<Root>' */
void MdlInitialize(void)
{

  /* TransferFcn Block: <S4>/Integral */
  rtX.Integral_a_CSTATE = 0.0;

  /* TransferFcn Block: <S4>/Cart Velocity  Filter1 */
  rtX.Cart_Velocity_Filter1_CSTATE[0] = 0.0;
  rtX.Cart_Velocity_Filter1_CSTATE[1] = 0.0;

  /* TransferFcn Block: <S5>/Integral */
  rtX.Integral_b_CSTATE = 0.0;

  /* TransferFcn Block: <S5>/Pendulum Velocity  Filter */
  rtX.Pendulum_Velocity_Filter_CSTATE[0] = 0.0;
  rtX.Pendulum_Velocity_Filter_CSTATE[1] = 0.0;

  /* TransferFcn Block: <S1>/Cart Velocity  Filter */
  rtX.Cart_Velocity_Filter_CSTATE[0] = 0.0;
  rtX.Cart_Velocity_Filter_CSTATE[1] = 0.0;

  /* Derivative Block: <S1>/Cart Velocity */
  rtDWork.Cart_Velocity_RWORK.TimeStampA = rtInf;
  rtDWork.Cart_Velocity_RWORK.TimeStampB = rtInf;

  /* Derivative Block: <S4>/Derivative */
  rtDWork.Derivative_a_RWORK.TimeStampA = rtInf;
  rtDWork.Derivative_a_RWORK.TimeStampB = rtInf;

  /* Derivative Block: <S5>/Derivative */
  rtDWork.Derivative_b_RWORK.TimeStampA = rtInf;
  rtDWork.Derivative_b_RWORK.TimeStampB = rtInf;
}

/* Start for root system: '<Root>' */
void MdlStart(void)
{

  /* Level2 S-Function Block: <Root>/Digital To Analog Converter  (pci1711FedDac) */
  {
    SimStruct *rts = ssGetSFunction(rtS, 0);
    sfcnStart(rts);
  }

  /* Level2 S-Function Block: <Root>/Read Cart Encoder (pci1711FedEnc) */
  {
    SimStruct *rts = ssGetSFunction(rtS, 1);
    sfcnStart(rts);
  }

  /* Level2 S-Function Block: <Root>/Read Pendulum Encoder (pci1711FedEnc) */
  {
    SimStruct *rts = ssGetSFunction(rtS, 2);
    sfcnStart(rts);
  }

  MdlInitialize();
}

/* Outputs for root system: '<Root>' */
void MdlOutputs(int_T tid)
{
  /* local block i/o variables */
  real_T rtb_Integral_a;
  real_T rtb_Cart_Velocity_Filter1;
  real_T rtb_Integral_b;
  real_T rtb_Pendulum_Velocity_Filter;
  real_T rtb_Sign2;
  real_T rtb_id;
  real_T rtb_temp27;

  if (ssIsSampleHit(rtS, 1, tid)) {     /* Sample time: [0.001, 0.0] */

    /* Level2 S-Function Block: <Root>/Digital To Analog Converter  (pci1711FedDac) */
    {
      SimStruct *rts = ssGetSFunction(rtS, 0);
      sfcnOutputs(rts, tid);
    }
  }

  if (ssIsContinuousTask(rtS, tid)) {   /* Sample time: [0.0, 0.0] */

    /* Sin: '<Root>/Desired Position Input' */

    rtB.Desired_Position = rtP.Desired_Position_Input_Amp *
      sin(rtP.Desired_Position_Input_Freq * ssGetTaskTime(rtS,tid) +
      rtP.Desired_Position_Input_Phase) + rtP.Desired_Position_Input_Bias;
  }

  if (ssIsSampleHit(rtS, 1, tid)) {     /* Sample time: [0.001, 0.0] */

    /* Level2 S-Function Block: <Root>/Read Cart Encoder (pci1711FedEnc) */
    {
      SimStruct *rts = ssGetSFunction(rtS, 1);
      sfcnOutputs(rts, tid);
    }

    /* Gain: '<Root>/Counts->Meters'
     *
     * Regarding '<Root>/Counts->Meters':
     *   Gain value: rtP.Counts_Meters_Gain
     */
    rtB.actual_CartPosition = rtB.Read_Cart_Encoder * rtP.Counts_Meters_Gain;
  }

  if (ssIsContinuousTask(rtS, tid)) {   /* Sample time: [0.0, 0.0] */

    /* Sum: '<S1>/Sum2' */
    rtB.Sum2 = rtB.Desired_Position - rtB.actual_CartPosition;

    /* TransferFcn Block: <S4>/Integral */
    rtb_Integral_a = rtP.Integral_a_C*rtX.Integral_a_CSTATE;

    /* TransferFcn Block: <S4>/Cart Velocity  Filter1 */
    rtb_Cart_Velocity_Filter1 =
      rtP.Cart_Velocity_Filter1_C[0]*rtX.Cart_Velocity_Filter1_CSTATE[0]
      + rtP.Cart_Velocity_Filter1_C[1]*rtX.Cart_Velocity_Filter1_CSTATE[1];
  }

  if (ssIsSampleHit(rtS, 1, tid)) {     /* Sample time: [0.001, 0.0] */

    /* Level2 S-Function Block: <Root>/Read Pendulum Encoder (pci1711FedEnc) */
    {
      SimStruct *rts = ssGetSFunction(rtS, 2);
      sfcnOutputs(rts, tid);
    }

    /* Sum: '<S1>/Sum3' incorporates:
     *   Gain: '<Root>/Counts->Radians'
     *   Constant: '<S1>/s7'
     *
     * Regarding '<Root>/Counts->Radians':
     *   Gain value: rtP.Counts_Radians_Gain
     */
    rtB.Sum3 = - (rtB.Read_Pendulum_Encoder * rtP.Counts_Radians_Gain)
      + rtP.s7_Value;

    /* Gain: '<S5>/Proportional'
     *
     * Regarding '<S5>/Proportional':
     *   Gain value: rtP.Proportional_b_Gain
     */
    rtB.Proportional_b = rtB.Sum3 * rtP.Proportional_b_Gain;
  }

  if (ssIsContinuousTask(rtS, tid)) {   /* Sample time: [0.0, 0.0] */

    /* TransferFcn Block: <S5>/Integral */
    rtb_Integral_b = rtP.Integral_b_C*rtX.Integral_b_CSTATE;

    /* TransferFcn Block: <S5>/Pendulum Velocity  Filter */
    rtb_Pendulum_Velocity_Filter =
      rtP.Pendulum_Velocity_Filter_C[0]*rtX.Pendulum_Velocity_Filter_CSTATE[0]
      + rtP.Pendulum_Velocity_Filter_C[1]*rtX.Pendulum_Velocity_Filter_CSTATE[1];

    /* TransferFcn Block: <S1>/Cart Velocity  Filter */
    rtb_temp27 = rtP.Cart_Velocity_Filter_C[0]*rtX.Cart_Velocity_Filter_CSTATE[0]
      + rtP.Cart_Velocity_Filter_C[1]*rtX.Cart_Velocity_Filter_CSTATE[1];

    /* Signum: '<S3>/Sign2' */
    rtb_Sign2 = rt_SGN(rtb_temp27);
  }

  if (ssIsContinuousTask(rtS, tid)) {   /* Sample time: [0.0, 0.0] */

    /* Switch: '<S3>/3' */
    if (rtb_Sign2 >= rtP.id_Threshold) {

      /* Gain: '<S3>/Gain2'
       *
       * Regarding '<S3>/Gain2':
       *   Gain value: rtP.Gain2_Gain
       */
      rtB.Gain2 = rtb_Sign2 * rtP.Gain2_Gain;

      rtb_id = rtB.Gain2;
    } else {

      /* Gain: '<S3>/Gain3'
       *
       * Regarding '<S3>/Gain3':
       *   Gain value: rtP.Gain3_Gain
       */
      rtB.Gain3 = rtb_Sign2 * rtP.Gain3_Gain;

      rtb_id = rtB.Gain3;
    }

    /* Gain: '<S2>/Gain' incorporates:
     *   Sum: '<S1>/Sum5'
     *   Sum: '<S4>/Sum'
     *   Gain: '<S4>/Proportional'
     *   Sum: '<S5>/Sum'
     *
     * Regarding '<S2>/Gain':
     *   Gain value: rtP.Gain_Gain
     *
     * Regarding '<S4>/Proportional':
     *   Gain value: rtP.Proportional_a_Gain
     */
    rtb_temp27 = (((rtB.Sum2 * rtP.Proportional_a_Gain) + rtb_Integral_a +
      rtb_Cart_Velocity_Filter1) + (rtB.Proportional_b + rtb_Integral_b +
      rtb_Pendulum_Velocity_Filter) + rtb_id) * rtP.Gain_Gain;

    /* Saturate: '<S2>/Saturation'
     *
     * Regarding '<S2>/Saturation':
     *   Lower limit: rtP.Saturation_LowerSat
     *   Upper limit: rtP.Saturation_UpperSat
     */
    if (rtb_temp27 >= rtP.Saturation_UpperSat) {
      rtB.Saturation = rtP.Saturation_UpperSat;
    } else if (rtb_temp27 <= rtP.Saturation_LowerSat) {
      rtB.Saturation = rtP.Saturation_LowerSat;
    } else {
      rtB.Saturation = rtb_temp27;
    }
  }

  if (ssIsSampleHit(rtS, 1, tid)) {     /* Sample time: [0.001, 0.0] */

    /* Gain: '<S1>/Plot Scaling'
     *
     * Regarding '<S1>/Plot Scaling':
     *   Gain value: rtP.Plot_Scaling_Gain
     */
    rtB.Pendulum_Angle_Deviation_from_E = rtB.Sum3 * rtP.Plot_Scaling_Gain;
  }

  if (ssIsContinuousTask(rtS, tid)) {   /* Sample time: [0.0, 0.0] */

    /* Derivative Block: <S1>/Cart Velocity */
    {
      real_T t = ssGetTaskTime(rtS,tid);
      real_T timeStampA = rtDWork.Cart_Velocity_RWORK.TimeStampA;
      real_T timeStampB = rtDWork.Cart_Velocity_RWORK.TimeStampB;

      if (timeStampA >= t && timeStampB >= t) {
        rtB.derPendPos = 0.0;
      } else {
        real_T deltaT;
        real_T *lastBank = &rtDWork.Cart_Velocity_RWORK.TimeStampA;
        if (timeStampA < timeStampB) {
          if (timeStampB < t) {
            lastBank += 2;
          }
        } else if (timeStampA >= t) {
          lastBank += 2;
        }
        deltaT = t - *lastBank++;
        rtB.derPendPos = (rtB.actual_CartPosition - *lastBank++) / deltaT;
      }
    }

    /* Gain: '<S4>/D'
     *
     * Regarding '<S4>/D':
     *   Gain value: rtP.D_a_Gain
     */
    rtB.D_a = rtB.Sum2 * rtP.D_a_Gain;

    /* Derivative Block: <S4>/Derivative */
    {
      real_T t = ssGetTaskTime(rtS,tid);
      real_T timeStampA = rtDWork.Derivative_a_RWORK.TimeStampA;
      real_T timeStampB = rtDWork.Derivative_a_RWORK.TimeStampB;

      if (timeStampA >= t && timeStampB >= t) {
        rtB.Derivative_a = 0.0;
      } else {
        real_T deltaT;
        real_T *lastBank = &rtDWork.Derivative_a_RWORK.TimeStampA;
        if (timeStampA < timeStampB) {
          if (timeStampB < t) {
            lastBank += 2;
          }
        } else if (timeStampA >= t) {
          lastBank += 2;
        }
        deltaT = t - *lastBank++;
        rtB.Derivative_a = (rtB.D_a - *lastBank++) / deltaT;
      }
    }
  }

  if (ssIsSampleHit(rtS, 1, tid)) {     /* Sample time: [0.001, 0.0] */

    /* Gain: '<S5>/D'
     *
     * Regarding '<S5>/D':
     *   Gain value: rtP.D_b_Gain
     */
    rtB.D_b = rtB.Sum3 * rtP.D_b_Gain;
  }

  if (ssIsContinuousTask(rtS, tid)) {   /* Sample time: [0.0, 0.0] */

    /* Derivative Block: <S5>/Derivative */
    {
      real_T t = ssGetTaskTime(rtS,tid);
      real_T timeStampA = rtDWork.Derivative_b_RWORK.TimeStampA;
      real_T timeStampB = rtDWork.Derivative_b_RWORK.TimeStampB;

      if (timeStampA >= t && timeStampB >= t) {
        rtB.Derivative_b = 0.0;
      } else {
        real_T deltaT;
        real_T *lastBank = &rtDWork.Derivative_b_RWORK.TimeStampA;
        if (timeStampA < timeStampB) {
          if (timeStampB < t) {
            lastBank += 2;
          }
        } else if (timeStampA >= t) {
          lastBank += 2;
        }
        deltaT = t - *lastBank++;
        rtB.Derivative_b = (rtB.D_b - *lastBank++) / deltaT;
      }
    }
  }
}

/* Update for root system: '<Root>' */
void MdlUpdate(int_T tid)
{

  if (ssIsContinuousTask(rtS, tid)) {   /* Sample time: [0.0, 0.0] */

    /* Derivative Block: <S1>/Cart Velocity */
    {
      real_T timeStampA = rtDWork.Cart_Velocity_RWORK.TimeStampA;
      real_T timeStampB = rtDWork.Cart_Velocity_RWORK.TimeStampB;
      real_T *lastBank = &rtDWork.Cart_Velocity_RWORK.TimeStampA;

      if (timeStampA != rtInf) {
        if (timeStampB == rtInf) {
          lastBank += 2;
        } else if (timeStampA >= timeStampB) {
          lastBank += 2;
        }
      }
      *lastBank++ = ssGetTaskTime(rtS,tid);
      *lastBank++ = rtB.actual_CartPosition;
    }

    /* Derivative Block: <S4>/Derivative */
    {
      real_T timeStampA = rtDWork.Derivative_a_RWORK.TimeStampA;
      real_T timeStampB = rtDWork.Derivative_a_RWORK.TimeStampB;
      real_T *lastBank = &rtDWork.Derivative_a_RWORK.TimeStampA;

      if (timeStampA != rtInf) {
        if (timeStampB == rtInf) {
          lastBank += 2;
        } else if (timeStampA >= timeStampB) {
          lastBank += 2;
        }
      }
      *lastBank++ = ssGetTaskTime(rtS,tid);
      *lastBank++ = rtB.D_a;
    }

    /* Derivative Block: <S5>/Derivative */
    {
      real_T timeStampA = rtDWork.Derivative_b_RWORK.TimeStampA;
      real_T timeStampB = rtDWork.Derivative_b_RWORK.TimeStampB;
      real_T *lastBank = &rtDWork.Derivative_b_RWORK.TimeStampA;

      if (timeStampA != rtInf) {
        if (timeStampB == rtInf) {
          lastBank += 2;
        } else if (timeStampA >= timeStampB) {
          lastBank += 2;
        }
      }
      *lastBank++ = ssGetTaskTime(rtS,tid);
      *lastBank++ = rtB.D_b;
    }
  }
}

/* Derivatives for root system: '<Root>' */
void MdlDerivatives(void)
{
  /* simstruct variables */
  StateDerivatives *rtXdot = (StateDerivatives*) ssGetdX(rtS);

  /* TransferFcn Block: <S4>/Integral */
  {

    rtXdot->Integral_a_CSTATE = rtB.Sum2;
    rtXdot->Integral_a_CSTATE += (rtP.Integral_a_A)*rtX.Integral_a_CSTATE;
  }

  /* TransferFcn Block: <S4>/Cart Velocity  Filter1 */
  {

    rtXdot->Cart_Velocity_Filter1_CSTATE[0] = rtB.Derivative_a;
    rtXdot->Cart_Velocity_Filter1_CSTATE[0] +=
      (rtP.Cart_Velocity_Filter1_A[0])*rtX.Cart_Velocity_Filter1_CSTATE[0]
      + (rtP.Cart_Velocity_Filter1_A[1])*rtX.Cart_Velocity_Filter1_CSTATE[1];
    rtXdot->Cart_Velocity_Filter1_CSTATE[1] =
      rtX.Cart_Velocity_Filter1_CSTATE[0];
  }

  /* TransferFcn Block: <S5>/Integral */
  {

    rtXdot->Integral_b_CSTATE = rtB.Sum3;
    rtXdot->Integral_b_CSTATE += (rtP.Integral_b_A)*rtX.Integral_b_CSTATE;
  }

  /* TransferFcn Block: <S5>/Pendulum Velocity  Filter */
  {

    rtXdot->Pendulum_Velocity_Filter_CSTATE[0] = rtB.Derivative_b;
    rtXdot->Pendulum_Velocity_Filter_CSTATE[0] +=
      (rtP.Pendulum_Velocity_Filter_A[0])*rtX.Pendulum_Velocity_Filter_CSTATE[0]
      +
      (rtP.Pendulum_Velocity_Filter_A[1])*rtX.Pendulum_Velocity_Filter_CSTATE[1];
    rtXdot->Pendulum_Velocity_Filter_CSTATE[1] =
      rtX.Pendulum_Velocity_Filter_CSTATE[0];
  }

  /* TransferFcn Block: <S1>/Cart Velocity  Filter */
  {

    rtXdot->Cart_Velocity_Filter_CSTATE[0] = rtB.derPendPos;
    rtXdot->Cart_Velocity_Filter_CSTATE[0] +=
      (rtP.Cart_Velocity_Filter_A[0])*rtX.Cart_Velocity_Filter_CSTATE[0]
      + (rtP.Cart_Velocity_Filter_A[1])*rtX.Cart_Velocity_Filter_CSTATE[1];
    rtXdot->Cart_Velocity_Filter_CSTATE[1] = rtX.Cart_Velocity_Filter_CSTATE[0];
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

    /* Level2 S-Function Block: <Root>/Digital To Analog Converter  (pci1711FedDac) */
    {
      SimStruct *rts = ssGetSFunction(rtS, 0);
      sfcnTerminate(rts);
    }

    /* Level2 S-Function Block: <Root>/Read Cart Encoder (pci1711FedEnc) */
    {
      SimStruct *rts = ssGetSFunction(rtS, 1);
      sfcnTerminate(rts);
    }

    /* Level2 S-Function Block: <Root>/Read Pendulum Encoder (pci1711FedEnc) */
    {
      SimStruct *rts = ssGetSFunction(rtS, 2);
      sfcnTerminate(rts);
    }
  }
}

/* Helper function to make function calls from non-inlined S-functions */
int_T rt_CallSys(SimStruct *S, int_T element, int_T tid)
{
  (*(S)->callSys.fcns[element])((S)->callSys.args1[element],
   (S)->callSys.args2[element], tid);

  if (ssGetErrorStatus(S) != NULL) {
    return 0;
  } else {
    return 1;
  }
}

/* Function to initialize sizes */
void MdlInitializeSizes(void)
{
  ssSetNumContStates(rtS, 8);           /* Number of continuous states */
  ssSetNumY(rtS, 0);                    /* Number of model outputs */
  ssSetNumU(rtS, 0);                    /* Number of model inputs */
  ssSetDirectFeedThrough(rtS, 0);       /* The model is not direct feedthrough */
  ssSetNumSampleTimes(rtS, 4);          /* Number of sample times */
  ssSetNumBlocks(rtS, 35);              /* Number of blocks */
  ssSetNumBlockIO(rtS, 16);             /* Number of block outputs */
  ssSetNumBlockParams(rtS, 70);         /* Sum of parameter "widths" */
}

/* Function to initialize sample times */
void MdlInitializeSampleTimes(void)
{
  /* task periods */
  ssSetSampleTime(rtS, 0, 0.0);
  ssSetSampleTime(rtS, 1, 0.001);
  ssSetSampleTime(rtS, 2, 0.01);
  ssSetSampleTime(rtS, 3, 0.1);

  /* task offsets */
  ssSetOffsetTime(rtS, 0, 0.0);
  ssSetOffsetTime(rtS, 1, 0.0);
  ssSetOffsetTime(rtS, 2, 0.0);
  ssSetOffsetTime(rtS, 3, 0.0);
}

/* Function to register the model */
SimStruct *CranePID(void)
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
    (void)memset((char_T *)&mdlTsMap[0], 0, 4 * sizeof(int_T));
    (void)memset((char_T *)&mdlSampleHits[0], 0, 4 * sizeof(int_T));

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

      b = &rtB.Desired_Position;
      for (i = 0; i < 14; i++) {
        ((real_T*)b)[i] = 0.0;
      }
      b =&rtB.Gain3;
      for (i = 0; i < 2; i++) {
        ((real_T*)b)[i] = 0.0;
      }
    }
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
    {
      int_T i;
      real_T *dwork_ptr = (real_T *) &rtDWork.Cart_Velocity_RWORK.TimeStampA;

      for (i = 0; i < 12; i++) {
        dwork_ptr[i] = 0.0;
      }
    }
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
  ssSetModelName(rtS, "CranePID");
  ssSetPath(rtS, "CranePID");

  ssSetTStart(rtS, 0.0);
  ssSetTFinal(rtS, 50.0);
  ssSetStepSize(rtS, 0.001);
  ssSetFixedStepSize(rtS, 0.001);

  ssSetChecksumVal(rtS, 0, 2290999061U);
  ssSetChecksumVal(rtS, 1, 744840901U);
  ssSetChecksumVal(rtS, 2, 952558526U);
  ssSetChecksumVal(rtS, 3, 2458867920U);

  {
    static const EnableStates rtAlwaysEnabled = SUBSYS_ENABLED;

    static RTWExtModeInfo rt_ExtModeInfo;
    static const void *sysModes[3];

    ssSetRTWExtModeInfo(rtS, &rt_ExtModeInfo);
    rteiSetSubSystemModeVectorAddresses(&rt_ExtModeInfo, sysModes);

    sysModes[0] = &rtAlwaysEnabled;
    sysModes[1] = &rtAlwaysEnabled;
    sysModes[2] = &rtAlwaysEnabled;

    rteiSetModelMappingInfoPtr(&rt_ExtModeInfo, &ssGetModelMappingInfo(rtS));

    rteiSetChecksumsPtr(&rt_ExtModeInfo, ssGetChecksums(rtS));

    rteiSetTPtr(&rt_ExtModeInfo, ssGetTPtr(rtS));
  }

  /* child S-Function registration */

  ssSetNumSFunctions(rtS, 3);

  /* register each child */
  {
    static SimStruct childSFunctions[3];
    static SimStruct *childSFunctionPtrs[3];

    (void)memset((char_T *)&childSFunctions[0], 0, sizeof(childSFunctions));
    ssSetSFunctions(rtS, &childSFunctionPtrs[0]);
    {
      int_T i;

      for(i = 0; i < 3; i++) {
        ssSetSFunction(rtS, i, &childSFunctions[i]);
      }
    }

    /* Level2 S-Function Block: CranePID/<Root>/Digital To Analog Converter  (pci1711FedDac) */
    {
      SimStruct *rts = ssGetSFunction(rtS, 0);
      /* timing info */
      static time_T sfcnPeriod[1];
      static time_T sfcnOffset[1];
      static int_T sfcnTsMap[1];

      {
        int_T i;

        for(i = 0; i < 1; i++) {
          sfcnPeriod[i] = sfcnOffset[i] = 0.0;
        }
      }
      ssSetSampleTimePtr(rts, &sfcnPeriod[0]);
      ssSetOffsetTimePtr(rts, &sfcnOffset[0]);
      ssSetSampleTimeTaskIDPtr(rts, sfcnTsMap);

      /* Set up the mdlInfo pointer */
      ssSetMdlInfoPtr(rts, ssGetMdlInfoPtr(rtS));
      /* Allocate memory of model methods 2 */
      {
        static struct _ssSFcnModelMethods2 methods2;
        ssSetModelMethods2(rts, &methods2);
      }

      /* inputs */
      {
        static struct _ssPortInputs inputPortInfo[1];

        _ssSetNumInputPorts(rts, 1);
        ssSetPortInfoForInputs(rts, &inputPortInfo[0]);

        /* port 0 */
        {

          static real_T const *sfcnUPtrs[1];
          sfcnUPtrs[0] = &rtB.Saturation;
          ssSetInputPortSignalPtrs(rts, 0, (InputPtrsType)&sfcnUPtrs[0]);
          _ssSetInputPortNumDimensions(rts, 0, 1);
          ssSetInputPortWidth(rts, 0, 1);
        }
      }

      /* path info */
      ssSetModelName(rts, "Digital To Analog\nConverter\n");
      ssSetPath(rts, "CranePID/Digital To Analog Converter ");
      if (ssGetRTModel(rtS) == NULL) {
        ssSetParentSS(rts, rtS);
        ssSetRootSS(rts, ssGetRootSS(rtS));
      } else {
        ssSetRTModel(rts,ssGetRTModel(rtS));
        ssSetParentSS(rts, NULL);
        ssSetRootSS(rts, rts);
      }
      ssSetVersion(rts, SIMSTRUCT_VERSION_LEVEL2);

      /* parameters */
      {
        static mxArray *sfcnParams[4];

        ssSetSFcnParamsCount(rts, 4);
        ssSetSFcnParamsPtr(rts, &sfcnParams[0]);

        ssSetSFcnParam(rts, 0, &rtP.Digital_To_Analog_Convert_P1_Si[0]);
        ssSetSFcnParam(rts, 1, &rtP.Digital_To_Analog_Convert_P2_Si[0]);
        ssSetSFcnParam(rts, 2, &rtP.Digital_To_Analog_Convert_P3_Si[0]);
        ssSetSFcnParam(rts, 3, &rtP.Digital_To_Analog_Convert_P4_Si[0]);
      }

      /* work vectors */
      ssSetIWork(rts, (int_T *) &rtDWork.Digital_To_Analog_Convert_IWORK);
      {
        static struct _ssDWorkRecord dWorkRecord[1];

        ssSetSFcnDWork(rts, dWorkRecord);
        _ssSetNumDWork(rts, 1);

        /* IWORK */
        ssSetDWorkWidth(rts, 0, 1);
        ssSetDWorkDataType(rts, 0,SS_INTEGER);
        ssSetDWorkComplexSignal(rts, 0, 0);
        ssSetDWork(rts, 0, &rtDWork.Digital_To_Analog_Convert_IWORK);
      }

      /* registration */
      pci1711FedDac(rts);

      sfcnInitializeSizes(rts);
      sfcnInitializeSampleTimes(rts);

      /* adjust sample time */
      ssSetSampleTime(rts, 0, 0.001);
      ssSetOffsetTime(rts, 0, 0.0);
      sfcnTsMap[0] = 1;

      /* set compiled values of dynamic vector attributes */

      ssSetNumNonsampledZCs(rts, 0);
      /* Update connectivity flags for each port */
      _ssSetInputPortConnected(rts, 0, 1);
      /* Update the BufferDstPort flags for each input port */
      ssSetInputPortBufferDstPort(rts, 0, -1);
    }

    /* Level2 S-Function Block: CranePID/<Root>/Read Cart Encoder (pci1711FedEnc) */
    {
      SimStruct *rts = ssGetSFunction(rtS, 1);
      /* timing info */
      static time_T sfcnPeriod[1];
      static time_T sfcnOffset[1];
      static int_T sfcnTsMap[1];

      {
        int_T i;

        for(i = 0; i < 1; i++) {
          sfcnPeriod[i] = sfcnOffset[i] = 0.0;
        }
      }
      ssSetSampleTimePtr(rts, &sfcnPeriod[0]);
      ssSetOffsetTimePtr(rts, &sfcnOffset[0]);
      ssSetSampleTimeTaskIDPtr(rts, sfcnTsMap);

      /* Set up the mdlInfo pointer */
      ssSetMdlInfoPtr(rts, ssGetMdlInfoPtr(rtS));
      /* Allocate memory of model methods 2 */
      {
        static struct _ssSFcnModelMethods2 methods2;
        ssSetModelMethods2(rts, &methods2);
      }

      /* outputs */
      {
        static struct _ssPortOutputs outputPortInfo[1];
        _ssSetNumOutputPorts(rts, 1);
        ssSetPortInfoForOutputs(rts, &outputPortInfo[0]);
        /* port 0 */
        {
          _ssSetOutputPortNumDimensions(rts, 0, 1);
          ssSetOutputPortWidth(rts, 0, 1);
          ssSetOutputPortSignal(rts, 0, ((real_T *) &rtB.Read_Cart_Encoder));
        }
      }
      /* path info */
      ssSetModelName(rts, "Read Cart Encoder");
      ssSetPath(rts, "CranePID/Read Cart Encoder");
      if (ssGetRTModel(rtS) == NULL) {
        ssSetParentSS(rts, rtS);
        ssSetRootSS(rts, ssGetRootSS(rtS));
      } else {
        ssSetRTModel(rts,ssGetRTModel(rtS));
        ssSetParentSS(rts, NULL);
        ssSetRootSS(rts, rts);
      }
      ssSetVersion(rts, SIMSTRUCT_VERSION_LEVEL2);

      /* parameters */
      {
        static mxArray *sfcnParams[4];

        ssSetSFcnParamsCount(rts, 4);
        ssSetSFcnParamsPtr(rts, &sfcnParams[0]);

        ssSetSFcnParam(rts, 0, &rtP.Read_Cart_Encoder_P1_Size[0]);
        ssSetSFcnParam(rts, 1, &rtP.Read_Cart_Encoder_P2_Size[0]);
        ssSetSFcnParam(rts, 2, &rtP.Read_Cart_Encoder_P3_Size[0]);
        ssSetSFcnParam(rts, 3, &rtP.Read_Cart_Encoder_P4_Size[0]);
      }

      /* work vectors */
      ssSetIWork(rts, (int_T *) &rtDWork.Read_Cart_Encoder_IWORK);
      {
        static struct _ssDWorkRecord dWorkRecord[1];

        ssSetSFcnDWork(rts, dWorkRecord);
        _ssSetNumDWork(rts, 1);

        /* IWORK */
        ssSetDWorkWidth(rts, 0, 1);
        ssSetDWorkDataType(rts, 0,SS_INTEGER);
        ssSetDWorkComplexSignal(rts, 0, 0);
        ssSetDWork(rts, 0, &rtDWork.Read_Cart_Encoder_IWORK);
      }

      /* registration */
      pci1711FedEnc(rts);

      sfcnInitializeSizes(rts);
      sfcnInitializeSampleTimes(rts);

      /* adjust sample time */
      ssSetSampleTime(rts, 0, 0.001);
      ssSetOffsetTime(rts, 0, 0.0);
      sfcnTsMap[0] = 1;

      /* set compiled values of dynamic vector attributes */

      ssSetNumNonsampledZCs(rts, 0);
      /* Update connectivity flags for each port */
      _ssSetOutputPortConnected(rts, 0, 1);
      _ssSetOutputPortBeingMerged(rts, 0, 0);
      /* Update the BufferDstPort flags for each input port */
    }

    /* Level2 S-Function Block: CranePID/<Root>/Read Pendulum Encoder (pci1711FedEnc) */
    {
      SimStruct *rts = ssGetSFunction(rtS, 2);
      /* timing info */
      static time_T sfcnPeriod[1];
      static time_T sfcnOffset[1];
      static int_T sfcnTsMap[1];

      {
        int_T i;

        for(i = 0; i < 1; i++) {
          sfcnPeriod[i] = sfcnOffset[i] = 0.0;
        }
      }
      ssSetSampleTimePtr(rts, &sfcnPeriod[0]);
      ssSetOffsetTimePtr(rts, &sfcnOffset[0]);
      ssSetSampleTimeTaskIDPtr(rts, sfcnTsMap);

      /* Set up the mdlInfo pointer */
      ssSetMdlInfoPtr(rts, ssGetMdlInfoPtr(rtS));
      /* Allocate memory of model methods 2 */
      {
        static struct _ssSFcnModelMethods2 methods2;
        ssSetModelMethods2(rts, &methods2);
      }

      /* outputs */
      {
        static struct _ssPortOutputs outputPortInfo[1];
        _ssSetNumOutputPorts(rts, 1);
        ssSetPortInfoForOutputs(rts, &outputPortInfo[0]);
        /* port 0 */
        {
          _ssSetOutputPortNumDimensions(rts, 0, 1);
          ssSetOutputPortWidth(rts, 0, 1);
          ssSetOutputPortSignal(rts, 0, ((real_T *) &rtB.Read_Pendulum_Encoder));
        }
      }
      /* path info */
      ssSetModelName(rts, "Read Pendulum Encoder");
      ssSetPath(rts, "CranePID/Read Pendulum Encoder");
      if (ssGetRTModel(rtS) == NULL) {
        ssSetParentSS(rts, rtS);
        ssSetRootSS(rts, ssGetRootSS(rtS));
      } else {
        ssSetRTModel(rts,ssGetRTModel(rtS));
        ssSetParentSS(rts, NULL);
        ssSetRootSS(rts, rts);
      }
      ssSetVersion(rts, SIMSTRUCT_VERSION_LEVEL2);

      /* parameters */
      {
        static mxArray *sfcnParams[4];

        ssSetSFcnParamsCount(rts, 4);
        ssSetSFcnParamsPtr(rts, &sfcnParams[0]);

        ssSetSFcnParam(rts, 0, &rtP.Read_Pendulum_Encoder_P1_Size[0]);
        ssSetSFcnParam(rts, 1, &rtP.Read_Pendulum_Encoder_P2_Size[0]);
        ssSetSFcnParam(rts, 2, &rtP.Read_Pendulum_Encoder_P3_Size[0]);
        ssSetSFcnParam(rts, 3, &rtP.Read_Pendulum_Encoder_P4_Size[0]);
      }

      /* work vectors */
      ssSetIWork(rts, (int_T *) &rtDWork.Read_Pendulum_Encoder_IWORK);
      {
        static struct _ssDWorkRecord dWorkRecord[1];

        ssSetSFcnDWork(rts, dWorkRecord);
        _ssSetNumDWork(rts, 1);

        /* IWORK */
        ssSetDWorkWidth(rts, 0, 1);
        ssSetDWorkDataType(rts, 0,SS_INTEGER);
        ssSetDWorkComplexSignal(rts, 0, 0);
        ssSetDWork(rts, 0, &rtDWork.Read_Pendulum_Encoder_IWORK);
      }

      /* registration */
      pci1711FedEnc(rts);

      sfcnInitializeSizes(rts);
      sfcnInitializeSampleTimes(rts);

      /* adjust sample time */
      ssSetSampleTime(rts, 0, 0.001);
      ssSetOffsetTime(rts, 0, 0.0);
      sfcnTsMap[0] = 1;

      /* set compiled values of dynamic vector attributes */

      ssSetNumNonsampledZCs(rts, 0);
      /* Update connectivity flags for each port */
      _ssSetOutputPortConnected(rts, 0, 1);
      _ssSetOutputPortBeingMerged(rts, 0, 0);
      /* Update the BufferDstPort flags for each input port */
    }
  }

  return rtS;
}

