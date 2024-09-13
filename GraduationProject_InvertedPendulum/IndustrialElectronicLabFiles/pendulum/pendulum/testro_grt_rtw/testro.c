/*
 * Real-Time Workshop code generation for Simulink model "testro.mdl".
 *
 * Model Version                        : 1.1
 * Real-Time Workshop file version      : 5.0 $Date: 2002/05/30 19:21:33 $
 * Real-Time Workshop file generated on : Mon Mar 23 11:39:34 2009
 * TLC version                          : 5.0 (Jun 18 2002)
 * C source code generated on           : Mon Mar 23 11:39:34 2009
 */

#include <math.h>
#include <string.h>
#include "testro.h"
#include "testro_private.h"

/* Block signals (auto storage) */
BlockIO rtB;

/* Continuous states */
ContinuousStates rtX;

/* Block states (auto storage) */
D_Work rtDWork;

/* Parent Simstruct */
static rtModel_testro model_S;
rtModel_testro *const rtM_testro = &model_S;

/* Initial conditions for root system: '<Root>' */
void MdlInitialize(void)
{

  /* TransferFcn Block: <S3>/Integral */
  rtX.Integral_a_CSTATE = 0.0;

  /* Derivative Block: <S3>/Derivative */
  rtDWork.Derivative_a_RWORK.TimeStampA = rtInf;
  rtDWork.Derivative_a_RWORK.TimeStampB = rtInf;

  /* TransferFcn Block: <S2>/Integral */
  rtX.Integral_b_CSTATE = 0.0;

  /* Derivative Block: <S2>/Derivative */
  rtDWork.Derivative_b_RWORK.TimeStampA = rtInf;
  rtDWork.Derivative_b_RWORK.TimeStampB = rtInf;
}

/* Start for root system: '<Root>' */
void MdlStart(void)
{

  /* Level2 S-Function Block: <S1>/Read Cart Encoder1 (pci1711FedEnc) */
  {
    SimStruct *rts = rtM_testro->childSfunctions[0];
    sfcnStart(rts);
  }

  /* Level2 S-Function Block: <S1>/Read Pendulum Encoder (pci1711FedEnc) */
  {
    SimStruct *rts = rtM_testro->childSfunctions[1];
    sfcnStart(rts);
  }

  /* Level2 S-Function Block: <S1>/Digital To Analog Converter (pci1711FedDac) */
  {
    SimStruct *rts = rtM_testro->childSfunctions[2];
    sfcnStart(rts);
  }

  MdlInitialize();
}

/* Outputs for root system: '<Root>' */
void MdlOutputs(int_T tid)
{
  /* local block i/o variables */
  real_T rtb_Step;
  real_T rtb_Integral_a;
  real_T rtb_Derivative_a;
  real_T rtb_Integral_b;
  real_T rtb_Derivative_b;
  real_T rtb_actual_LoadPosition;

  if (rtmIsSampleHit(rtM_testro, 1, tid)) { /* Sample time: [0.001, 0.0] */

    /* Level2 S-Function Block: <S1>/Read Cart Encoder1 (pci1711FedEnc) */
    {
      SimStruct *rts = rtM_testro->childSfunctions[0];
      sfcnOutputs(rts, tid);
    }

    /* Gain: '<S1>/Counts->Meters'
     *
     * Regarding '<S1>/Counts->Meters':
     *   Gain value: rtP.Counts_Meters_Gain
     */
    rtB.Cart_Position = rtB.Read_Cart_Encoder1 * rtP.Counts_Meters_Gain;

    /* Level2 S-Function Block: <S1>/Read Pendulum Encoder (pci1711FedEnc) */
    {
      SimStruct *rts = rtM_testro->childSfunctions[1];
      sfcnOutputs(rts, tid);
    }

    /* Gain: '<S1>/Counts->Radians'
     *
     * Regarding '<S1>/Counts->Radians':
     *   Gain value: rtP.Counts_Radians_Gain
     */
    rtB.Pendulum_Position = rtB.Read_Pendulum_Encoder * rtP.Counts_Radians_Gain;
  }

  if (rtmIsContinuousTask(rtM_testro, tid)) { /* Sample time: [0.0, 0.0] */

    /* Step: '<Root>/Step' */
    if (rtmGetTaskTime(rtM_testro, tid) < rtP.Step_Time) {
      rtb_Step = rtP.Step_Y0;
    } else {
      rtb_Step = rtP.Step_YFinal;
    }
  }

  if (rtmIsSampleHit(rtM_testro, 1, tid)) { /* Sample time: [0.001, 0.0] */

    /* Sum: '<Root>/Sum4' incorporates:
     *   Constant: '<Root>/Constant'
     */
    rtB.Sum4 = - rtB.Pendulum_Position + rtP.Constant_Value;

    /* Gain: '<S3>/Proportional'
     *
     * Regarding '<S3>/Proportional':
     *   Gain value: rtP.Proportional_a_Gain
     */
    rtB.Proportional_a = rtB.Sum4 * rtP.Proportional_a_Gain;
  }

  if (rtmIsContinuousTask(rtM_testro, tid)) { /* Sample time: [0.0, 0.0] */

    /* TransferFcn Block: <S3>/Integral */
    rtb_Integral_a = rtP.Integral_a_C*rtX.Integral_a_CSTATE;
  }

  if (rtmIsSampleHit(rtM_testro, 1, tid)) { /* Sample time: [0.001, 0.0] */

    /* Gain: '<S3>/D'
     *
     * Regarding '<S3>/D':
     *   Gain value: rtP.D_a_Gain
     */
    rtB.D_a = rtB.Sum4 * rtP.D_a_Gain;
  }

  if (rtmIsContinuousTask(rtM_testro, tid)) { /* Sample time: [0.0, 0.0] */

    /* Derivative Block: <S3>/Derivative */
    {
      real_T t = rtmGetTaskTime(rtM_testro, tid);
      real_T timeStampA = rtDWork.Derivative_a_RWORK.TimeStampA;
      real_T timeStampB = rtDWork.Derivative_a_RWORK.TimeStampB;

      if (timeStampA >= t && timeStampB >= t) {
        rtb_Derivative_a = 0.0;
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
        rtb_Derivative_a = (rtB.D_a - *lastBank++) / deltaT;
      }
    }
  }

  if (rtmIsSampleHit(rtM_testro, 1, tid)) { /* Sample time: [0.001, 0.0] */

    /* Gain: '<S2>/Proportional'
     *
     * Regarding '<S2>/Proportional':
     *   Gain value: rtP.Proportional_b_Gain
     */
    rtB.Proportional_b = rtB.Cart_Position * rtP.Proportional_b_Gain;
  }

  if (rtmIsContinuousTask(rtM_testro, tid)) { /* Sample time: [0.0, 0.0] */

    /* TransferFcn Block: <S2>/Integral */
    rtb_Integral_b = rtP.Integral_b_C*rtX.Integral_b_CSTATE;
  }

  if (rtmIsSampleHit(rtM_testro, 1, tid)) { /* Sample time: [0.001, 0.0] */

    /* Gain: '<S2>/D'
     *
     * Regarding '<S2>/D':
     *   Gain value: rtP.D_b_Gain
     */
    rtB.D_b = rtB.Cart_Position * rtP.D_b_Gain;
  }

  if (rtmIsContinuousTask(rtM_testro, tid)) { /* Sample time: [0.0, 0.0] */

    /* Derivative Block: <S2>/Derivative */
    {
      real_T t = rtmGetTaskTime(rtM_testro, tid);
      real_T timeStampA = rtDWork.Derivative_b_RWORK.TimeStampA;
      real_T timeStampB = rtDWork.Derivative_b_RWORK.TimeStampB;

      if (timeStampA >= t && timeStampB >= t) {
        rtb_Derivative_b = 0.0;
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
        rtb_Derivative_b = (rtB.D_b - *lastBank++) / deltaT;
      }
    }

    /* Sum: '<Root>/Sum3' incorporates:
     *   Gain: '<Root>/Gain4'
     *   Sum: '<S3>/Sum'
     *   Sum: '<S2>/Sum'
     *
     * Regarding '<Root>/Gain4':
     *   Gain value: rtP.Gain4_Gain
     */
    rtB.Sum3 = (rtb_Step * rtP.Gain4_Gain)
      + (rtB.Proportional_a + rtb_Integral_a + rtb_Derivative_a)
      + (rtB.Proportional_b + rtb_Integral_b + rtb_Derivative_b);
  }

  if (rtmIsSampleHit(rtM_testro, 1, tid)) { /* Sample time: [0.001, 0.0] */

    /* Level2 S-Function Block: <S1>/Digital To Analog Converter (pci1711FedDac) */
    {
      SimStruct *rts = rtM_testro->childSfunctions[2];
      sfcnOutputs(rts, tid);
    }
  }

  if (rtmIsContinuousTask(rtM_testro, tid)) { /* Sample time: [0.0, 0.0] */

    /* Gain: '<S4>/Scaling'
     *
     * Regarding '<S4>/Scaling':
     *   Gain value: rtP.Scaling_Gain
     */
    rtb_actual_LoadPosition = rtB.Sum3 * rtP.Scaling_Gain;

    /* Saturate: '<S4>/Saturation'
     *
     * Regarding '<S4>/Saturation':
     *   Lower limit: rtP.Saturation_LowerSat
     *   Upper limit: rtP.Saturation_UpperSat
     */
    if (rtb_actual_LoadPosition >= rtP.Saturation_UpperSat) {
      rtB.Saturation = rtP.Saturation_UpperSat;
    } else if (rtb_actual_LoadPosition <= rtP.Saturation_LowerSat) {
      rtB.Saturation = rtP.Saturation_LowerSat;
    } else {
      rtB.Saturation = rtb_actual_LoadPosition;
    }
  }
}

/* Update for root system: '<Root>' */
void MdlUpdate(int_T tid)
{

  if (rtmIsContinuousTask(rtM_testro, tid)) { /* Sample time: [0.0, 0.0] */

    /* Derivative Block: <S3>/Derivative */
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
      *lastBank++ = rtmGetTaskTime(rtM_testro, tid);
      *lastBank++ = rtB.D_a;
    }

    /* Derivative Block: <S2>/Derivative */
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
      *lastBank++ = rtmGetTaskTime(rtM_testro, tid);
      *lastBank++ = rtB.D_b;
    }
  }
}

/* Derivatives for root system: '<Root>' */
void MdlDerivatives(void)
{
  /* simstruct variables */
  StateDerivatives *rtXdot = (StateDerivatives*) rtM_testro->ModelData.derivs;

  /* TransferFcn Block: <S3>/Integral */
  {

    rtXdot->Integral_a_CSTATE = rtB.Sum4;
    rtXdot->Integral_a_CSTATE += (rtP.Integral_a_A)*rtX.Integral_a_CSTATE;
  }

  /* TransferFcn Block: <S2>/Integral */
  {

    rtXdot->Integral_b_CSTATE = rtB.Cart_Position;
    rtXdot->Integral_b_CSTATE += (rtP.Integral_b_A)*rtX.Integral_b_CSTATE;
  }
}

/* Projection for root system: '<Root>' */
void MdlProjection(void)
{
}

/* Terminate for root system: '<Root>' */
void MdlTerminate(void)
{
  if(rtM_testro != NULL) {

    /* Level2 S-Function Block: <S1>/Read Cart Encoder1 (pci1711FedEnc) */
    {
      SimStruct *rts = rtM_testro->childSfunctions[0];
      sfcnTerminate(rts);
    }

    /* Level2 S-Function Block: <S1>/Read Pendulum Encoder (pci1711FedEnc) */
    {
      SimStruct *rts = rtM_testro->childSfunctions[1];
      sfcnTerminate(rts);
    }

    /* Level2 S-Function Block: <S1>/Digital To Analog Converter (pci1711FedDac) */
    {
      SimStruct *rts = rtM_testro->childSfunctions[2];
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
  rtM_testro->Sizes.numContStates = (2); /* Number of continuous states */
  rtM_testro->Sizes.numY = (0);         /* Number of model outputs */
  rtM_testro->Sizes.numU = (0);         /* Number of model inputs */
  rtM_testro->Sizes.sysDirFeedThru = (0); /* The model is not direct feedthrough */
  rtM_testro->Sizes.numSampTimes = (3); /* Number of sample times */
  rtM_testro->Sizes.numBlocks = (23);   /* Number of blocks */
  rtM_testro->Sizes.numBlockIO = (11); /* Number of block outputs */
  rtM_testro->Sizes.numBlockPrms = (54); /* Sum of parameter "widths" */
}

/* Function to initialize sample times */
void MdlInitializeSampleTimes(void)
{
  /* task periods */
  rtM_testro->Timing.sampleTimes[0] = (0.0);
  rtM_testro->Timing.sampleTimes[1] = (0.001);
  rtM_testro->Timing.sampleTimes[2] = (0.01);

  /* task offsets */
  rtM_testro->Timing.offsetTimes[0] = (0.0);
  rtM_testro->Timing.offsetTimes[1] = (0.0);
  rtM_testro->Timing.offsetTimes[2] = (0.0);
}

/* Function to register the model */
rtModel_testro *testro(void)
{
  (void)memset((char *)rtM_testro, 0, sizeof(rtModel_testro));

  {
    /* Setup solver object */
    static RTWSolverInfo rt_SolverInfo;
    rtM_testro->solverInfo = (&rt_SolverInfo);

    rtsiSetSimTimeStepPtr(rtM_testro->solverInfo,
     &rtM_testro->Timing.simTimeStep);
    rtsiSetTPtr(rtM_testro->solverInfo, &rtmGetTPtr(rtM_testro));
    rtsiSetStepSizePtr(rtM_testro->solverInfo, &rtM_testro->Timing.stepSize);
    rtsiSetdXPtr(rtM_testro->solverInfo, &rtM_testro->ModelData.derivs);
    rtsiSetContStatesPtr(rtM_testro->solverInfo,
     &rtM_testro->ModelData.contStates);
    rtsiSetNumContStatesPtr(rtM_testro->solverInfo,
     &rtM_testro->Sizes.numContStates);
    rtsiSetErrorStatusPtr(rtM_testro->solverInfo,
     &rtmGetErrorStatus(rtM_testro));

    rtsiSetRTModelPtr(rtM_testro->solverInfo, rtM_testro);
  }

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
    (void)memset((char_T *)&mdlTsMap[0], 0, 3 * sizeof(int_T));
    (void)memset((char_T *)&mdlSampleHits[0], 0, 3 * sizeof(int_T));

    rtM_testro->Timing.sampleTimes = (&mdlPeriod[0]);
    rtM_testro->Timing.offsetTimes = (&mdlOffset[0]);
    rtM_testro->Timing.sampleTimeTaskIDPtr = (&mdlTsMap[0]);
    rtmSetTPtr(rtM_testro, &mdlTaskTimes[0]);
    rtM_testro->Timing.sampleHits = (&mdlSampleHits[0]);
  }
  rtsiSetSolverMode(rtM_testro->solverInfo, SOLVER_MODE_SINGLETASKING);

  /*
   * initialize model vectors and cache them in SimStruct
   */

  /* block I/O */
  {
    void *b = (void *) &rtB;
    rtM_testro->ModelData.blockIO = (b);

    {
      int_T i;

      b =&rtB.Read_Cart_Encoder1;
      for (i = 0; i < 11; i++) {
        ((real_T*)b)[i] = 0.0;
      }
    }
  }

  /* parameters */
  rtM_testro->ModelData.defaultParam = ((real_T *) &rtP);

  /* states */
  {
    int_T i;
    real_T *x = (real_T *) &rtX;
    rtM_testro->ModelData.contStates = (x);
    for(i = 0; i < (int_T)(sizeof(ContinuousStates)/sizeof(real_T)); i++) {
      x[i] = 0.0;
    }
  }

  /* data type work */
  {
    void *dwork = (void *) &rtDWork;
    rtM_testro->Work.dwork = (dwork);
    (void)memset((char_T *) dwork, 0, sizeof(D_Work));
    {
      int_T i;
      real_T *dwork_ptr = (real_T *) &rtDWork.Derivative_a_RWORK.TimeStampA;

      for (i = 0; i < 8; i++) {
        dwork_ptr[i] = 0.0;
      }
    }
  }

  /* Model specific registration */

  rtM_testro->modelName = ("testro");
  rtM_testro->path = ("testro");

  rtmSetTStart(rtM_testro, 0.0);
  rtM_testro->Timing.tFinal = (-1);
  rtM_testro->Timing.stepSize = (0.001);
  rtsiSetFixedStepSize(rtM_testro->solverInfo, 0.001);
  /* Setup for data logging */
  {
    static RTWLogInfo rt_DataLoggingInfo;

    rtM_testro->rtwLogInfo = (&rt_DataLoggingInfo);

    rtliSetLogFormat(rtM_testro->rtwLogInfo, 0);

    rtliSetLogMaxRows(rtM_testro->rtwLogInfo, 1000);

    rtliSetLogDecimation(rtM_testro->rtwLogInfo, 1);

    rtliSetLogVarNameModifier(rtM_testro->rtwLogInfo, "rt_");

    rtliSetLogT(rtM_testro->rtwLogInfo, "tout");

    rtliSetLogX(rtM_testro->rtwLogInfo, "");

    rtliSetLogXFinal(rtM_testro->rtwLogInfo, "");

    rtliSetLogXSignalInfo(rtM_testro->rtwLogInfo, NULL);

    rtliSetLogXSignalPtrs(rtM_testro->rtwLogInfo, NULL);

    rtliSetLogY(rtM_testro->rtwLogInfo, "");

    rtliSetLogYSignalInfo(rtM_testro->rtwLogInfo, NULL);

    rtliSetLogYSignalPtrs(rtM_testro->rtwLogInfo, NULL);
  }

  rtM_testro->Sizes.checksums[0] = (734056204U);
  rtM_testro->Sizes.checksums[1] = (1654362716U);
  rtM_testro->Sizes.checksums[2] = (2629496425U);
  rtM_testro->Sizes.checksums[3] = (4232700560U);

  /* child S-Function registration */
  {
    static RTWSfcnInfo _sfcnInfo;
    RTWSfcnInfo *sfcnInfo = &_sfcnInfo;

    rtM_testro->sfcnInfo = (sfcnInfo);

    rtssSetErrorStatusPtr(sfcnInfo, &rtmGetErrorStatus(rtM_testro));
    rtssSetNumRootSampTimesPtr(sfcnInfo, &rtM_testro->Sizes.numSampTimes);
    rtssSetTPtrPtr(sfcnInfo, &rtmGetTPtr(rtM_testro));
    rtssSetTStartPtr(sfcnInfo, &rtmGetTStart(rtM_testro));
    rtssSetTFinalPtr(sfcnInfo, &rtM_testro->Timing.tFinal);
    rtssSetTimeOfLastOutputPtr(sfcnInfo, &rtM_testro->Timing.timeOfLastOutput);
    rtssSetStepSizePtr(sfcnInfo, &rtM_testro->Timing.stepSize);
    rtssSetStopRequestedPtr(sfcnInfo, &rtM_testro->Timing.stopRequestedFlag);
    rtssSetDerivCacheNeedsResetPtr(sfcnInfo,
     &rtM_testro->ModelData.derivCacheNeedsReset);
    rtssSetZCCacheNeedsResetPtr(sfcnInfo,
     &rtM_testro->ModelData.zCCacheNeedsReset);
    rtssSetBlkStateChangePtr(sfcnInfo, &rtM_testro->ModelData.blkStateChange);
    rtssSetSampleHitsPtr(sfcnInfo, &rtM_testro->Timing.sampleHits);
    rtssSetPerTaskSampleHitsPtr(sfcnInfo,
     &rtM_testro->Timing.perTaskSampleHits);
    rtssSetSimModePtr(sfcnInfo, &rtM_testro->simMode);
    rtssSetSolverInfoPtr(sfcnInfo, &rtM_testro->solverInfo);
  }

  rtM_testro->Sizes.numSFcns = (3);

  /* register each child */
  {
    static SimStruct childSFunctions[3];
    static SimStruct *childSFunctionPtrs[3];

    (void)memset((char_T *)&childSFunctions[0], 0, sizeof(childSFunctions));
    rtM_testro->childSfunctions = (&childSFunctionPtrs[0]);
    {
      int_T i;

      for(i = 0; i < 3; i++) {
        rtM_testro->childSfunctions[i] = (&childSFunctions[i]);
      }
    }

    /* Level2 S-Function Block: testro/<S1>/Read Cart Encoder1 (pci1711FedEnc) */
    {
      SimStruct *rts = rtM_testro->childSfunctions[0];
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
      {
        static struct _ssBlkInfo2 _blkInfo2;
        struct _ssBlkInfo2 *blkInfo2 = &_blkInfo2;
        ssSetBlkInfo2Ptr(rts, blkInfo2);
        ssSetRTWSfcnInfo(rts, rtM_testro->sfcnInfo);
      }

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
          ssSetOutputPortSignal(rts, 0, ((real_T *) &rtB.Read_Cart_Encoder1));
        }
      }
      /* path info */
      ssSetModelName(rts, "Read Cart Encoder1");
      ssSetPath(rts, "testro/IP/Read Cart Encoder1");
      ssSetRTModel(rts,rtM_testro);
      ssSetParentSS(rts, NULL);
      ssSetRootSS(rts, rts);
      ssSetVersion(rts, SIMSTRUCT_VERSION_LEVEL2);

      /* parameters */
      {
        static mxArray *sfcnParams[4];

        ssSetSFcnParamsCount(rts, 4);
        ssSetSFcnParamsPtr(rts, &sfcnParams[0]);

        ssSetSFcnParam(rts, 0, &rtP.Read_Cart_Encoder1_P1_Size[0]);
        ssSetSFcnParam(rts, 1, &rtP.Read_Cart_Encoder1_P2_Size[0]);
        ssSetSFcnParam(rts, 2, &rtP.Read_Cart_Encoder1_P3_Size[0]);
        ssSetSFcnParam(rts, 3, &rtP.Read_Cart_Encoder1_P4_Size[0]);
      }

      /* work vectors */
      ssSetIWork(rts, (int_T *) &rtDWork.Read_Cart_Encoder1_IWORK);
      {
        static struct _ssDWorkRecord dWorkRecord[1];

        ssSetSFcnDWork(rts, dWorkRecord);
        _ssSetNumDWork(rts, 1);

        /* IWORK */
        ssSetDWorkWidth(rts, 0, 1);
        ssSetDWorkDataType(rts, 0,SS_INTEGER);
        ssSetDWorkComplexSignal(rts, 0, 0);
        ssSetDWork(rts, 0, &rtDWork.Read_Cart_Encoder1_IWORK);
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

    /* Level2 S-Function Block: testro/<S1>/Read Pendulum Encoder (pci1711FedEnc) */
    {
      SimStruct *rts = rtM_testro->childSfunctions[1];
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
      {
        static struct _ssBlkInfo2 _blkInfo2;
        struct _ssBlkInfo2 *blkInfo2 = &_blkInfo2;
        ssSetBlkInfo2Ptr(rts, blkInfo2);
        ssSetRTWSfcnInfo(rts, rtM_testro->sfcnInfo);
      }

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
      ssSetPath(rts, "testro/IP/Read Pendulum Encoder");
      ssSetRTModel(rts,rtM_testro);
      ssSetParentSS(rts, NULL);
      ssSetRootSS(rts, rts);
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

    /* Level2 S-Function Block: testro/<S1>/Digital To Analog Converter (pci1711FedDac) */
    {
      SimStruct *rts = rtM_testro->childSfunctions[2];
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
      {
        static struct _ssBlkInfo2 _blkInfo2;
        struct _ssBlkInfo2 *blkInfo2 = &_blkInfo2;
        ssSetBlkInfo2Ptr(rts, blkInfo2);
        ssSetRTWSfcnInfo(rts, rtM_testro->sfcnInfo);
      }

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
      ssSetModelName(rts, "Digital To Analog\nConverter");
      ssSetPath(rts, "testro/IP/Digital To Analog Converter");
      ssSetRTModel(rts,rtM_testro);
      ssSetParentSS(rts, NULL);
      ssSetRootSS(rts, rts);
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
  }

  return rtM_testro;
}

