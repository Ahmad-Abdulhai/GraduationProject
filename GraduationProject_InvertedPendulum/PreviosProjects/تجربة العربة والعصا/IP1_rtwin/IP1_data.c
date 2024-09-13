/*
 * IP1_data.c
 *
 * Real-Time Workshop code generation for Simulink model "IP1.mdl".
 *
 * Model Version                        : 1.84
 * Real-Time Workshop file version      : 5.0 $Date: 2002/05/30 19:21:33 $
 * Real-Time Workshop file generated on : Thu Jan 01 00:14:59 2004
 * TLC version                          : 5.0 (Jun 18 2002)
 * C source code generated on           : Thu Jan 01 00:15:00 2004
 */

#include "IP1.h"
#include "IP1_private.h"

/* Block parameters (auto storage) */
Parameters rtP = {
  0.5 ,                                 /* Saturation_a_UpperSat : '<Root>/Saturation' */
  -0.5 ,                                /* Saturation_a_LowerSat : '<Root>/Saturation' */
  /*  Digital_To_Analog_Convert_P1_Si : '<Root>/Digital To Analog Converter' */
  { 1.0, 1.0 } ,
  0.0 ,                                 /* Digital_To_Analog_Convert_P1 : '<Root>/Digital To Analog Converter' */
  /*  Digital_To_Analog_Convert_P2_Si : '<Root>/Digital To Analog Converter' */
  { 1.0, 1.0 } ,
  0.0 ,                                 /* Digital_To_Analog_Convert_P2 : '<Root>/Digital To Analog Converter' */
  /*  Digital_To_Analog_Convert_P3_Si : '<Root>/Digital To Analog Converter' */
  { 1.0, 1.0 } ,
  0.001 ,                               /* Digital_To_Analog_Convert_P3 : '<Root>/Digital To Analog Converter' */
  /*  Digital_To_Analog_Convert_P4_Si : '<Root>/Digital To Analog Converter' */
  { 1.0, 1.0 } ,
  1.0 ,                                 /* Digital_To_Analog_Convert_P4 : '<Root>/Digital To Analog Converter' */
  /*  Read_Cart_Encoder1_P1_Size : '<Root>/Read Cart Encoder1' */
  { 1.0, 1.0 } ,
  0.0 ,                                 /* Read_Cart_Encoder1_P1 : '<Root>/Read Cart Encoder1' */
  /*  Read_Cart_Encoder1_P2_Size : '<Root>/Read Cart Encoder1' */
  { 1.0, 1.0 } ,
  0.0 ,                                 /* Read_Cart_Encoder1_P2 : '<Root>/Read Cart Encoder1' */
  /*  Read_Cart_Encoder1_P3_Size : '<Root>/Read Cart Encoder1' */
  { 1.0, 1.0 } ,
  0.001 ,                               /* Read_Cart_Encoder1_P3 : '<Root>/Read Cart Encoder1' */
  /*  Read_Cart_Encoder1_P4_Size : '<Root>/Read Cart Encoder1' */
  { 1.0, 1.0 } ,
  1.0 ,                                 /* Read_Cart_Encoder1_P4 : '<Root>/Read Cart Encoder1' */
  7.6171875E-005 ,                      /* Counts_Meters_Gain : '<Root>/Counts->Meters' */
  0.0 ,                                 /* Step_Time : '<S2>/Step' */
  0.0 ,                                 /* Step_Y0 : '<S2>/Step' */
  0.01 ,                                /* Step_YFinal : '<S2>/Step' */
  0.0 ,                                 /* Constant_Value : '<S2>/Constant' */
  0.0 ,                                 /* Constant1_a_Value : '<S2>/Constant1' */
  0.1 ,                                 /* Saturation1_UpperSat : '<Root>/Saturation1' */
  0.1 ,                                 /* Saturation1_LowerSat : '<Root>/Saturation1' */
  /*  Cart_Velocity_Filter_A : '<S1>/Cart Velocity Filter' */
  { -70.7, -10000.0 } ,
  /*  Cart_Velocity_Filter_C : '<S1>/Cart Velocity Filter' */
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
  /*  Pendulum_Velocity_Filter_A : '<S1>/Pendulum Velocity  Filter' */
  { -70.7, -10000.0 } ,
  /*  Pendulum_Velocity_Filter_C : '<S1>/Pendulum Velocity  Filter' */
  { 0.0, 10000.0 } ,
  3.1415926535897931E+000 ,             /* Constant1_b_Value : '<S1>/Constant1' */
  0.0 ,                                 /* Constant2_Value : '<S1>/Constant2' */
  0.0 ,                                 /* Constant3_Value : '<S1>/Constant3' */
  1.0 ,                                 /* Scaling_Gain : '<S3>/Scaling' */
  2.5 ,                                 /* Saturation_b_UpperSat : '<S3>/Saturation' */
  -2.5                                  /* Saturation_b_LowerSat : '<S3>/Saturation' */
};

