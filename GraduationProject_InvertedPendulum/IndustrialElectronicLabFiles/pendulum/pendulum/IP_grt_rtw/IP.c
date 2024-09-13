/*
 * Real-Time Workshop code generation for Simulink model "IP.mdl".
 *
 * Model Version                        : 1.1
 * Real-Time Workshop file version      : 5.0 $Date: 2002/05/30 19:21:33 $
 * Real-Time Workshop file generated on : Mon Mar 16 17:05:41 2009
 * TLC version                          : 5.0 (Jun 18 2002)
 * C source code generated on           : Mon Mar 16 17:05:41 2009
 */

#include <math.h>
#include <string.h>
#include "IP.h"
#include "IP_private.h"

/* Block signals (auto storage) */
BlockIO rtB;

/* Block states (auto storage) */
D_Work rtDWork;

/* Parent Simstruct */
static rtModel_IP model_S;
rtModel_IP *const rtM_IP = &model_S;

/* Start for root system: '<Root>' */
void MdlStart(void)
{

  /* Level2 S-Function Block: <S1>/Read Cart Encoder1 (pci1711FedEnc) */
  {
    SimStruct *rts = rtM_IP->childSfunctions[0];
    sfcnStart(rts);
  }

  /* Level2 S-Function Block: <S1>/Read Pendulum Encoder (pci1711FedEnc) */
  {
    SimStruct *rts = rtM_IP->childSfunctions[1];
    sfcnStart(rts);
  }

  /* Scope Block: <Root>/Scope */
  {
    volatile int_T numCols = 5;

    rtDWork.Scope_PWORK.LoggedData = rt_CreateLogVar(rtM_IP->rtwLogInfo,
      rtM_IP->Timing.tFinal, rtM_IP->Timing.stepSize,
      &(rtmGetErrorStatus(rtM_IP)), "y", SS_DOUBLE, 0, 0, 0, 5, 1, (int_T
      *)&numCols, 0, 1, 0.001, 1);

    if (rtDWork.Scope_PWORK.LoggedData == NULL) return;
  }

  /* Level2 S-Function Block: <S1>/Digital To Analog Converter (pci1711FedDac) */
  {
    SimStruct *rts = rtM_IP->childSfunctions[2];
    sfcnStart(rts);
  }
}

/* Outputs for root system: '<Root>' */
void MdlOutputs(int_T tid)
{
  /* local block i/o variables */
  real_T rtb_Step;
  real_T rtb_Cart_Position;
  real_T rtb_Pendulum_Position;
  real_T rtb_temp8;

  /* tid is required for a uniform function interface. This system
   * is single rate, and in this case, tid is not accessed. */
  UNUSED_PARAMETER(tid);

  /* Clock: '<Root>/Clock' */
  rtB.Clock = rtmGetT(rtM_IP);

  /* Step: '<Root>/Step' */
  if (rtmGetT(rtM_IP) < rtP.Step_Time) {
    rtb_Step = rtP.Step_Y0;
  } else {
    rtb_Step = rtP.Step_YFinal;
  }

  /* Step: '<Root>/Step1' */
  if (rtmGetT(rtM_IP) < rtP.Step1_Time) {
    rtb_temp8 = rtP.Step1_Y0;
  } else {
    rtb_temp8 = rtP.Step1_YFinal;
  }

  /* Sum: '<Root>/Sum' */
  rtB.Sum = rtb_Step + rtb_temp8;

  /* Level2 S-Function Block: <S1>/Read Cart Encoder1 (pci1711FedEnc) */
  {
    SimStruct *rts = rtM_IP->childSfunctions[0];
    sfcnOutputs(rts, tid);
  }

  /* Gain: '<S1>/Counts->Meters'
   *
   * Regarding '<S1>/Counts->Meters':
   *   Gain value: rtP.Counts_Meters_Gain
   */
  rtb_Cart_Position = rtB.Read_Cart_Encoder1 * rtP.Counts_Meters_Gain;

  /* Level2 S-Function Block: <S1>/Read Pendulum Encoder (pci1711FedEnc) */
  {
    SimStruct *rts = rtM_IP->childSfunctions[1];
    sfcnOutputs(rts, tid);
  }

  /* Gain: '<S1>/Counts->Radians'
   *
   * Regarding '<S1>/Counts->Radians':
   *   Gain value: rtP.Counts_Radians_Gain
   */
  rtb_Pendulum_Position = rtB.Read_Pendulum_Encoder * rtP.Counts_Radians_Gain;

  /* Scope: '<Root>/Scope' */
  {
    real_T u[5];
    u[0] = rtmGetT(rtM_IP);
    u[1] = rtB.Clock;
    u[2] = rtB.Sum;
    u[3] = rtb_Cart_Position;
    u[4] = rtb_Pendulum_Position;
    rt_UpdateLogVar(rtDWork.Scope_PWORK.LoggedData, u);
  }

  /* Level2 S-Function Block: <S1>/Digital To Analog Converter (pci1711FedDac) */
  {
    SimStruct *rts = rtM_IP->childSfunctions[2];
    sfcnOutputs(rts, tid);
  }

  /* Gain: '<S2>/Scaling'
   *
   * Regarding '<S2>/Scaling':
   *   Gain value: rtP.Scaling_Gain
   */
  rtb_temp8 = rtB.Sum * rtP.Scaling_Gain;

  /* Saturate: '<S2>/Saturation'
   *
   * Regarding '<S2>/Saturation':
   *   Lower limit: rtP.Saturation_LowerSat
   *   Upper limit: rtP.Saturation_UpperSat
   */
  if (rtb_temp8 >= rtP.Saturation_UpperSat) {
    rtB.Saturation = rtP.Saturation_UpperSat;
  } else if (rtb_temp8 <= rtP.Saturation_LowerSat) {
    rtB.Saturation = rtP.Saturation_LowerSat;
  } else {
    rtB.Saturation = rtb_temp8;
  }
}

/* Update for root system: '<Root>' */
void MdlUpdate(int_T tid)
{

  /* tid is required for a uniform function interface. This system
   * is single rate, and in this case, tid is not accessed. */
  UNUSED_PARAMETER(tid);
}

/* Terminate for root system: '<Root>' */
void MdlTerminate(void)
{
  if(rtM_IP != NULL) {

    /* Level2 S-Function Block: <S1>/Read Cart Encoder1 (pci1711FedEnc) */
    {
      SimStruct *rts = rtM_IP->childSfunctions[0];
      sfcnTerminate(rts);
    }

    /* Level2 S-Function Block: <S1>/Read Pendulum Encoder (pci1711FedEnc) */
    {
      SimStruct *rts = rtM_IP->childSfunctions[1];
      sfcnTerminate(rts);
    }

    /* Level2 S-Function Block: <S1>/Digital To Analog Converter (pci1711FedDac) */
    {
      SimStruct *rts = rtM_IP->childSfunctions[2];
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
  rtM_IP->Sizes.numContStates = (0);    /* Number of continuous states */
  rtM_IP->Sizes.numY = (0);             /* Number of model outputs */
  rtM_IP->Sizes.numU = (0);             /* Number of model inputs */
  rtM_IP->Sizes.sysDirFeedThru = (0);   /* The model is not direct feedthrough */
  rtM_IP->Sizes.numSampTimes = (2);     /* Number of sample times */
  rtM_IP->Sizes.numBlocks = (12);       /* Number of blocks */
  rtM_IP->Sizes.numBlockIO = (5);       /* Number of block outputs */
  rtM_IP->Sizes.numBlockPrms = (47);    /* Sum of parameter "widths" */
}

/* Function to initialize sample times */
void MdlInitializeSampleTimes(void)
{
  /* task periods */
  rtM_IP->Timing.sampleTimes[0] = (0.0);
  rtM_IP->Timing.sampleTimes[1] = (0.001);

  /* task offsets */
  rtM_IP->Timing.offsetTimes[0] = (0.0);
  rtM_IP->Timing.offsetTimes[1] = (0.0);
}

/* Function to register the model */
rtModel_IP *IP(void)
{
  (void)memset((char *)rtM_IP, 0, sizeof(rtModel_IP));

  {
    /* Setup solver object */
    static RTWSolverInfo rt_SolverInfo;
    rtM_IP->solverInfo = (&rt_SolverInfo);

    rtsiSetSimTimeStepPtr(rtM_IP->solverInfo, &rtM_IP->Timing.simTimeStep);
    rtsiSetTPtr(rtM_IP->solverInfo, &rtmGetTPtr(rtM_IP));
    rtsiSetStepSizePtr(rtM_IP->solverInfo, &rtM_IP->Timing.stepSize);
    rtsiSetdXPtr(rtM_IP->solverInfo, &rtM_IP->ModelData.derivs);
    rtsiSetContStatesPtr(rtM_IP->solverInfo, &rtM_IP->ModelData.contStates);
    rtsiSetNumContStatesPtr(rtM_IP->solverInfo, &rtM_IP->Sizes.numContStates);
    rtsiSetErrorStatusPtr(rtM_IP->solverInfo, &rtmGetErrorStatus(rtM_IP));

    rtsiSetRTModelPtr(rtM_IP->solverInfo, rtM_IP);
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
    (void)memset((char_T *)&mdlTsMap[0], 0, 2 * sizeof(int_T));
    (void)memset((char_T *)&mdlSampleHits[0], 0, 2 * sizeof(int_T));

    rtM_IP->Timing.sampleTimes = (&mdlPeriod[0]);
    rtM_IP->Timing.offsetTimes = (&mdlOffset[0]);
    rtM_IP->Timing.sampleTimeTaskIDPtr = (&mdlTsMap[0]);
    rtmSetTPtr(rtM_IP, &mdlTaskTimes[0]);
    rtM_IP->Timing.sampleHits = (&mdlSampleHits[0]);
  }
  rtsiSetSolverMode(rtM_IP->solverInfo, SOLVER_MODE_SINGLETASKING);

  /*
   * initialize model vectors and cache them in SimStruct
   */

  /* block I/O */
  {
    void *b = (void *) &rtB;
    rtM_IP->ModelData.blockIO = (b);

    {
      int_T i;

      b =&rtB.Clock;
      for (i = 0; i < 5; i++) {
        ((real_T*)b)[i] = 0.0;
      }
    }
  }

  /* parameters */
  rtM_IP->ModelData.defaultParam = ((real_T *) &rtP);

  /* data type work */
  {
    void *dwork = (void *) &rtDWork;
    rtM_IP->Work.dwork = (dwork);
    (void)memset((char_T *) dwork, 0, sizeof(D_Work));
  }

  /* Model specific registration */

  rtM_IP->modelName = ("IP");
  rtM_IP->path = ("IP");

  rtmSetTStart(rtM_IP, 0.0);
  rtM_IP->Timing.tFinal = (15.0);
  rtM_IP->Timing.stepSize = (0.001);
  rtsiSetFixedStepSize(rtM_IP->solverInfo, 0.001);
  /* Setup for data logging */
  {
    static RTWLogInfo rt_DataLoggingInfo;

    rtM_IP->rtwLogInfo = (&rt_DataLoggingInfo);

    rtliSetLogFormat(rtM_IP->rtwLogInfo, 0);

    rtliSetLogMaxRows(rtM_IP->rtwLogInfo, 1000);

    rtliSetLogDecimation(rtM_IP->rtwLogInfo, 1);

    rtliSetLogVarNameModifier(rtM_IP->rtwLogInfo, "rt_");

    rtliSetLogT(rtM_IP->rtwLogInfo, "tout");

    rtliSetLogX(rtM_IP->rtwLogInfo, "");

    rtliSetLogXFinal(rtM_IP->rtwLogInfo, "");

    rtliSetLogXSignalInfo(rtM_IP->rtwLogInfo, NULL);

    rtliSetLogXSignalPtrs(rtM_IP->rtwLogInfo, NULL);

    rtliSetLogY(rtM_IP->rtwLogInfo, "");

    rtliSetLogYSignalInfo(rtM_IP->rtwLogInfo, NULL);

    rtliSetLogYSignalPtrs(rtM_IP->rtwLogInfo, NULL);
  }

  rtM_IP->Sizes.checksums[0] = (3872519999U);
  rtM_IP->Sizes.checksums[1] = (1012107053U);
  rtM_IP->Sizes.checksums[2] = (1535781685U);
  rtM_IP->Sizes.checksums[3] = (1724369096U);

  /* child S-Function registration */
  {
    static RTWSfcnInfo _sfcnInfo;
    RTWSfcnInfo *sfcnInfo = &_sfcnInfo;

    rtM_IP->sfcnInfo = (sfcnInfo);

    rtssSetErrorStatusPtr(sfcnInfo, &rtmGetErrorStatus(rtM_IP));
    rtssSetNumRootSampTimesPtr(sfcnInfo, &rtM_IP->Sizes.numSampTimes);
    rtssSetTPtrPtr(sfcnInfo, &rtmGetTPtr(rtM_IP));
    rtssSetTStartPtr(sfcnInfo, &rtmGetTStart(rtM_IP));
    rtssSetTFinalPtr(sfcnInfo, &rtM_IP->Timing.tFinal);
    rtssSetTimeOfLastOutputPtr(sfcnInfo, &rtM_IP->Timing.timeOfLastOutput);
    rtssSetStepSizePtr(sfcnInfo, &rtM_IP->Timing.stepSize);
    rtssSetStopRequestedPtr(sfcnInfo, &rtM_IP->Timing.stopRequestedFlag);
    rtssSetDerivCacheNeedsResetPtr(sfcnInfo,
     &rtM_IP->ModelData.derivCacheNeedsReset);
    rtssSetZCCacheNeedsResetPtr(sfcnInfo, &rtM_IP->ModelData.zCCacheNeedsReset);

    rtssSetBlkStateChangePtr(sfcnInfo, &rtM_IP->ModelData.blkStateChange);
    rtssSetSampleHitsPtr(sfcnInfo, &rtM_IP->Timing.sampleHits);
    rtssSetPerTaskSampleHitsPtr(sfcnInfo, &rtM_IP->Timing.perTaskSampleHits);
    rtssSetSimModePtr(sfcnInfo, &rtM_IP->simMode);
    rtssSetSolverInfoPtr(sfcnInfo, &rtM_IP->solverInfo);
  }

  rtM_IP->Sizes.numSFcns = (3);

  /* register each child */
  {
    static SimStruct childSFunctions[3];
    static SimStruct *childSFunctionPtrs[3];

    (void)memset((char_T *)&childSFunctions[0], 0, sizeof(childSFunctions));
    rtM_IP->childSfunctions = (&childSFunctionPtrs[0]);
    {
      int_T i;

      for(i = 0; i < 3; i++) {
        rtM_IP->childSfunctions[i] = (&childSFunctions[i]);
      }
    }

    /* Level2 S-Function Block: IP/<S1>/Read Cart Encoder1 (pci1711FedEnc) */
    {
      SimStruct *rts = rtM_IP->childSfunctions[0];
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
        ssSetRTWSfcnInfo(rts, rtM_IP->sfcnInfo);
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
      ssSetPath(rts, "IP/IP/Read Cart Encoder1");
      ssSetRTModel(rts,rtM_IP);
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

    /* Level2 S-Function Block: IP/<S1>/Read Pendulum Encoder (pci1711FedEnc) */
    {
      SimStruct *rts = rtM_IP->childSfunctions[1];
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
        ssSetRTWSfcnInfo(rts, rtM_IP->sfcnInfo);
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
      ssSetPath(rts, "IP/IP/Read Pendulum Encoder");
      ssSetRTModel(rts,rtM_IP);
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

    /* Level2 S-Function Block: IP/<S1>/Digital To Analog Converter (pci1711FedDac) */
    {
      SimStruct *rts = rtM_IP->childSfunctions[2];
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
        ssSetRTWSfcnInfo(rts, rtM_IP->sfcnInfo);
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
      ssSetPath(rts, "IP/IP/Digital To Analog Converter");
      ssSetRTModel(rts,rtM_IP);
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

  return rtM_IP;
}

