/*
 * CranePID_data.c
 *
 * Real-Time Workshop code generation for Simulink model "CranePID.mdl".
 *
 * Model Version                        : 1.60
 * Real-Time Workshop file version      : 5.0 $Date: 2002/05/30 19:21:33 $
 * Real-Time Workshop file generated on : Wed Apr 01 15:07:26 2009
 * TLC version                          : 5.0 (Jun 18 2002)
 * C source code generated on           : Wed Apr 01 15:07:26 2009
 */

#include "CranePID.h"
#include "CranePID_private.h"

/* Block parameters (auto storage) */
Parameters rtP = {
  /*  Digital_To_Analog_Convert_P1_Si : '<Root>/Digital To Analog Converter ' */

  { 1.0, 1.0 } ,
  0.0 ,                                 /* Digital_To_Analog_Convert_P1 : '<Root>/Digital To Analog Converter ' */
  /*  Digital_To_Analog_Convert_P2_Si : '<Root>/Digital To Analog Converter ' */

  { 1.0, 1.0 } ,
  0.0 ,                                 /* Digital_To_Analog_Convert_P2 : '<Root>/Digital To Analog Converter ' */
  /*  Digital_To_Analog_Convert_P3_Si : '<Root>/Digital To Analog Converter ' */

  { 1.0, 1.0 } ,
  0.001 ,                               /* Digital_To_Analog_Convert_P3 : '<Root>/Digital To Analog Converter ' */
  /*  Digital_To_Analog_Convert_P4_Si : '<Root>/Digital To Analog Converter ' */

  { 1.0, 1.0 } ,
  1.0 ,                                 /* Digital_To_Analog_Convert_P4 : '<Root>/Digital To Analog Converter ' */
  0.2 ,                                 /* Desired_Position_Input_Amp : '<Root>/Desired Position Input' */
  0.0 ,                                 /* Desired_Position_Input_Bias : '<Root>/Desired Position Input' */
  5.0 ,                                 /* Desired_Position_Input_Freq : '<Root>/Desired Position Input' */
  0.0 ,                                 /* Desired_Position_Input_Phase : '<Root>/Desired Position Input' */
  /*  Read_Cart_Encoder_P1_Size : '<Root>/Read Cart Encoder' */
  { 1.0, 1.0 } ,
  0.0 ,                                 /* Read_Cart_Encoder_P1 : '<Root>/Read Cart Encoder' */
  /*  Read_Cart_Encoder_P2_Size : '<Root>/Read Cart Encoder' */
  { 1.0, 1.0 } ,
  0.0 ,                                 /* Read_Cart_Encoder_P2 : '<Root>/Read Cart Encoder' */
  /*  Read_Cart_Encoder_P3_Size : '<Root>/Read Cart Encoder' */
  { 1.0, 1.0 } ,
  0.001 ,                               /* Read_Cart_Encoder_P3 : '<Root>/Read Cart Encoder' */
  /*  Read_Cart_Encoder_P4_Size : '<Root>/Read Cart Encoder' */
  { 1.0, 1.0 } ,
  1.0 ,                                 /* Read_Cart_Encoder_P4 : '<Root>/Read Cart Encoder' */
  7.6171875E-005 ,                      /* Counts_Meters_Gain : '<Root>/Counts->Meters' */
  10.0 ,                                /* Proportional_a_Gain : '<S4>/Proportional' */
  0.0 ,                                 /* Integral_a_A : '<S4>/Integral' */
  1.0 ,                                 /* Integral_a_C : '<S4>/Integral' */
  /*  Cart_Velocity_Filter1_A : '<S4>/Cart Velocity  Filter1' */
  { -70.7, -10000.0 } ,
  /*  Cart_Velocity_Filter1_C : '<S4>/Cart Velocity  Filter1' */
  { 0.0, 10000.0 } ,
  /*  Read_Pendulum_Encoder_P1_Size : '<Root>/Read Pendulum Encoder' */
  { 1.0, 1.0 } ,
  1.0 ,                                 /* Read_Pendulum_Encoder_P1 : '<Root>/Read Pendulum Encoder' */
  /*  Read_Pendulum_Encoder_P2_Size : '<Root>/Read Pendulum Encoder' */
  { 1.0, 1.0 } ,
  -1024.0 ,                             /* Read_Pendulum_Encoder_P2 : '<Root>/Read Pendulum Encoder' */
  /*  Read_Pendulum_Encoder_P3_Size : '<Root>/Read Pendulum Encoder' */
  { 1.0, 1.0 } ,
  0.001 ,                               /* Read_Pendulum_Encoder_P3 : '<Root>/Read Pendulum Encoder' */
  /*  Read_Pendulum_Encoder_P4_Size : '<Root>/Read Pendulum Encoder' */
  { 1.0, 1.0 } ,
  1.0 ,                                 /* Read_Pendulum_Encoder_P4 : '<Root>/Read Pendulum Encoder' */
  -3.0679615757712823E-003 ,            /* Counts_Radians_Gain : '<Root>/Counts->Radians' */
  3.1415926535897931E+000 ,             /* s7_Value : '<S1>/s7' */
  -5.0 ,                                /* Proportional_b_Gain : '<S5>/Proportional' */
  0.0 ,                                 /* Integral_b_A : '<S5>/Integral' */
  0.0 ,                                 /* Integral_b_C : '<S5>/Integral' */
  /*  Pendulum_Velocity_Filter_A : '<S5>/Pendulum Velocity  Filter' */
  { -70.7, -10000.0 } ,
  /*  Pendulum_Velocity_Filter_C : '<S5>/Pendulum Velocity  Filter' */
  { 0.0, 10000.0 } ,
  /*  Cart_Velocity_Filter_A : '<S1>/Cart Velocity  Filter' */
  { -70.7, -10000.0 } ,
  /*  Cart_Velocity_Filter_C : '<S1>/Cart Velocity  Filter' */
  { 0.0, 10000.0 } ,
  0.0 ,                                 /* id_Threshold : '<S3>/3' */
  1.0 ,                                 /* Gain_Gain : '<S2>/Gain' */
  2.5 ,                                 /* Saturation_UpperSat : '<S2>/Saturation' */
  -2.5 ,                                /* Saturation_LowerSat : '<S2>/Saturation' */
  -1.0 ,                                /* Plot_Scaling_Gain : '<S1>/Plot Scaling' */
  2.0 ,                                 /* D_a_Gain : '<S4>/D' */
  0.0 ,                                 /* D_b_Gain : '<S5>/D' */
  0.1 ,                                 /* Gain2_Gain : '<S3>/Gain2' */
  0.1                                   /* Gain3_Gain : '<S3>/Gain3' */
};

