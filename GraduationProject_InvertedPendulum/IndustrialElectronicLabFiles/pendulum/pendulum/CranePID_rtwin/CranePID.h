/*
 * CranePID.h
 *
 * Real-Time Workshop code generation for Simulink model "CranePID.mdl".
 *
 * Model Version                        : 1.60
 * Real-Time Workshop file version      : 5.0 $Date: 2002/05/30 19:21:33 $
 * Real-Time Workshop file generated on : Wed Apr 01 15:07:26 2009
 * TLC version                          : 5.0 (Jun 18 2002)
 * C source code generated on           : Wed Apr 01 15:07:26 2009
 */

#ifndef _RTW_HEADER_CranePID_h_
# define _RTW_HEADER_CranePID_h_

#ifndef _CranePID_COMMON_INCLUDES_
# define _CranePID_COMMON_INCLUDES_
#include <math.h>
#include <string.h>

#include "simstruc.h"
#include "rtlibsrc.h"
#include "dt_info.h"
#include "rtwintgt.h"

#endif                                  /* _CranePID_COMMON_INCLUDES_ */

#include "CranePID_types.h"

#define MODEL_NAME                      CranePID
#define NSAMPLE_TIMES                   (4)                      /* Number of sample times */
#define NINPUTS                         (0)                      /* Number of model inputs */
#define NOUTPUTS                        (0)                      /* Number of model outputs */
#define NBLOCKIO                        (16)                     /* Number of data output port signals */
#define NUM_ZC_EVENTS                   (0)                      /* Number of zero-crossing events */

#ifndef NCSTATES
# define NCSTATES (8)                   /* Number of continuous states */
#elif NCSTATES != 8
# error Invalid specification of NCSTATES defined in compiler command
#endif

/* Intrinsic types */
#ifndef POINTER_T
# define POINTER_T
typedef void * pointer_T;
#endif

/* Block signals (auto storage) */
typedef struct _BlockIO {
  real_T Desired_Position;              /* '<Root>/Desired Position Input' */
  real_T Read_Cart_Encoder;             /* '<Root>/Read Cart Encoder' */
  real_T actual_CartPosition;           /* '<Root>/Counts->Meters' */
  real_T Sum2;                          /* '<S1>/Sum2' */
  real_T Read_Pendulum_Encoder;         /* '<Root>/Read Pendulum Encoder' */
  real_T Sum3;                          /* '<S1>/Sum3' */
  real_T Proportional_b;                /* '<S5>/Proportional' */
  real_T Saturation;                    /* '<S2>/Saturation' */
  real_T Pendulum_Angle_Deviation_from_E; /* '<S1>/Plot Scaling' */
  real_T derPendPos;                    /* '<S1>/Cart Velocity' */
  real_T D_a;                           /* '<S4>/D' */
  real_T Derivative_a;                  /* '<S4>/Derivative' */
  real_T D_b;                           /* '<S5>/D' */
  real_T Derivative_b;                  /* '<S5>/Derivative' */
  real_T Gain3;                         /* '<S3>/Gain3' */
  real_T Gain2;                         /* '<S3>/Gain2' */
} BlockIO;

/* Block states (auto storage) for system: '<Root>' */
typedef struct D_Work_tag {
  struct {
    real_T TimeStampA;
    real_T LastUAtTimeA;
    real_T TimeStampB;
    real_T LastUAtTimeB;
  } Cart_Velocity_RWORK;                /* '<S1>/Cart Velocity' */
  struct {
    real_T TimeStampA;
    real_T LastUAtTimeA;
    real_T TimeStampB;
    real_T LastUAtTimeB;
  } Derivative_a_RWORK;                 /* '<S4>/Derivative' */
  struct {
    real_T TimeStampA;
    real_T LastUAtTimeA;
    real_T TimeStampB;
    real_T LastUAtTimeB;
  } Derivative_b_RWORK;                 /* '<S5>/Derivative' */
  struct {
    void *LoggedData;
  } Scope_PWORK;                        /* '<Root>/Scope' */
  struct {
    void *LoggedData;
  } See_Desired_Position_inpu_PWORK;    /* '<Root>/See Desired Position input' */
  int_T Digital_To_Analog_Convert_IWORK; /* '<Root>/Digital To Analog Converter ' */
  int_T Read_Cart_Encoder_IWORK;        /* '<Root>/Read Cart Encoder' */
  int_T Read_Pendulum_Encoder_IWORK;    /* '<Root>/Read Pendulum Encoder' */
} D_Work;

/* Continuous states (auto storage) */
typedef struct _ContinuousStates {
  real_T Integral_a_CSTATE;             /* '<S4>/Integral' */
  real_T Cart_Velocity_Filter1_CSTATE[2]; /* '<S4>/Cart Velocity  Filter1' */
  real_T Integral_b_CSTATE;             /* '<S5>/Integral' */
  real_T Pendulum_Velocity_Filter_CSTATE[2]; /* '<S5>/Pendulum Velocity  Filter' */
  real_T Cart_Velocity_Filter_CSTATE[2]; /* '<S1>/Cart Velocity  Filter' */
} ContinuousStates;

/* State derivatives (auto storage) */
typedef struct _StateDerivatives {
  real_T Integral_a_CSTATE;             /* '<S4>/Integral' */
  real_T Cart_Velocity_Filter1_CSTATE[2]; /* '<S4>/Cart Velocity  Filter1' */
  real_T Integral_b_CSTATE;             /* '<S5>/Integral' */
  real_T Pendulum_Velocity_Filter_CSTATE[2]; /* '<S5>/Pendulum Velocity  Filter' */
  real_T Cart_Velocity_Filter_CSTATE[2]; /* '<S1>/Cart Velocity  Filter' */
} StateDerivatives;

/* State disabled  */
typedef struct _StateDisabled {
  boolean_T Integral_a_CSTATE;          /* '<S4>/Integral' */
  boolean_T Cart_Velocity_Filter1_CSTATE[2]; /* '<S4>/Cart Velocity  Filter1' */
  boolean_T Integral_b_CSTATE;          /* '<S5>/Integral' */
  boolean_T Pendulum_Velocity_Filter_CSTATE[2]; /* '<S5>/Pendulum Velocity  Filter' */
  boolean_T Cart_Velocity_Filter_CSTATE[2]; /* '<S1>/Cart Velocity  Filter' */
} StateDisabled;

/* Parameters (auto storage) */
struct _Parameters {
  real_T Digital_To_Analog_Convert_P1_Si[2]; /* Computed Parameter: P1Size
                                              * '<Root>/Digital To Analog Converter '
                                              */
  real_T Digital_To_Analog_Convert_P1; /* Expression: channel
                                        * '<Root>/Digital To Analog Converter '
                                        */
  real_T Digital_To_Analog_Convert_P2_Si[2]; /* Computed Parameter: P2Size
                                              * '<Root>/Digital To Analog Converter '
                                              */
  real_T Digital_To_Analog_Convert_P2; /* Expression: range
                                        * '<Root>/Digital To Analog Converter '
                                        */
  real_T Digital_To_Analog_Convert_P3_Si[2]; /* Computed Parameter: P3Size
                                              * '<Root>/Digital To Analog Converter '
                                              */
  real_T Digital_To_Analog_Convert_P3; /* Expression: tsamp
                                        * '<Root>/Digital To Analog Converter '
                                        */
  real_T Digital_To_Analog_Convert_P4_Si[2]; /* Computed Parameter: P4Size
                                              * '<Root>/Digital To Analog Converter '
                                              */
  real_T Digital_To_Analog_Convert_P4; /* Expression: hwAccess
                                        * '<Root>/Digital To Analog Converter '
                                        */
  real_T Desired_Position_Input_Amp;    /* Expression: 0.2
                                         * '<Root>/Desired Position Input'
                                         */
  real_T Desired_Position_Input_Bias;   /* Expression: 0
                                         * '<Root>/Desired Position Input'
                                         */
  real_T Desired_Position_Input_Freq;   /* Expression: 5
                                         * '<Root>/Desired Position Input'
                                         */
  real_T Desired_Position_Input_Phase; /* Expression: 0
                                        * '<Root>/Desired Position Input'
                                        */
  real_T Read_Cart_Encoder_P1_Size[2]; /* Computed Parameter: P1Size
                                        * '<Root>/Read Cart Encoder'
                                        */
  real_T Read_Cart_Encoder_P1;          /* Expression: channel
                                         * '<Root>/Read Cart Encoder'
                                         */
  real_T Read_Cart_Encoder_P2_Size[2]; /* Computed Parameter: P2Size
                                        * '<Root>/Read Cart Encoder'
                                        */
  real_T Read_Cart_Encoder_P2;          /* Expression: offset
                                         * '<Root>/Read Cart Encoder'
                                         */
  real_T Read_Cart_Encoder_P3_Size[2]; /* Computed Parameter: P3Size
                                        * '<Root>/Read Cart Encoder'
                                        */
  real_T Read_Cart_Encoder_P3;          /* Expression: tsamp
                                         * '<Root>/Read Cart Encoder'
                                         */
  real_T Read_Cart_Encoder_P4_Size[2]; /* Computed Parameter: P4Size
                                        * '<Root>/Read Cart Encoder'
                                        */
  real_T Read_Cart_Encoder_P4;          /* Expression: hwAccess
                                         * '<Root>/Read Cart Encoder'
                                         */
  real_T Counts_Meters_Gain;            /* Expression: .156/2048
                                         * '<Root>/Counts->Meters'
                                         */
  real_T Proportional_a_Gain;           /* Expression: P
                                         * '<S4>/Proportional'
                                         */
  real_T Integral_a_A;                  /* Computed Parameter: A
                                         * '<S4>/Integral'
                                         */
  real_T Integral_a_C;                  /* Computed Parameter: C
                                         * '<S4>/Integral'
                                         */
  real_T Cart_Velocity_Filter1_A[2];    /* Computed Parameter: A
                                         * '<S4>/Cart Velocity  Filter1'
                                         */
  real_T Cart_Velocity_Filter1_C[2];    /* Computed Parameter: C
                                         * '<S4>/Cart Velocity  Filter1'
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
  real_T s7_Value;                      /* Expression: pi
                                         * '<S1>/s7'
                                         */
  real_T Proportional_b_Gain;           /* Expression: P
                                         * '<S5>/Proportional'
                                         */
  real_T Integral_b_A;                  /* Computed Parameter: A
                                         * '<S5>/Integral'
                                         */
  real_T Integral_b_C;                  /* Computed Parameter: C
                                         * '<S5>/Integral'
                                         */
  real_T Pendulum_Velocity_Filter_A[2]; /* Computed Parameter: A
                                         * '<S5>/Pendulum Velocity  Filter'
                                         */
  real_T Pendulum_Velocity_Filter_C[2]; /* Computed Parameter: C
                                         * '<S5>/Pendulum Velocity  Filter'
                                         */
  real_T Cart_Velocity_Filter_A[2];     /* Computed Parameter: A
                                         * '<S1>/Cart Velocity  Filter'
                                         */
  real_T Cart_Velocity_Filter_C[2];     /* Computed Parameter: C
                                         * '<S1>/Cart Velocity  Filter'
                                         */
  real_T id_Threshold;                  /* Expression: 0
                                         * '<S3>/3'
                                         */
  real_T Gain_Gain;                     /* Expression: 1
                                         * '<S2>/Gain'
                                         */
  real_T Saturation_UpperSat;           /* Expression: 2.5
                                         * '<S2>/Saturation'
                                         */
  real_T Saturation_LowerSat;           /* Expression: -2.5
                                         * '<S2>/Saturation'
                                         */
  real_T Plot_Scaling_Gain;             /* Expression: -1
                                         * '<S1>/Plot Scaling'
                                         */
  real_T D_a_Gain;                      /* Expression: D
                                         * '<S4>/D'
                                         */
  real_T D_b_Gain;                      /* Expression: D
                                         * '<S5>/D'
                                         */
  real_T Gain2_Gain;                    /* Expression: frictionCompPos
                                         * '<S3>/Gain2'
                                         */
  real_T Gain3_Gain;                    /* Expression: frictionCompNeg
                                         * '<S3>/Gain3'
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
 * '<Root>' : CranePID
 * '<S1>'   : CranePID/Control Subsystem
 * '<S2>'   : CranePID/Scaling and Safety
 * '<S3>'   : CranePID/Control Subsystem/Friction Compensation
 * '<S4>'   : CranePID/Control Subsystem/PID Cart  Controller
 * '<S5>'   : CranePID/Control Subsystem/PID Pendulum   Controller
 */

#endif                                  /* _RTW_HEADER_CranePID_h_ */
