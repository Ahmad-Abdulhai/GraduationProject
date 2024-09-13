/*
 * Real-Time Workshop code generation for Simulink model "Crane1.mdl".
 *
 * Model Version                        : 1.74
 * Real-Time Workshop file version      : 5.0 $Date: 2002/05/30 19:21:33 $
 * Real-Time Workshop file generated on : Tue Apr 21 13:45:51 2009
 * TLC version                          : 5.0 (Jun 18 2002)
 * C source code generated on           : Tue Apr 21 13:45:51 2009
 */

#include <math.h>
#include <string.h>
#include "Crane1.h"
#include "Crane1_private.h"
#include "ext_work.h"

#include "Crane1_dt.h"
#include "simstruc.h"

/* Block signals (auto storage) */
BlockIO rtB;

/* Block states (auto storage) */
D_Work rtDWork;

/* Parent Simstruct */
static SimStruct model_S;
SimStruct *const rtS = &model_S;

/* Initial conditions for root system: '<Root>' */
void MdlInitialize(void)
{

  /* Derivative Block: <Root>/Derivative2 */
  rtDWork.Derivative2_RWORK.TimeStampA = rtInf;
  rtDWork.Derivative2_RWORK.TimeStampB = rtInf;

  /* Derivative Block: <Root>/Derivative1 */
  rtDWork.Derivative1_RWORK.TimeStampA = rtInf;
  rtDWork.Derivative1_RWORK.TimeStampB = rtInf;
}

/* Start for root system: '<Root>' */
void MdlStart(void)
{

  /* Level2 S-Function Block: <S1>/Read Cart Encoder1 (pci1711FedEnc) */
  {
    SimStruct *rts = ssGetSFunction(rtS, 0);
    sfcnStart(rts);
  }

  /* Level2 S-Function Block: <S1>/Read Pendulum Encoder (pci1711FedEnc) */
  {
    SimStruct *rts = ssGetSFunction(rtS, 1);
    sfcnStart(rts);
  }

  /* Level2 S-Function Block: <S1>/Digital To Analog Converter (pci1711FedDac) */
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
  real_T rtb_Derivative2;
  real_T rtb_Derivative1;
  real_T rtb_Sum[4];
  real_T rtb_temp9;

  /* tid is required for a uniform function interface. This system
   * is single rate, and in this case, tid is not accessed. */
  UNUSED_PARAMETER(tid);

  /* Level2 S-Function Block: <S1>/Read Cart Encoder1 (pci1711FedEnc) */
  {
    SimStruct *rts = ssGetSFunction(rtS, 0);
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
    SimStruct *rts = ssGetSFunction(rtS, 1);
    sfcnOutputs(rts, tid);
  }

  /* Gain: '<S1>/Counts->Radians'
   *
   * Regarding '<S1>/Counts->Radians':
   *   Gain value: rtP.Counts_Radians_Gain
   */
  rtB.Pendulum_Position = rtB.Read_Pendulum_Encoder * rtP.Counts_Radians_Gain;

  /* Derivative Block: <Root>/Derivative2 */
  {
    real_T t = ssGetT(rtS);
    real_T timeStampA = rtDWork.Derivative2_RWORK.TimeStampA;
    real_T timeStampB = rtDWork.Derivative2_RWORK.TimeStampB;

    if (timeStampA >= t && timeStampB >= t) {
      rtb_Derivative2 = 0.0;
    } else {
      real_T deltaT;
      real_T *lastBank = &rtDWork.Derivative2_RWORK.TimeStampA;
      if (timeStampA < timeStampB) {
        if (timeStampB < t) {
          lastBank += 2;
        }
      } else if (timeStampA >= t) {
        lastBank += 2;
      }
      deltaT = t - *lastBank++;
      rtb_Derivative2 = (rtB.Cart_Position - *lastBank++) / deltaT;
    }
  }

  /* Derivative Block: <Root>/Derivative1 */
  {
    real_T t = ssGetT(rtS);
    real_T timeStampA = rtDWork.Derivative1_RWORK.TimeStampA;
    real_T timeStampB = rtDWork.Derivative1_RWORK.TimeStampB;

    if (timeStampA >= t && timeStampB >= t) {
      rtb_Derivative1 = 0.0;
    } else {
      real_T deltaT;
      real_T *lastBank = &rtDWork.Derivative1_RWORK.TimeStampA;
      if (timeStampA < timeStampB) {
        if (timeStampB < t) {
          lastBank += 2;
        }
      } else if (timeStampA >= t) {
        lastBank += 2;
      }
      deltaT = t - *lastBank++;
      rtb_Derivative1 = (rtB.Pendulum_Position - *lastBank++) / deltaT;
    }
  }

  /* Step: '<Root>/Step' */
  if (ssGetT(rtS) < rtP.Step_Time) {
    rtb_temp9 = rtP.Step_Y0;
  } else {
    rtb_temp9 = rtP.Step_YFinal;
  }

  /* Sum: '<Root>/Sum' incorporates:
   *   Constant: '<Root>/Constant'
   *   Constant: '<Root>/Constant1'
   *   Constant: '<Root>/Constant2'
   */
  rtb_Sum[0] = - rtB.Cart_Position + rtb_temp9;
  rtb_Sum[1] = - rtB.Pendulum_Position + rtP.Constant_Value;
  rtb_Sum[2] = - rtb_Derivative2 + rtP.Constant1_Value;
  rtb_Sum[3] = - rtb_Derivative1 + rtP.Constant2_Value;

  /* Gain: '<Root>/Matrix Gain'
   *
   * Regarding '<Root>/Matrix Gain':
   *   Gain value: [7.0711 -11 2.0251 -1.2106]
   */
  {
    static const int dims[3] = { 1, 4, 1 };
    rt_MatMultRR_Dbl((real_T *)&rtB.Matrix_Gain, (real_T
      *)&rtP.Matrix_Gain_Gain[0],
     (real_T *)&rtb_Sum[0], &dims[0]);
  }

  /* Level2 S-Function Block: <S1>/Digital To Analog Converter (pci1711FedDac) */
  {
    SimStruct *rts = ssGetSFunction(rtS, 2);
    sfcnOutputs(rts, tid);
  }

  /* Gain: '<S2>/Scaling'
   *
   * Regarding '<S2>/Scaling':
   *   Gain value: rtP.Scaling_Gain
   */
  rtb_temp9 = rtB.Matrix_Gain * rtP.Scaling_Gain;

  /* Saturate: '<S2>/Saturation'
   *
   * Regarding '<S2>/Saturation':
   *   Lower limit: rtP.Saturation_LowerSat
   *   Upper limit: rtP.Saturation_UpperSat
   */
  if (rtb_temp9 >= rtP.Saturation_UpperSat) {
    rtB.Saturation = rtP.Saturation_UpperSat;
  } else if (rtb_temp9 <= rtP.Saturation_LowerSat) {
    rtB.Saturation = rtP.Saturation_LowerSat;
  } else {
    rtB.Saturation = rtb_temp9;
  }
}

/* Update for root system: '<Root>' */
void MdlUpdate(int_T tid)
{

  /* tid is required for a uniform function interface. This system
   * is single rate, and in this case, tid is not accessed. */
  UNUSED_PARAMETER(tid);

  /* Derivative Block: <Root>/Derivative2 */
  {
    real_T timeStampA = rtDWork.Derivative2_RWORK.TimeStampA;
    real_T timeStampB = rtDWork.Derivative2_RWORK.TimeStampB;
    real_T *lastBank = &rtDWork.Derivative2_RWORK.TimeStampA;

    if (timeStampA != rtInf) {
      if (timeStampB == rtInf) {
        lastBank += 2;
      } else if (timeStampA >= timeStampB) {
        lastBank += 2;
      }
    }
    *lastBank++ = ssGetT(rtS);
    *lastBank++ = rtB.Cart_Position;
  }

  /* Derivative Block: <Root>/Derivative1 */
  {
    real_T timeStampA = rtDWork.Derivative1_RWORK.TimeStampA;
    real_T timeStampB = rtDWork.Derivative1_RWORK.TimeStampB;
    real_T *lastBank = &rtDWork.Derivative1_RWORK.TimeStampA;

    if (timeStampA != rtInf) {
      if (timeStampB == rtInf) {
        lastBank += 2;
      } else if (timeStampA >= timeStampB) {
        lastBank += 2;
      }
    }
    *lastBank++ = ssGetT(rtS);
    *lastBank++ = rtB.Pendulum_Position;
  }
}

/* Terminate for root system: '<Root>' */
void MdlTerminate(void)
{
  if(rtS != NULL) {

    /* Level2 S-Function Block: <S1>/Read Cart Encoder1 (pci1711FedEnc) */
    {
      SimStruct *rts = ssGetSFunction(rtS, 0);
      sfcnTerminate(rts);
    }

    /* Level2 S-Function Block: <S1>/Read Pendulum Encoder (pci1711FedEnc) */
    {
      SimStruct *rts = ssGetSFunction(rtS, 1);
      sfcnTerminate(rts);
    }

    /* Level2 S-Function Block: <S1>/Digital To Analog Converter (pci1711FedDac) */
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
  ssSetNumContStates(rtS, 0);           /* Number of continuous states */
  ssSetNumY(rtS, 0);                    /* Number of model outputs */
  ssSetNumU(rtS, 0);                    /* Number of model inputs */
  ssSetDirectFeedThrough(rtS, 0);       /* The model is not direct feedthrough */
  ssSetNumSampleTimes(rtS, 2);          /* Number of sample times */
  ssSetNumBlocks(rtS, 18);              /* Number of blocks */
  ssSetNumBlockIO(rtS, 6);              /* Number of block outputs */
  ssSetNumBlockParams(rtS, 51);         /* Sum of parameter "widths" */
}

/* Function to initialize sample times */
void MdlInitializeSampleTimes(void)
{
  /* task periods */
  ssSetSampleTime(rtS, 0, 0.0);
  ssSetSampleTime(rtS, 1, 0.001);

  /* task offsets */
  ssSetOffsetTime(rtS, 0, 0.0);
  ssSetOffsetTime(rtS, 1, 0.0);
}

/* Function to register the model */
SimStruct *Crane1(void)
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

      b =&rtB.Read_Cart_Encoder1;
      for (i = 0; i < 6; i++) {
        ((real_T*)b)[i] = 0.0;
      }
    }
  }

  /* parameters */
  ssSetDefaultParam(rtS, (real_T *) &rtP);

  /* data type work */
  {
    void *dwork = (void *) &rtDWork;
    ssSetRootDWork(rtS, dwork);
    (void)memset((char_T *) dwork, 0, sizeof(D_Work));
    {
      int_T i;
      real_T *dwork_ptr = (real_T *) &rtDWork.Derivative2_RWORK.TimeStampA;

      for (i = 0; i < 8; i++) {
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
  ssSetModelName(rtS, "Crane1");
  ssSetPath(rtS, "Crane1");

  ssSetTStart(rtS, 0.0);
  ssSetTFinal(rtS, 50.0);
  ssSetStepSize(rtS, 0.001);
  ssSetFixedStepSize(rtS, 0.001);

  ssSetChecksumVal(rtS, 0, 4108607532U);
  ssSetChecksumVal(rtS, 1, 3572193876U);
  ssSetChecksumVal(rtS, 2, 89665501U);
  ssSetChecksumVal(rtS, 3, 805961731U);

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

    /* Level2 S-Function Block: Crane1/<S1>/Read Cart Encoder1 (pci1711FedEnc) */
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
      ssSetPath(rts, "Crane1/IP/Read Cart Encoder1");
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

    /* Level2 S-Function Block: Crane1/<S1>/Read Pendulum Encoder (pci1711FedEnc) */
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
          ssSetOutputPortSignal(rts, 0, ((real_T *) &rtB.Read_Pendulum_Encoder));
        }
      }
      /* path info */
      ssSetModelName(rts, "Read Pendulum Encoder");
      ssSetPath(rts, "Crane1/IP/Read Pendulum Encoder");
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

    /* Level2 S-Function Block: Crane1/<S1>/Digital To Analog Converter (pci1711FedDac) */
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
      ssSetPath(rts, "Crane1/IP/Digital To Analog Converter");
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
  }

  return rtS;
}

