/*
 * invertedpd_data.c
 *
 * Real-Time Workshop code generation for Simulink model "invertedpd.mdl".
 *
 * Model Version                        : 1.67
 * Real-Time Workshop file version      : 5.0 $Date: 2002/05/30 19:21:33 $
 * Real-Time Workshop file generated on : Mon Sep 20 21:52:28 2010
 * TLC version                          : 5.0 (Jun 18 2002)
 * C source code generated on           : Mon Sep 20 21:52:29 2010
 */

#include "invertedpd.h"
#include "invertedpd_private.h"

/* Block parameters (auto storage) */
Parameters rtP = {
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
  0.0 ,                                 /* Constant_Value : '<Root>/Constant' */
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
  1.302839E+002 ,                       /* Gain_Gain : '<S1>/Gain' */
  -45.7776 ,                            /* Gain1_Gain : '<S1>/Gain1' */
  34.0233 ,                             /* Gain2_Gain : '<S1>/Gain2' */
  -30.7689 ,                            /* Gain3_Gain : '<S1>/Gain3' */
  -41.616 ,                             /* N_Gain : '<S1>/N' */
  1.0 ,                                 /* Scaling_Gain : '<S2>/Scaling' */
  2.5 ,                                 /* Saturation_UpperSat : '<S2>/Saturation' */
  -2.5                                  /* Saturation_LowerSat : '<S2>/Saturation' */
};

