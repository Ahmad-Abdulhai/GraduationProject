/*
 * IP2.h
 *
 * Real-Time Workshop code generation for Simulink model "IP2.mdl".
 *
 * Model Version                        : 1.76
 * Real-Time Workshop file version      : 5.0 $Date: 2002/05/30 19:21:33 $
 * Real-Time Workshop file generated on : Wed Apr 01 18:00:33 2009
 * TLC version                          : 5.0 (Jun 18 2002)
 * C source code generated on           : Wed Apr 01 18:00:33 2009
 */

#ifndef _RTW_HEADER_IP2_h_
# define _RTW_HEADER_IP2_h_

#ifndef _IP2_COMMON_INCLUDES_
# define _IP2_COMMON_INCLUDES_
#include <math.h>
#include <string.h>

#include "simstruc.h"
#include "rtlibsrc.h"
#include "dt_info.h"
#include "rtwintgt.h"

#endif                                  /* _IP2_COMMON_INCLUDES_ */

#include "IP2_types.h"

#define MODEL_NAME                      IP2
#define NSAMPLE_TIMES                   (3)                      /* Number of sample times */
#define NINPUTS                         (0)                      /* Number of model inputs */
#define NOUTPUTS                        (0)                      /* Number of model outputs */
#define NBLOCKIO                        (10)                     /* Number of data output port signals */
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
  real_T Read_Cart_Encoder1;            /* '<Root>/Read Cart Encoder1' */
  real_T Cart_Position;                 /* '<Root>/Counts->Meters' */
  real_T Desired_Position;              /* '<Root>/Step' */
  real_T Cart_Velocity;                 /* '<S1>/Cart Velocity Filter' */
  real_T Read_Pendulum_Encoder;         /* '<Root>/Read Pendulum Encoder' */
  real_T Pendulum_Position;             /* '<Root>/Counts->Radians' */
  real_T Pendulum_Velocity;             /* '<S1>/Pendulum Velocity  Filter' */
  real_T derCartPos;                    /* '<S1>/Cart Velocity' */
  real_T derPendPos;                    /* '<S1>/Pendulum Velocity' */
  real_T Saturation;                    /* '<S2>/Saturation' */
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
  } Pendulum_Velocity_RWORK;            /* '<S1>/Pendulum Velocity' */
  struct {
    void *LoggedData;
  } System_States_PWORK;                /* '<Root>/System States' */
  struct {
    void *LoggedData;
  } System_States1_PWORK;               /* '<Root>/System States1' */
  struct {
    void *LoggedData;
  } System_States2_PWORK;               /* '<Root>/System States2' */
  struct {
    void *LoggedData;
  } System_States3_PWORK;               /* '<Root>/System States3' */
  int_T Digital_To_Analog_Convert_IWORK; /* '<Root>/Digital To Analog Converter' */
  int_T Read_Cart_Encoder1_IWORK;       /* '<Root>/Read Cart Encoder1' */
  int_T Read_Pendulum_Encoder_IWORK;    /* '<Root>/Read Pendulum Encoder' */
} D_Work;

/* Continuous states (auto storage) */
typedef struct _ContinuousStates {
  real_T Cart_Velocity_Filter_CSTATE[2]; /* '<S1>/Cart Velocity Filter' */
  real_T Pendulum_Velocity_Filter_CSTATE[2]; /* '<S1>/Pendulum Velocity  Filter' */
} ContinuousStates;

/* State derivatives (auto storage) */
typedef struct _StateDerivatives {
  real_T Cart_Velocity_Filter_CSTATE[2]; /* '<S1>/Cart Velocity Filter' */
  real_T Pendulum_Velocity_Filter_CSTATE[2]; /* '<S1>/Pendulum Velocity  Filter' */
} StateDerivatives;

/* State disabled  */
typedef struct _StateDisabled {
  boolean_T Cart_Velocity_Filter_CSTATE[2]; /* '<S1>/Cart Velocity Filter' */
  boolean_T Pendulum_Velocity_Filter_CSTATE[2]; /* '<S1>/Pendulum Velocity  Filter' */
} StateDisabled;

/* Parameters (auto storage) */
struct _Parameters {
  real_T Digital_To_Analog_Convert_P1_Si[2]; /* Computed Parameter: P1Size
                                              * '<Root>/Digital To Analog Converter'
                                              */
  real_T Digital_To_Analog_Convert_P1; /* Expression: channel
                                        * '<Root>/Digital To Analog Converter'
                                        */
  real_T Digital_To_Analog_Convert_P2_Si[2]; /* Computed Parameter: P2Size
                                              * '<Root>/Digital To Analog Converter'
                                              */
  real_T Digital_To_Analog_Convert_P2; /* Expression: range
                                        * '<Root>/Digital To Analog Converter'
                                        */
  real_T Digital_To_Analog_Convert_P3_Si[2]; /* Computed Parameter: P3Size
                                              * '<Root>/Digital To Analog Converter'
                                              */
  real_T Digital_To_Analog_Convert_P3; /* Expression: tsamp
                                        * '<Root>/Digital To Analog Converter'
                                        */
  real_T Digital_To_Analog_Convert_P4_Si[2]; /* Computed Parameter: P4Size
                                              * '<Root>/Digital To Analog Converter'
                                              */
  real_T Digital_To_Analog_Convert_P4; /* Expression: hwAccess
                                        * '<Root>/Digital To Analog Converter'
                                        */
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
  real_T Step_Time;                     /* Expression: 20
                                         * '<Root>/Step'
                                         */
  real_T Step_Y0;                       /* Expression: 0
                                         * '<Root>/Step'
                                         */
  real_T Step_YFinal;                   /* Expression: 0.2
                                         * '<Root>/Step'
                                         */
  real_T Cart_Velocity_Filter_A[2];     /* Computed Parameter: A
                                         * '<S1>/Cart Velocity Filter'
                                         */
  real_T Cart_Velocity_Filter_C[2];     /* Computed Parameter: C
                                         * '<S1>/Cart Velocity Filter'
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
  real_T Pendulum_Velocity_Filter_A[2]; /* Computed Parameter: A
                                         * '<S1>/Pendulum Velocity  Filter'
                                         */
  real_T Pendulum_Velocity_Filter_C[2]; /* Computed Parameter: C
                                         * '<S1>/Pendulum Velocity  Filter'
                                         */
  real_T Constant1_Value;               /* Expression: pi
                                         * '<S1>/Constant1'
                                         */
  real_T Constant2_Value;               /* Expression: 0
                                         * '<S1>/Constant2'
                                         */
  real_T Constant3_Value;               /* Expression: 0
                                         * '<S1>/Constant3'
                                         */
  real_T Scaling_Gain;                  /* Expression: 1
                                         * '<S2>/Scaling'
                                         */
  real_T Saturation_UpperSat;           /* Expression: 2.5
                                         * '<S2>/Saturation'
                                         */
  real_T Saturation_LowerSat;           /* Expression: -2.5
                                         * '<S2>/Saturation'
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
 * '<Root>' : IP2
 * '<S1>'   : IP2/Control Subsystem
 * '<S2>'   : IP2/Scaling and Safety
 * '<S3>'   : IP2/Control Subsystem/Controller
 * '<S4>'   : IP2/Control Subsystem/Controller/Linear cart controller
 * '<S5>'   : IP2/Control Subsystem/Controller/Linear pendulum controller
 */

#endif                                  /* _RTW_HEADER_IP2_h_ */
