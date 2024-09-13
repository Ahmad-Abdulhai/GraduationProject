/*
 * IP.h
 *
 * Real-Time Workshop code generation for Simulink model "IP.mdl".
 *
 * Model Version                        : 1.2
 * Real-Time Workshop file version      : 5.0 $Date: 2002/05/30 19:21:33 $
 * Real-Time Workshop file generated on : Mon Mar 16 17:07:54 2009
 * TLC version                          : 5.0 (Jun 18 2002)
 * C source code generated on           : Mon Mar 16 17:07:54 2009
 */

#ifndef _RTW_HEADER_IP_h_
# define _RTW_HEADER_IP_h_

#ifndef _IP_COMMON_INCLUDES_
# define _IP_COMMON_INCLUDES_
#include <math.h>
#include <string.h>

#include "simstruc.h"
#include "rtlibsrc.h"

#endif                                  /* _IP_COMMON_INCLUDES_ */

#include "IP_types.h"

#define MODEL_NAME                      IP
#define NSAMPLE_TIMES                   (2)                      /* Number of sample times */
#define NINPUTS                         (0)                      /* Number of model inputs */
#define NOUTPUTS                        (0)                      /* Number of model outputs */
#define NBLOCKIO                        (5)                      /* Number of data output port signals */
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
  real_T Clock;                         /* '<Root>/Clock' */
  real_T Sum;                           /* '<Root>/Sum' */
  real_T Read_Cart_Encoder1;            /* '<S1>/Read Cart Encoder1' */
  real_T Read_Pendulum_Encoder;         /* '<S1>/Read Pendulum Encoder' */
  real_T Saturation;                    /* '<S2>/Saturation' */
} BlockIO;

/* Block states (auto storage) for system: '<Root>' */
typedef struct D_Work_tag {
  struct {
    void *LoggedData;
  } Scope_PWORK;                        /* '<Root>/Scope' */
  int_T Read_Cart_Encoder1_IWORK;       /* '<S1>/Read Cart Encoder1' */
  int_T Read_Pendulum_Encoder_IWORK;    /* '<S1>/Read Pendulum Encoder' */
  int_T Digital_To_Analog_Convert_IWORK; /* '<S1>/Digital To Analog Converter' */
} D_Work;

/* Parameters (auto storage) */
struct _Parameters {
  real_T pooled1[2];                    /* Computed Parameter: P1Size
                                         * Referenced by blocks:
                                         * '<S1>/Read Cart Encoder1'
                                         * '<S1>/Read Cart Encoder1'
                                         * '<S1>/Digital To Analog Converter'
                                         * '<S1>/Digital To Analog Converter'
                                         */
  real_T pooled2;                       /* Expression: 0
                                         * Referenced by blocks:
                                         * '<Root>/Step'
                                         * '<Root>/Step1'
                                         * '<S1>/Read Cart Encoder1'
                                         * '<S1>/Read Cart Encoder1'
                                         * '<S1>/Digital To Analog Converter'
                                         * '<S1>/Digital To Analog Converter'
                                         */
  real_T pooled3[2];                    /* Computed Parameter: P3Size
                                         * Referenced by blocks:
                                         * '<S1>/Read Cart Encoder1'
                                         * '<S1>/Read Pendulum Encoder'
                                         * '<S1>/Digital To Analog Converter'
                                         */
  real_T pooled4;                       /* Expression: tsamp
                                         * Referenced by blocks:
                                         * '<S1>/Read Cart Encoder1'
                                         * '<S1>/Read Pendulum Encoder'
                                         * '<S1>/Digital To Analog Converter'
                                         */
  real_T pooled5[2];                    /* Computed Parameter: P4Size
                                         * Referenced by blocks:
                                         * '<S1>/Read Cart Encoder1'
                                         * '<S1>/Read Pendulum Encoder'
                                         * '<S1>/Read Pendulum Encoder'
                                         * '<S1>/Digital To Analog Converter'
                                         */
  real_T pooled6;                       /* Expression: hwAccess
                                         * Referenced by blocks:
                                         * '<S1>/Read Cart Encoder1'
                                         * '<S1>/Read Pendulum Encoder'
                                         * '<S1>/Read Pendulum Encoder'
                                         * '<S1>/Digital To Analog Converter'
                                         */
  real_T Read_Pendulum_Encoder_P2_Size[2]; /* Computed Parameter: P2Size
                                            * '<S1>/Read Pendulum Encoder'
                                            */
  real_T Read_Pendulum_Encoder_P2;      /* Expression: offset
                                         * '<S1>/Read Pendulum Encoder'
                                         */
};

/* Simulation Structure */
extern SimStruct *const rtS;

extern Parameters rtP;                  /* parameters */

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
 * '<Root>' : IP
 * '<S1>'   : IP/IP
 * '<S2>'   : IP/IP/Scaling and Safety
 */

#endif                                  /* _RTW_HEADER_IP_h_ */
