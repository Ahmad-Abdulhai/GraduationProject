/*
 * Real-Time Workshop code generation for Simulink model "IP_Fuzzy.mdl".
 *
 * Model Version                        : 1.88
 * Real-Time Workshop file version      : 5.0 $Date: 2002/05/30 19:21:33 $
 * Real-Time Workshop file generated on : Thu Apr 09 14:12:49 2009
 * TLC version                          : 5.0 (Jun 18 2002)
 * C source code generated on           : Thu Apr 09 14:12:49 2009
 */

#include <math.h>
#include <string.h>
#include "IP_Fuzzy.h"
#include "IP_Fuzzy_private.h"
#include "ext_work.h"

#include "IP_Fuzzy_dt.h"
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

  /* Derivative Block: <S4>/Derivative */
  rtDWork.Derivative_a_RWORK.TimeStampA = rtInf;
  rtDWork.Derivative_a_RWORK.TimeStampB = rtInf;

  /* Memory Block: <S4>/Memory */
  rtDWork.Memory_a_PreviousInput = rtP.Memory_a_X0;

  /* Derivative Block: <S5>/Derivative */
  rtDWork.Derivative_b_RWORK.TimeStampA = rtInf;
  rtDWork.Derivative_b_RWORK.TimeStampB = rtInf;

  /* Memory Block: <S5>/Memory */
  rtDWork.Memory_b_PreviousInput = rtP.Memory_b_X0;
}

/* Start for root system: '<Root>' */
void MdlStart(void)
{

  /* Level2 S-Function Block: <Root>/Digital To Analog Converter (pci1711FedDac) */
  {
    SimStruct *rts = ssGetSFunction(rtS, 0);
    sfcnStart(rts);
  }

  /* Level2 S-Function Block: <Root>/Read Cart Encoder1 (pci1711FedEnc) */
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
  real_T rtb_Derivative_a;
  real_T rtb_Derivative_b;
  real_T rtb_actual_LoadPosition;

  if (ssIsSampleHit(rtS, 1, tid)) {     /* Sample time: [0.001, 0.0] */

    /* Level2 S-Function Block: <Root>/Digital To Analog Converter (pci1711FedDac) */
    {
      SimStruct *rts = ssGetSFunction(rtS, 0);
      sfcnOutputs(rts, tid);
    }

    /* Level2 S-Function Block: <Root>/Read Cart Encoder1 (pci1711FedEnc) */
    {
      SimStruct *rts = ssGetSFunction(rtS, 1);
      sfcnOutputs(rts, tid);
    }

    /* Gain: '<Root>/Counts->Meters'
     *
     * Regarding '<Root>/Counts->Meters':
     *   Gain value: rtP.Counts_Meters_Gain
     */
    rtB.Cart_Position = rtB.Read_Cart_Encoder1 * rtP.Counts_Meters_Gain;
  }

  if (ssIsContinuousTask(rtS, tid)) {   /* Sample time: [0.0, 0.0] */

    /* Step: '<Root>/Step' */
    if (ssGetTaskTime(rtS,tid) < rtP.Step_Time) {
      rtB.Desired_Position = rtP.Step_Y0;
    } else {
      rtB.Desired_Position = rtP.Step_YFinal;
    }
  }

  if (ssIsSampleHit(rtS, 1, tid)) {     /* Sample time: [0.001, 0.0] */

    /* Level2 S-Function Block: <Root>/Read Pendulum Encoder (pci1711FedEnc) */
    {
      SimStruct *rts = ssGetSFunction(rtS, 2);
      sfcnOutputs(rts, tid);
    }

    /* Gain: '<Root>/Counts->Radians'
     *
     * Regarding '<Root>/Counts->Radians':
     *   Gain value: rtP.Counts_Radians_Gain
     */
    rtB.Pendulum_Position = rtB.Read_Pendulum_Encoder * rtP.Counts_Radians_Gain;
  }

  if (ssIsContinuousTask(rtS, tid)) {   /* Sample time: [0.0, 0.0] */

    /* Sum: '<S1>/Sum1' */
    rtB.Sum1_a = - rtB.Cart_Position + rtB.Desired_Position;

    /* Derivative Block: <S4>/Derivative */
    {
      real_T t = ssGetTaskTime(rtS,tid);
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
        rtb_Derivative_a = (rtB.Sum1_a - *lastBank++) / deltaT;
      }
    }

    /* S-Function (sfun_lookupnd): '<S4>/Look-Up Table (n-D)' incorporates:
     *   Gain: '<S4>/Gain1'
     *   Gain: '<S4>/Gain'
     *
     * Regarding '<S4>/Gain1':
     *   Gain value: rtP.Gain1_a_Gain
     *
     * Regarding '<S4>/Gain':
     *   Gain value: rtP.Gain_a_Gain
     */

    /* Look-Up Table (2-D): '<S4>/Look-Up Table (n-D)' */
    rtB.Look_Up_Table_n_D_a = rt_LookLin2BinXZd((rtB.Sum1_a * rtP.Gain1_a_Gain),
      (rtb_Derivative_a * rtP.Gain_a_Gain), rtP.Look_Up_Table_n_D_a_bp01Data,
      rtP.Look_Up_Table_n_D_a_bp02Data, rtP.Look_Up_Table_n_D_a_tableData,
      rtP.Look_Up_Table_n_D_a_maxIndex);
  }

  if (ssIsSampleHit(rtS, 1, tid)) {     /* Sample time: [0.001, 0.0] */

    /* Memory: '<S4>/Memory' */
    rtB.Memory_a = rtDWork.Memory_a_PreviousInput;

    /* Sum: '<S1>/Sum2' incorporates:
     *   Constant: '<S1>/Constant1'
     */
    rtB.Sum2_a = - rtB.Pendulum_Position + rtP.Constant1_Value;
  }

  if (ssIsContinuousTask(rtS, tid)) {   /* Sample time: [0.0, 0.0] */

    /* Derivative Block: <S5>/Derivative */
    {
      real_T t = ssGetTaskTime(rtS,tid);
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
        rtb_Derivative_b = (rtB.Sum2_a - *lastBank++) / deltaT;
      }
    }
  }

  if (ssIsSampleHit(rtS, 1, tid)) {     /* Sample time: [0.001, 0.0] */

    /* Gain: '<S5>/Gain1'
     *
     * Regarding '<S5>/Gain1':
     *   Gain value: rtP.Gain1_b_Gain
     */
    rtB.Gain1_b = rtB.Sum2_a * rtP.Gain1_b_Gain;
  }

  if (ssIsContinuousTask(rtS, tid)) {   /* Sample time: [0.0, 0.0] */

    /* S-Function (sfun_lookupnd): '<S5>/Look-Up Table (n-D)' incorporates:
     *   Gain: '<S5>/Gain'
     *
     * Regarding '<S5>/Gain':
     *   Gain value: rtP.Gain_b_Gain
     */

    /* Look-Up Table (2-D): '<S5>/Look-Up Table (n-D)' */
    rtB.Look_Up_Table_n_D_b = rt_LookLin2BinXZd(rtB.Gain1_b, (rtb_Derivative_b *
      rtP.Gain_b_Gain), rtP.Look_Up_Table_n_D_b_bp01Data,
      rtP.Look_Up_Table_n_D_b_bp02Data, rtP.Look_Up_Table_n_D_b_tableData,
      rtP.Look_Up_Table_n_D_b_maxIndex);
  }

  if (ssIsSampleHit(rtS, 1, tid)) {     /* Sample time: [0.001, 0.0] */

    /* Memory: '<S5>/Memory' */
    rtB.Memory_b = rtDWork.Memory_b_PreviousInput;
  }

  if (ssIsContinuousTask(rtS, tid)) {   /* Sample time: [0.0, 0.0] */

    /* Gain: '<S2>/Scaling' incorporates:
     *   Sum: '<S3>/Sum2'
     *   Sum: '<S4>/Sum1'
     *   Gain: '<S4>/Gain2'
     *   Sum: '<S5>/Sum1'
     *   Gain: '<S5>/Gain2'
     *
     * Regarding '<S2>/Scaling':
     *   Gain value: rtP.Scaling_Gain
     *
     * Regarding '<S4>/Gain2':
     *   Gain value: rtP.Gain2_a_Gain
     *
     * Regarding '<S5>/Gain2':
     *   Gain value: rtP.Gain2_b_Gain
     */
    rtb_actual_LoadPosition = (((rtB.Look_Up_Table_n_D_a * rtP.Gain2_a_Gain) +
      rtB.Memory_a) + ((rtB.Look_Up_Table_n_D_b * rtP.Gain2_b_Gain) +
      rtB.Memory_b)) * rtP.Scaling_Gain;

    /* Saturate: '<S2>/Saturation'
     *
     * Regarding '<S2>/Saturation':
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

  if (ssIsContinuousTask(rtS, tid)) {   /* Sample time: [0.0, 0.0] */

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
      *lastBank++ = rtB.Sum1_a;
    }
  }

  if (ssIsSampleHit(rtS, 1, tid)) {     /* Sample time: [0.001, 0.0] */

    /* Memory Block: <S4>/Memory */
    rtDWork.Memory_a_PreviousInput = rtB.Look_Up_Table_n_D_a;
  }

  if (ssIsContinuousTask(rtS, tid)) {   /* Sample time: [0.0, 0.0] */

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
      *lastBank++ = rtB.Sum2_a;
    }
  }

  if (ssIsSampleHit(rtS, 1, tid)) {     /* Sample time: [0.001, 0.0] */

    /* Memory Block: <S5>/Memory */
    rtDWork.Memory_b_PreviousInput = rtB.Look_Up_Table_n_D_b;
  }
}

/* Terminate for root system: '<Root>' */
void MdlTerminate(void)
{
  if(rtS != NULL) {

    /* Level2 S-Function Block: <Root>/Digital To Analog Converter (pci1711FedDac) */
    {
      SimStruct *rts = ssGetSFunction(rtS, 0);
      sfcnTerminate(rts);
    }

    /* Level2 S-Function Block: <Root>/Read Cart Encoder1 (pci1711FedEnc) */
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
  ssSetNumContStates(rtS, 0);           /* Number of continuous states */
  ssSetNumY(rtS, 0);                    /* Number of model outputs */
  ssSetNumU(rtS, 0);                    /* Number of model inputs */
  ssSetDirectFeedThrough(rtS, 0);       /* The model is not direct feedthrough */
  ssSetNumSampleTimes(rtS, 3);          /* Number of sample times */
  ssSetNumBlocks(rtS, 30);              /* Number of blocks */
  ssSetNumBlockIO(rtS, 13);             /* Number of block outputs */
  ssSetNumBlockParams(rtS, 13503);      /* Sum of parameter "widths" */
}

/* Function to initialize sample times */
void MdlInitializeSampleTimes(void)
{
  /* task periods */
  ssSetSampleTime(rtS, 0, 0.0);
  ssSetSampleTime(rtS, 1, 0.001);
  ssSetSampleTime(rtS, 2, 0.01);

  /* task offsets */
  ssSetOffsetTime(rtS, 0, 0.0);
  ssSetOffsetTime(rtS, 1, 0.0);
  ssSetOffsetTime(rtS, 2, 0.0);
}

/* Function to register the model */
SimStruct *IP_Fuzzy(void)
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
    (void)memset((char_T *)&mdlTsMap[0], 0, 3 * sizeof(int_T));
    (void)memset((char_T *)&mdlSampleHits[0], 0, 3 * sizeof(int_T));

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
      for (i = 0; i < 13; i++) {
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
      real_T *dwork_ptr = (real_T *) &rtDWork.Memory_a_PreviousInput;

      for (i = 0; i < 10; i++) {
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
  ssSetModelName(rtS, "IP_Fuzzy");
  ssSetPath(rtS, "IP_Fuzzy");

  ssSetTStart(rtS, 0.0);
  ssSetTFinal(rtS, 70.0);
  ssSetStepSize(rtS, 0.001);
  ssSetFixedStepSize(rtS, 0.001);

  ssSetChecksumVal(rtS, 0, 1956683916U);
  ssSetChecksumVal(rtS, 1, 1148969180U);
  ssSetChecksumVal(rtS, 2, 716391119U);
  ssSetChecksumVal(rtS, 3, 1502320611U);

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

    /* Level2 S-Function Block: IP_Fuzzy/<Root>/Digital To Analog Converter (pci1711FedDac) */
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
      ssSetModelName(rts, "Digital To Analog\nConverter");
      ssSetPath(rts, "IP_Fuzzy/Digital To Analog Converter");
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

    /* Level2 S-Function Block: IP_Fuzzy/<Root>/Read Cart Encoder1 (pci1711FedEnc) */
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
          ssSetOutputPortSignal(rts, 0, ((real_T *) &rtB.Read_Cart_Encoder1));
        }
      }
      /* path info */
      ssSetModelName(rts, "Read Cart Encoder1");
      ssSetPath(rts, "IP_Fuzzy/Read Cart Encoder1");
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

    /* Level2 S-Function Block: IP_Fuzzy/<Root>/Read Pendulum Encoder (pci1711FedEnc) */
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
      ssSetPath(rts, "IP_Fuzzy/Read Pendulum Encoder");
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

