/*
 * IPtest.h
 *
 * Real-Time Workshop code generation for Simulink model "IPtest.mdl".
 *
 * Model Version                        : 1.85
 * Real-Time Workshop file version      : 5.0 $Date: 2002/05/30 19:21:33 $
 * Real-Time Workshop file generated on : Thu Mar 29 02:31:21 2012
 * TLC version                          : 5.0 (Jun 18 2002)
 * C source code generated on           : Thu Mar 29 02:31:21 2012
 */

#ifndef _RTW_HEADER_IPtest_h_
# define _RTW_HEADER_IPtest_h_

#ifndef _IPtest_COMMON_INCLUDES_
# define _IPtest_COMMON_INCLUDES_
#include <math.h>
#include <string.h>

#include "simstruc.h"
#include "rtlibsrc.h"
#include "dt_info.h"
#include "rtwintgt.h"

#endif                                  /* _IPtest_COMMON_INCLUDES_ */

#include "IPtest_types.h"

#define MODEL_NAME                      IPtest
#define NSAMPLE_TIMES                   (2)                      /* Number of sample times */
#define NINPUTS                         (0)                      /* Number of model inputs */
#define NOUTPUTS                        (0)                      /* Number of model outputs */
#define NBLOCKIO                        (4)                      /* Number of data output port signals */
#define NUM_ZC_EVENTS                   (0)                      /* Number of zero-crossing events */

#ifndef NCSTATES
# define NCSTATES (0)                   /* Number of continuous states */
#elif NCSTATES != 0
# error Invalid specification of NCSTATES defined in compiler command
#endif

/* Intrinsic types */
#ifndef POINTER_T
# define POINTER_T
typedef void * pointer_T;
#endif

/* Block signals (auto storage) */
typedef struct _BlockIO {
  real_T Read_Cart_Encoder1;            /* '<Root>/Read Cart Encoder1' */
  real_T Cart_Position;                 /* '<Root>/Counts->Meters' */
  real_T Read_Pendulum_Encoder;         /* '<Root>/Read Pendulum Encoder' */
  real_T Pendulum_Position;             /* '<Root>/Counts->Radians' */
} BlockIO;

/* Block states (auto storage) for system: '<Root>' */
typedef struct D_Work_tag {
  struct {
    void *LoggedData;
  } System_States1_PWORK;               /* '<Root>/System States1' */
  struct {
    void *LoggedData;
  } System_States_PWORK;                /* '<Root>/System States' */
  int_T Read_Cart_Encoder1_IWORK;       /* '<Root>/Read Cart Encoder1' */
  int_T Read_Pendulum_Encoder_IWORK;    /* '<Root>/Read Pendulum Encoder' */
} D_Work;

/* Parameters (auto storage) */
struct _Parameters {
  real_T Read_Cart_Encoder1_P1_Size[2]; /* Computed Parameter: P1Size
                                         * '<Root>/Read Cart Encoder1'
                                         */
  real_T Read_Cart_Encoder1_P1;         /* Expression: channel
                                         * '<Root>/Read Cart Encoder1'
                                         */
  real_T Read_Cart_Encoder1_P2_Size[2]; /* Computed Parameter: P2Size
                                         * '<Root>/Read Cart Encoder1'
                                         */
  real_T Read_Cart_Encoder1_P2;         /* Expression: offset
                                         * '<Root>/Read Cart Encoder1'
                                         */
  real_T Read_Cart_Encoder1_P3_Size[2]; /* Computed Parameter: P3Size
                                         * '<Root>/Read Cart Encoder1'
                                         */
  real_T Read_Cart_Encoder1_P3;         /* Expression: tsamp
                                         * '<Root>/Read Cart Encoder1'
                                         */
  real_T Read_Cart_Encoder1_P4_Size[2]; /* Computed Parameter: P4Size
                                         * '<Root>/Read Cart Encoder1'
                                         */
  real_T Read_Cart_Encoder1_P4;         /* Expression: hwAccess
                                         * '<Root>/Read Cart Encoder1'
                                         */
  real_T Counts_Meters_Gain;            /* Expression: .156/2048
                                         * '<Root>/Counts->Meters'
                                         */
  real_T Read_Pendulum_Encoder_P1_Size[2]; /* Computed Parameter: P1Size
                                            * '<Root>/Read Pendulum Encoder'
                                            */
  real_T Read_Pendulum_Encoder_P1;      /* Expression: channel
                                         * '<Root>/Read Pendulum Encoder'
                                         */
  real_T Read_Pendulum_Encoder_P2_Size[2]; /* Computed Parameter: P2Size
                                            * '<Root>/Read Pendulum Encoder'
                                            */
  real_T Read_Pendulum_Encoder_P2;      /* Expression: offset
                                         * '<Root>/Read Pendulum Encoder'
                                         */
  real_T Read_Pendulum_Encoder_P3_Size[2]; /* Computed Parameter: P3Size
                                            * '<Root>/Read Pendulum Encoder'
                                            */
  real_T Read_Pendulum_Encoder_P3;      /* Expression: tsamp
                                         * '<Root>/Read Pendulum Encoder'
                                         */
  real_T Read_Pendulum_Encoder_P4_Size[2]; /* Computed Parameter: P4Size
                                            * '<Root>/Read Pendulum Encoder'
                                            */
  real_T Read_Pendulum_Encoder_P4;      /* Expression: hwAccess
                                         * '<Root>/Read Pendulum Encoder'
                                         */
  real_T Counts_Radians_Gain;           /* Expression: -2*pi/2048
                                         * '<Root>/Counts->Radians'
                                         */
};

/* Simulation Structure */
extern SimStruct *const rtS;

extern Parameters rtP;                  /* parameters */

/* External data declarations for dependent source files */

extern BlockIO rtB;                     /* block i/o */
extern D_Work rtDWork;                  /* data type work */

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
 * '<Root>' : IPtest
 */

#endif                                  /* _RTW_HEADER_IPtest_h_ */
