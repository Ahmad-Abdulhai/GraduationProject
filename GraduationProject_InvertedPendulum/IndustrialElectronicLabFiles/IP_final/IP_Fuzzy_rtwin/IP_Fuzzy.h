/*
 * IP_Fuzzy.h
 *
 * Real-Time Workshop code generation for Simulink model "IP_Fuzzy.mdl".
 *
 * Model Version                        : 1.89
 * Real-Time Workshop file version      : 5.0 $Date: 2002/05/30 19:21:33 $
 * Real-Time Workshop file generated on : Thu Apr 09 14:25:04 2009
 * TLC version                          : 5.0 (Jun 18 2002)
 * C source code generated on           : Thu Apr 09 14:25:04 2009
 */

#ifndef _RTW_HEADER_IP_Fuzzy_h_
# define _RTW_HEADER_IP_Fuzzy_h_

#ifndef _IP_Fuzzy_COMMON_INCLUDES_
# define _IP_Fuzzy_COMMON_INCLUDES_
#include <math.h>
#include <string.h>

#include "simstruc.h"
#include "rtlibsrc.h"
#include "dt_info.h"
#include "rtlooksrc.h"
#include "rtwintgt.h"

#endif                                  /* _IP_Fuzzy_COMMON_INCLUDES_ */

#include "IP_Fuzzy_types.h"

#define MODEL_NAME                      IP_Fuzzy
#define NSAMPLE_TIMES                   (3)                      /* Number of sample times */
#define NINPUTS                         (0)                      /* Number of model inputs */
#define NOUTPUTS                        (0)                      /* Number of model outputs */
#define NBLOCKIO                        (13)                     /* Number of data output port signals */
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
  real_T Desired_Position;              /* '<Root>/Step' */
  real_T Read_Pendulum_Encoder;         /* '<Root>/Read Pendulum Encoder' */
  real_T Pendulum_Position;             /* '<Root>/Counts->Radians' */
  real_T Sum1_a;                        /* '<S1>/Sum1' */
  real_T Look_Up_Table_n_D_a;           /* '<S4>/Look-Up Table (n-D)' */
  real_T Memory_a;                      /* '<S4>/Memory' */
  real_T Sum2_a;                        /* '<S1>/Sum2' */
  real_T Gain1_b;                       /* '<S5>/Gain1' */
  real_T Look_Up_Table_n_D_b;           /* '<S5>/Look-Up Table (n-D)' */
  real_T Memory_b;                      /* '<S5>/Memory' */
  real_T Saturation;                    /* '<S2>/Saturation' */
} BlockIO;

/* Block states (auto storage) for system: '<Root>' */
typedef struct D_Work_tag {
  real_T Memory_a_PreviousInput;        /* <S4>/Memory */
  real_T Memory_b_PreviousInput;        /* <S5>/Memory */
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
  } System_States3_PWORK;               /* '<Root>/System States3' */
  struct {
    void *LoggedData;
  } System_States1_PWORK;               /* '<Root>/System States1' */
  struct {
    void *LoggedData;
  } System_States_PWORK;                /* '<Root>/System States' */
  struct {
    void *LoggedData;
  } System_States2_PWORK;               /* '<Root>/System States2' */
  int_T Digital_To_Analog_Convert_IWORK; /* '<Root>/Digital To Analog Converter' */
  int_T Read_Cart_Encoder1_IWORK;       /* '<Root>/Read Cart Encoder1' */
  int_T Read_Pendulum_Encoder_IWORK;    /* '<Root>/Read Pendulum Encoder' */
} D_Work;

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
  real_T Constant1_Value;               /* Expression: pi
                                         * '<S1>/Constant1'
                                         */
  real_T Gain_a_Gain;                   /* Expression: -80/u1
                                         * '<S4>/Gain'
                                         */
  real_T Gain1_a_Gain;                  /* Expression: -40/u1
                                         * '<S4>/Gain1'
                                         */
  real_T Look_Up_Table_n_D_a_tableData[6561]; /* Expression: tableData
                                               * '<S4>/Look-Up Table (n-D)'
                                               */
  real_T Look_Up_Table_n_D_a_bp01Data[81]; /* Expression: bp1
                                            * '<S4>/Look-Up Table (n-D)'
                                            */
  real_T Look_Up_Table_n_D_a_bp02Data[81]; /* Expression: bp2
                                            * '<S4>/Look-Up Table (n-D)'
                                            */
  real_T Gain2_a_Gain;                  /* Expression: u1
                                         * '<S4>/Gain2'
                                         */
  real_T Memory_a_X0;                   /* Expression: 0
                                         * '<S4>/Memory'
                                         */
  real_T Gain_b_Gain;                   /* Expression: 35/u2
                                         * '<S5>/Gain'
                                         */
  real_T Gain1_b_Gain;                  /* Expression: 130/u2
                                         * '<S5>/Gain1'
                                         */
  real_T Look_Up_Table_n_D_b_tableData[6561]; /* Expression: tableData
                                               * '<S5>/Look-Up Table (n-D)'
                                               */
  real_T Look_Up_Table_n_D_b_bp01Data[81]; /* Expression: bp1
                                            * '<S5>/Look-Up Table (n-D)'
                                            */
  real_T Look_Up_Table_n_D_b_bp02Data[81]; /* Expression: bp2
                                            * '<S5>/Look-Up Table (n-D)'
                                            */
  real_T Gain2_b_Gain;                  /* Expression: u2
                                         * '<S5>/Gain2'
                                         */
  real_T Memory_b_X0;                   /* Expression: 0
                                         * '<S5>/Memory'
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
  int32_T Look_Up_Table_n_D_a_maxIndex[2]; /* Computed Parameter: maxIndex
                                            * '<S4>/Look-Up Table (n-D)'
                                            */
  int32_T Look_Up_Table_n_D_b_maxIndex[2]; /* Computed Parameter: maxIndex
                                            * '<S5>/Look-Up Table (n-D)'
                                            */
};

/* Simulation Structure */
extern SimStruct *const rtS;

extern Parameters rtP;                  /* parameters */

/* External data declarations for dependent source files */

/* non-finites */
extern real_T rtInf;
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
 * '<Root>' : IP_Fuzzy
 * '<S1>'   : IP_Fuzzy/Control Subsystem
 * '<S2>'   : IP_Fuzzy/Scaling and Safety
 * '<S3>'   : IP_Fuzzy/Control Subsystem/Controller
 * '<S4>'   : IP_Fuzzy/Control Subsystem/Controller/Subsystem1
 * '<S5>'   : IP_Fuzzy/Control Subsystem/Controller/Subsystem2
 */

#endif                                  /* _RTW_HEADER_IP_Fuzzy_h_ */
