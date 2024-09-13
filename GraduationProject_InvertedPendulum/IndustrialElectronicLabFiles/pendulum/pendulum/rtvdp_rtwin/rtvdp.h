/*
 * rtvdp.h
 *
 * Real-Time Workshop code generation for Simulink model "rtvdp.mdl".
 *
 * Model Version                        : 1.9
 * Real-Time Workshop file version      : 5.0 $Date: 2002/05/30 19:21:33 $
 * Real-Time Workshop file generated on : Sat Mar 14 23:10:17 2009
 * TLC version                          : 5.0 (Jun 18 2002)
 * C source code generated on           : Sat Mar 14 23:10:17 2009
 */

#ifndef _RTW_HEADER_rtvdp_h_
# define _RTW_HEADER_rtvdp_h_

#ifndef _rtvdp_COMMON_INCLUDES_
# define _rtvdp_COMMON_INCLUDES_
#include <math.h>
#include <string.h>

#include "simstruc.h"
#include "rtlibsrc.h"
#include "dt_info.h"
#include "rtwintgt.h"

#endif                                  /* _rtvdp_COMMON_INCLUDES_ */

#include "rtvdp_types.h"

#define MODEL_NAME                      rtvdp
#define NSAMPLE_TIMES                   (2)                      /* Number of sample times */
#define NINPUTS                         (0)                      /* Number of model inputs */
#define NOUTPUTS                        (2)                      /* Number of model outputs */
#define NBLOCKIO                        (4)                      /* Number of data output port signals */
#define NUM_ZC_EVENTS                   (0)                      /* Number of zero-crossing events */

#ifndef NCSTATES
# define NCSTATES (2)                   /* Number of continuous states */
#elif NCSTATES != 2
# error Invalid specification of NCSTATES defined in compiler command
#endif

/* Intrinsic types */
#ifndef POINTER_T
# define POINTER_T
typedef void * pointer_T;
#endif

/* Block signals (auto storage) */
typedef struct _BlockIO {
  real_T x1;                            /* '<Root>/Integrator1' */
  real_T x2;                            /* '<Root>/Integrator2' */
  real_T Saturation[2];                 /* '<Root>/Saturation' */
  real_T Sum;                           /* '<Root>/Sum' */
} BlockIO;

/* Block states (auto storage) for system: '<Root>' */
typedef struct D_Work_tag {
  struct {
    void *LoggedData;
  } Scope_PWORK;                        /* '<Root>/Scope' */
} D_Work;

/* Continuous states (auto storage) */
typedef struct _ContinuousStates {
  real_T Integrator1_CSTATE;            /* '<Root>/Integrator1' */
  real_T Integrator2_CSTATE;            /* '<Root>/Integrator2' */
} ContinuousStates;

/* State derivatives (auto storage) */
typedef struct _StateDerivatives {
  real_T Integrator1_CSTATE;            /* '<Root>/Integrator1' */
  real_T Integrator2_CSTATE;            /* '<Root>/Integrator2' */
} StateDerivatives;

/* State disabled  */
typedef struct _StateDisabled {
  boolean_T Integrator1_CSTATE;         /* '<Root>/Integrator1' */
  boolean_T Integrator2_CSTATE;         /* '<Root>/Integrator2' */
} StateDisabled;

/* Parameters (auto storage) */
struct _Parameters {
  real_T Integrator1_IC;                /* Expression: 2
                                         * '<Root>/Integrator1'
                                         */
  real_T Integrator2_IC;                /* Expression: 0
                                         * '<Root>/Integrator2'
                                         */
  real_T Saturation_UpperSat;           /* Expression: 2
                                         * '<Root>/Saturation'
                                         */
  real_T Saturation_LowerSat;           /* Expression: -2
                                         * '<Root>/Saturation'
                                         */
  real_T Mu_Gain;                       /* Expression: 1
                                         * '<Root>/Mu'
                                         */
};

/* External outputs (root outports fed by signals with auto storage) */
typedef struct _ExternalOutputs_tag {
  real_T Out1;                          /* '<Root>/Out1' */
  real_T Out2;                          /* '<Root>/Out2' */
} ExternalOutputs;

/* Simulation Structure */
extern SimStruct *const rtS;

extern Parameters rtP;                  /* parameters */

/* External data declarations for dependent source files */

extern BlockIO rtB;                     /* block i/o */
extern ContinuousStates rtX;            /* continuous states */
extern D_Work rtDWork;                  /* data type work */
extern ExternalOutputs rtY;             /* external outputs */

/* 
 * The generated code includes comments that allow you to trace directly 
 * back to the appropriate location in the model.  The basic format
 * is <system>/block_name, where system is the system number (uniquely
 * assigned by Simulink) and block_name is the name of the block.
 *
 * Use the MATLAB hilite_system command to trace the generated code back
 * to the model.  For example,
 *
 * hilite_system('<S3>')    - opens system 3
 * hilite_system('<S3>/Kp') - opens and selects block Kp which resides in S3
 *
 * Here is the system hierarchy for this model
 *
 * '<Root>' : rtvdp
 */

#endif                                  /* _RTW_HEADER_rtvdp_h_ */
