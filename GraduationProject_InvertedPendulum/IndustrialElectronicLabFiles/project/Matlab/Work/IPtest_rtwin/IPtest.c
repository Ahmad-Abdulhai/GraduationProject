/*
 * Real-Time Workshop code generation for Simulink model "IPtest.mdl".
 *
 * Model Version                        : 1.85
 * Real-Time Workshop file version      : 5.0 $Date: 2002/05/30 19:21:33 $
 * Real-Time Workshop file generated on : Thu Mar 29 02:31:21 2012
 * TLC version                          : 5.0 (Jun 18 2002)
 * C source code generated on           : Thu Mar 29 02:31:21 2012
 */

#include <math.h>
#include <string.h>
#include "IPtest.h"
#include "IPtest_private.h"
#include "ext_work.h"

#include "IPtest_dt.h"
#include "simstruc.h"

/* Block signals (auto storage) */
BlockIO rtB;

/* Block states (auto storage) */
D_Work rtDWork;

/* Parent Simstruct */
static SimStruct model_S;
SimStruct *const rtS = &model_S;

/* Start for root system: '<Root>' */
void MdlStart(void)
{

  /* Level2 S-Function Block: <Root>/Read Cart Encoder1 (pci1711FedEnc) */
  {
    SimStruct *rts = ssGetSFunction(rtS, 0);
    sfcnStart(rts);
  }

  /* Level2 S-Function Block: <Root>/Read Pendulum Encoder (pci1711FedEnc) */
  {
    SimStruct *rts = ssGetSFunction(rtS, 1);
    sfcnStart(rts);
  }
}

/* Outputs for root system: '<Root>' */
void MdlOutputs(int_T tid)
{

  if (ssIsSampleHit(rtS, 0, tid)) {     /* Sample time: [0.001, 0.0] */

    /* Level2 S-Function Block: <Root>/Read Cart Encoder1 (pci1711FedEnc) */
    {
      SimStruct *rts = ssGetSFunction(rtS, 0);
      sfcnOutputs(rts, tid);
    }

    /* Gain: '<Root>/Counts->Meters'
     *
     * Regarding '<Root>/Counts->Meters':
     *   Gain value: rtP.Counts_Meters_Gain
     */
    rtB.Cart_Position = rtB.Read_Cart_Encoder1 * rtP.Counts_Meters_Gain;

    /* Level2 S-Function Block: <Root>/Read Pendulum Encoder (pci1711FedEnc) */
    {
      SimStruct *rts = ssGetSFunction(rtS, 1);
      sfcnOutputs(rts, tid);
    }

    /* Gain: '<Root>/Counts->Radians'
     *
     * Regarding '<Root>/Counts->Radians':
     *   Gain value: rtP.Counts_Radians_Gain
     */
    rtB.Pendulum_Position = rtB.Read_Pendulum_Encoder * rtP.Counts_Radians_Gain;
  }
}

/* Update for root system: '<Root>' */
void MdlUpdate(int_T tid)
{
}

/* Terminate for root system: '<Root>' */
void MdlTerminate(void)
{
  if(rtS != NULL) {

    /* Level2 S-Function Block: <Root>/Read Cart Encoder1 (pci1711FedEnc) */
    {
      SimStruct *rts = ssGetSFunction(rtS, 0);
      sfcnTerminate(rts);
    }

    /* Level2 S-Function Block: <Root>/Read Pendulum Encoder (pci1711FedEnc) */
    {
      SimStruct *rts = ssGetSFunction(rtS, 1);
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
  ssSetNumBlocks(rtS, 6);               /* Number of blocks */
  ssSetNumBlockIO(rtS, 4);              /* Number of block outputs */
  ssSetNumBlockParams(rtS, 26);         /* Sum of parameter "widths" */
}

/* Function to initialize sample times */
void MdlInitializeSampleTimes(void)
{
  /* task periods */
  ssSetSampleTime(rtS, 0, 0.001);
  ssSetSampleTime(rtS, 1, 0.01);

  /* task offsets */
  ssSetOffsetTime(rtS, 0, 0.0);
  ssSetOffsetTime(rtS, 1, 0.0);
}

/* Function to register the model */
SimStruct *IPtest(void)
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
      for (i = 0; i < 4; i++) {
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
  ssSetModelName(rtS, "IPtest");
  ssSetPath(rtS, "IPtest");

  ssSetTStart(rtS, 0.0);
  ssSetTFinal(rtS, 70.0);
  ssSetStepSize(rtS, 0.001);
  ssSetFixedStepSize(rtS, 0.001);

  ssSetChecksumVal(rtS, 0, 3988474959U);
  ssSetChecksumVal(rtS, 1, 1196956938U);
  ssSetChecksumVal(rtS, 2, 2467882105U);
  ssSetChecksumVal(rtS, 3, 2395496463U);

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

  ssSetNumSFunctions(rtS, 2);

  /* register each child */
  {
    static SimStruct childSFunctions[2];
    static SimStruct *childSFunctionPtrs[2];

    (void)memset((char_T *)&childSFunctions[0], 0, sizeof(childSFunctions));
    ssSetSFunctions(rtS, &childSFunctionPtrs[0]);
    {
      int_T i;

      for(i = 0; i < 2; i++) {
        ssSetSFunction(rtS, i, &childSFunctions[i]);
      }
    }

    /* Level2 S-Function Block: IPtest/<Root>/Read Cart Encoder1 (pci1711FedEnc) */
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
      ssSetPath(rts, "IPtest/Read Cart Encoder1");
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
      sfcnTsMap[0] = 0;

      /* set compiled values of dynamic vector attributes */

      ssSetNumNonsampledZCs(rts, 0);
      /* Update connectivity flags for each port */
      _ssSetOutputPortConnected(rts, 0, 1);
      _ssSetOutputPortBeingMerged(rts, 0, 0);
      /* Update the BufferDstPort flags for each input port */
    }

    /* Level2 S-Function Block: IPtest/<Root>/Read Pendulum Encoder (pci1711FedEnc) */
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
      ssSetPath(rts, "IPtest/Read Pendulum Encoder");
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
      sfcnTsMap[0] = 0;

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

