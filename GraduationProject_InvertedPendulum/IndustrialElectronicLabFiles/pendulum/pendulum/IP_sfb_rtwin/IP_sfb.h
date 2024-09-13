/*
 * IP_sfb.h
 *
 * Real-Time Workshop code generation for Simulink model "IP_sfb.mdl".
 *
 * Model Version                        : 1.125
 * Real-Time Workshop file version      : 5.0 $Date: 2002/05/30 19:21:33 $
 * Real-Time Workshop file generated on : Mon Mar 30 16:20:29 2009
 * TLC version                          : 5.0 (Jun 18 2002)
 * C source code generated on           : Mon Mar 30 16:20:30 2009
 */

#ifndef _RTW_HEADER_IP_sfb_h_
# define _RTW_HEADER_IP_sfb_h_

#ifndef _IP_sfb_COMMON_INCLUDES_
# define _IP_sfb_COMMON_INCLUDES_
#include <math.h>
#include <string.h>

#include "simstruc.h"
#include "rtlibsrc.h"
#include "dt_info.h"
#include "rtwintgt.h"

#endif                                  /* _IP_sfb_COMMON_INCLUDES_ */

#include "IP_sfb_types.h"

#define MODEL_NAME                      IP_sfb
#define NSAMPLE_TIMES                   (3)                      /* Number of sample times */
#define NINPUTS                         (0)                      /* Number of model inputs */
#define NOUTPUTS                        (0)                      /* Number of model outputs */
#define NBLOCKIO                        (8)                      /* Number of data output port signals */
#define NUM_ZC_EVENTS                   (0)                      /* Number of zero-crossing events */

#ifndef NCSTATES
# define NCSTATES (4)                   /* Number of continuous states */
#elif NCSTATES != 4
# error Invalid specification of NCSTATES defined in compiler command
#endif

/* Intrinsic types */
#ifndef POINTER_T
# define POINTER_T
typedef void * pointer_T;
#endif

/* Block signals (auto storage) */
typedef struct _BlockIO {
  real_T Read_Cart_Encoder1;            /* '<S1>/Read Cart Encoder1' */
  real_T Cart_Position;                 /* '<S1>/Counts->Meters' */
  real_T Read_Pendulum_Encoder;         /* '<S1>/Read Pendulum Encoder' */
  real_T Pendulum_Position;             /* '<S1>/Counts->Radians' */
  real_T Matrix_Gain;                   /* '<Root>/Matrix Gain' */
  real_T Saturation;                    /* '<S3>/Saturation' */
  real_T Derivative2;                   /* '<S2>/Derivative2' */
  real_T Derivative1;                   /* '<S2>/Derivative1' */
} BlockIO;

/* Block states (auto storage) for system: '<Root>' */
typedef struct D_Work_tag {
  struct {
    real_T TimeStampA;
    real_T LastUAtTimeA;
    real_T TimeStampB;
    real_T LastUAtTimeB;
  } Derivative2_RWORK;                  /* '<S2>/Derivative2' */
  struct {
    real_T TimeStampA;
    real_T LastUAtTimeA;
    real_T TimeStampB;
    real_T LastUAtTimeB;
  } Derivative1_RWORK;                  /* '<S2>/Derivative1' */
  struct {
    void *LoggedData;
  } Scope_PWORK;                        /* '<Root>/Scope' */
  int_T Read_Cart_Encoder1_IWORK;       /* '<S1>/Read Cart Encoder1' */
  int_T Read_Pendulum_Encoder_IWORK;    /* '<S1>/Read Pendulum Encoder' */
  int_T Digital_To_Analog_Convert_IWORK; /* '<S1>/Digital To Analog Converter' */
} D_Work;

/* Continuous states (auto storage) */
typedef struct _ContinuousStates {
  real_T Pendulum_Velocity_Filter_CSTATE[2]; /* '<S2>/Pendulum Velocity  Filter' */
  real_T Cart_Velocity_Filter_CSTATE[2]; /* '<S2>/Cart Velocity Filter' */
} ContinuousStates;

/* State derivatives (auto storage) */
typedef struct _StateDerivatives {
  real_T Pendulum_Velocity_Filter_CSTATE[2]; /* '<S2>/Pendulum Velocity  Filter' */
  real_T Cart_Velocity_Filter_CSTATE[2]; /* '<S2>/Cart Velocity Filter' */
} StateDerivatives;

/* State disabled  */
typedef struct _StateDisabled {
  boolean_T Pendulum_Velocity_Filter_CSTATE[2]; /* '<S2>/Pendulum Velocity  Filter' */
  boolean_T Cart_Velocity_Filter_CSTATE[2]; /* '<S2>/Cart Velocity Filter' */
} StateDisabled;

/* Parameters (auto storage) */
struct _Parameters {
  real_T Read_Cart_Encoder1_P1_Size[2]; /* Computed Parameter: P1Size
                                         * '<S1>/Read Cart Encoder1'
                                         */
  real_T Read_Cart_Encoder1_P1;         /* Expression: channel
                                         * '<S1>/Read Cart Encoder1'
                                         */
  real_T Read_Cart_Encoder1_P2_Size[2]; /* Computed Parameter: P2Size
                                         * '<S1>/Read Cart Encoder1'
                                         */
  real_T Read_Cart_Encoder1_P2;         /* Expression: offset
                                         * '<S1>/Read Cart Encoder1'
                                         */
  real_T Read_Cart_Encoder1_P3_Size[2]; /* Computed Parameter: P3Size
                                         * '<S1>/Read Cart Encoder1'
                                         */
  real_T Read_Cart_Encoder1_P3;         /* Expression: tsamp
                                         * '<S1>/Read Cart Encoder1'
                                         */
  real_T Read_Cart_Encoder1_P4_Size[2]; /* Computed Parameter: P4Size
                                         * '<S1>/Read Cart Encoder1'
                                         */
  real_T Read_Cart_Encoder1_P4;         /* Expression: hwAccess
                                         * '<S1>/Read Cart Encoder1'
                                         */
  real_T Counts_Meters_Gain;            /* Expression: .156/2048
                                         * '<S1>/Counts->Meters'
                                         */
  real_T Read_Pendulum_Encoder_P1_Size[2]; /* Computed Parameter: P1Size
                                            * '<S1>/Read Pendulum Encoder'
                                            */
  real_T Read_Pendulum_Encoder_P1;      /* Expression: channel
                                         * '<S1>/Read Pendulum Encoder'
                                         */
  real_T Read_Pendulum_Encoder_P2_Size[2]; /* Computed Parameter: P2Size
                                            * '<S1>/Read Pendulum Encoder'
                                            */
  real_T Read_Pendulum_Encoder_P2;      /* Expression: offset
                                         * '<S1>/Read Pendulum Encoder'
                                         */
  real_T Read_Pendulum_Encoder_P3_Size[2]; /* Computed Parameter: P3Size
                                            * '<S1>/Read Pendulum Encoder'
                                            */
  real_T Read_Pendulum_Encoder_P3;      /* Expression: tsamp
                                         * '<S1>/Read Pendulum Encoder'
                                         */
  real_T Read_Pendulum_Encoder_P4_Size[2]; /* Computed Parameter: P4Size
                                            * '<S1>/Read Pendulum Encoder'
                                            */
  real_T Read_Pendulum_Encoder_P4;      /* Expression: hwAccess
                                         * '<S1>/Read Pendulum Encoder'
                                         */
  real_T Counts_Radians_Gain;           /* Expression: -2*pi/2048
                                         * '<S1>/Counts->Radians'
                                         */
  real_T Pendulum_Velocity_Filter_A[2]; /* Computed Parameter: A
                                         * '<S2>/Pendulum Velocity  Filter'
                                         */
  real_T Pendulum_Velocity_Filter_C[2]; /* Computed Parameter: C
                                         * '<S2>/Pendulum Velocity  Filter'
                                         */
  real_T Cart_Velocity_Filter_A[2];     /* Computed Parameter: A
                                         * '<S2>/Cart Velocity Filter'
                                         */
  real_T Cart_Velocity_Filter_C[2];     /* Computed Parameter: C
                                         * '<S2>/Cart Velocity Filter'
                                         */
  real_T Step_Time;                     /* Expression: 20
                                         * '<Root>/Step'
                                         */
  real_T Step_Y0;                       /* Expression: 0
                                         * '<Root>/Step'
                                         */
  real_T Step_YFinal;                   /* Expression: 0.2
                                         * '<Root>/Step'
                                         */
  real_T Constant_Value;                /* Expression: pi
                                         * '<Root>/Constant'
                                         */
  real_T Constant1_Value;               /* Expression: 0
                                         * '<Root>/Constant1'
                                         */
  real_T Constant2_Value;               /* Expression: 0
                                         * '<Root>/Constant2'
                                         */
  real_T Matrix_Gain_Gain[4];           /* Expression: K
                                         * '<Root>/Matrix Gain'
                                         */
  real_T Digital_To_Analog_Convert_P1_Si[2]; /* Computed Parameter: P1Size
                                              * '<S1>/Digital To Analog Converter'
                                              */
  real_T Digital_To_Analog_Convert_P1; /* Expression: channel
                                        * '<S1>/Digital To Analog Converter'
                                        */
  real_T Digital_To_Analog_Convert_P2_Si[2]; /* Computed Parameter: P2Size
                                              * '<S1>/Digital To Analog Converter'
                                              */
  real_T Digital_To_Analog_Convert_P2; /* Expression: range
                                        * '<S1>/Digital To Analog Converter'
                                        */
  real_T Digital_To_Analog_Convert_P3_Si[2]; /* Computed Parameter: P3Size
                                              * '<S1>/Digital To Analog Converter'
                                              */
  real_T Digital_To_Analog_Convert_P3; /* Expression: tsamp
                                        * '<S1>/Digital To Analog Converter'
                                        */
  real_T Digital_To_Analog_Convert_P4_Si[2]; /* Computed Parameter: P4Size
                                              * '<S1>/Digital To Analog Converter'
                                              */
  real_T Digital_To_Analog_Convert_P4; /* Expression: hwAccess
                                        * '<S1>/Digital To Analog Converter'
                                        */
  real_T Scaling_Gain;                  /* Expression: 1
                                         * '<S3>/Scaling'
                                         */
  real_T Saturation_UpperSat;           /* Expression: 2.5
                                         * '<S3>/Saturation'
                                         */
  real_T Saturation_LowerSat;           /* Expression: -2.5
                                         * '<S3>/Saturation'
                                         */
};

/* Simulation Structure */
extern SimStruct *const rtS;

extern Parameters rtP;                  /* parameters */

/* External data declarations for dependent source files */

/* non-finites */
extern real_T rtInf;
extern BlockIO rtB;                     /* block i/o */
extern ContinuousStates rtX;            /* continuous states */
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
 * '<Root>' : IP_sfb
 * '<S1>'   : IP_sfb/IP
 * '<S2>'   : IP_sfb/Subsystem
 * '<S3>'   : IP_sfb/IP/Scaling and Safety
 */

#endif                                  /* _RTW_HEADER_IP_sfb_h_ */
