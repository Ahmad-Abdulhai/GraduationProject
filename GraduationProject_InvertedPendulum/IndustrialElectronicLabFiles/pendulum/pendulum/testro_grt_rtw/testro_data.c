/*
 * testro_data.c
 *
 * Real-Time Workshop code generation for Simulink model "testro.mdl".
 *
 * Model Version                        : 1.1
 * Real-Time Workshop file version      : 5.0 $Date: 2002/05/30 19:21:33 $
 * Real-Time Workshop file generated on : Mon Mar 23 11:39:34 2009
 * TLC version                          : 5.0 (Jun 18 2002)
 * C source code generated on           : Mon Mar 23 11:39:34 2009
 */

#include "testro.h"
#include "testro_private.h"

/* Block parameters (auto storage) */
Parameters rtP = {
  /*  Read_Cart_Encoder1_P1_Size : '<S1>/Read Cart Encoder1' */
  { 1.0, 1.0 } ,
  0.0 ,                                 /* Read_Cart_Encoder1_P1 : '<S1>/Read Cart Encoder1' */
  /*  Read_Cart_Encoder1_P2_Size : '<S1>/Read Cart Encoder1' */
  { 1.0, 1.0 } ,
  0.0 ,                                 /* Read_Cart_Encoder1_P2 : '<S1>/Read Cart Encoder1' */
  /*  Read_Cart_Encoder1_P3_Size : '<S1>/Read Cart Encoder1' */
  { 1.0, 1.0 } ,
  0.001 ,                               /* Read_Cart_Encoder1_P3 : '<S1>/Read Cart Encoder1' */
  /*  Read_Cart_Encoder1_P4_Size : '<S1>/Read Cart Encoder1' */
  { 1.0, 1.0 } ,
  1.0 ,                                 /* Read_Cart_Encoder1_P4 : '<S1>/Read Cart Encoder1' */
  7.6171875E-005 ,                      /* Counts_Meters_Gain : '<S1>/Counts->Meters' */
  /*  Read_Pendulum_Encoder_P1_Size : '<S1>/Read Pendulum Encoder' */
  { 1.0, 1.0 } ,
  1.0 ,                                 /* Read_Pendulum_Encoder_P1 : '<S1>/Read Pendulum Encoder' */
  /*  Read_Pendulum_Encoder_P2_Size : '<S1>/Read Pendulum Encoder' */
  { 1.0, 1.0 } ,
  -1024.0 ,                             /* Read_Pendulum_Encoder_P2 : '<S1>/Read Pendulum Encoder' */
  /*  Read_Pendulum_Encoder_P3_Size : '<S1>/Read Pendulum Encoder' */
  { 1.0, 1.0 } ,
  0.001 ,                               /* Read_Pendulum_Encoder_P3 : '<S1>/Read Pendulum Encoder' */
  /*  Read_Pendulum_Encoder_P4_Size : '<S1>/Read Pendulum Encoder' */
  { 1.0, 1.0 } ,
  1.0 ,                                 /* Read_Pendulum_Encoder_P4 : '<S1>/Read Pendulum Encoder' */
  -3.0679615757712823E-003 ,            /* Counts_Radians_Gain : '<S1>/Counts->Radians' */
  5.0 ,                                 /* Step_Time : '<Root>/Step' */
  0.0 ,                                 /* Step_Y0 : '<Root>/Step' */
  0.2 ,                                 /* Step_YFinal : '<Root>/Step' */
  20.0 ,                                /* Gain4_Gain : '<Root>/Gain4' */
  3.1415926535897931E+000 ,             /* Constant_Value : '<Root>/Constant' */
  -25.0 ,                               /* Proportional_a_Gain : '<S3>/Proportional' */
  0.0 ,                                 /* Integral_a_A : '<S3>/Integral' */
  0.0 ,                                 /* Integral_a_C : '<S3>/Integral' */
  -28.0 ,                               /* D_a_Gain : '<S3>/D' */
  -62.0 ,                               /* Proportional_b_Gain : '<S2>/Proportional' */
  0.0 ,                                 /* Integral_b_A : '<S2>/Integral' */
  0.0 ,                                 /* Integral_b_C : '<S2>/Integral' */
  -110.0 ,                              /* D_b_Gain : '<S2>/D' */
  /*  Digital_To_Analog_Convert_P1_Si : '<S1>/Digital To Analog Converter' */
  { 1.0, 1.0 } ,
  0.0 ,                                 /* Digital_To_Analog_Convert_P1 : '<S1>/Digital To Analog Converter' */
  /*  Digital_To_Analog_Convert_P2_Si : '<S1>/Digital To Analog Converter' */
  { 1.0, 1.0 } ,
  0.0 ,                                 /* Digital_To_Analog_Convert_P2 : '<S1>/Digital To Analog Converter' */
  /*  Digital_To_Analog_Convert_P3_Si : '<S1>/Digital To Analog Converter' */
  { 1.0, 1.0 } ,
  0.001 ,                               /* Digital_To_Analog_Convert_P3 : '<S1>/Digital To Analog Converter' */
  /*  Digital_To_Analog_Convert_P4_Si : '<S1>/Digital To Analog Converter' */
  { 1.0, 1.0 } ,
  1.0 ,                                 /* Digital_To_Analog_Convert_P4 : '<S1>/Digital To Analog Converter' */
  1.0 ,                                 /* Scaling_Gain : '<S4>/Scaling' */
  2.5 ,                                 /* Saturation_UpperSat : '<S4>/Saturation' */
  -2.5                                  /* Saturation_LowerSat : '<S4>/Saturation' */
};

