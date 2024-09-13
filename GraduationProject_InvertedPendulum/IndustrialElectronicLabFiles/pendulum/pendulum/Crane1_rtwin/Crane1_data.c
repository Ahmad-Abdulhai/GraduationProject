/*
 * Crane1_data.c
 *
 * Real-Time Workshop code generation for Simulink model "Crane1.mdl".
 *
 * Model Version                        : 1.73
 * Real-Time Workshop file version      : 5.0 $Date: 2002/05/30 19:21:33 $
 * Real-Time Workshop file generated on : Wed Apr 01 15:50:10 2009
 * TLC version                          : 5.0 (Jun 18 2002)
 * C source code generated on           : Wed Apr 01 15:50:10 2009
 */

#include "Crane1.h"
#include "Crane1_private.h"

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
  10.0 ,                                /* Step_Time : '<Root>/Step' */
  0.0 ,                                 /* Step_Y0 : '<Root>/Step' */
  0.2 ,                                 /* Step_YFinal : '<Root>/Step' */
  3.1415926535897931E+000 ,             /* Constant_Value : '<Root>/Constant' */
  0.0 ,                                 /* Constant1_Value : '<Root>/Constant1' */
  0.0 ,                                 /* Constant2_Value : '<Root>/Constant2' */
  /*  Matrix_Gain_Gain : '<Root>/Matrix Gain' */
  { 7.0711, -11.0, 2.0251, -1.2106 } ,
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
  1.0 ,                                 /* Scaling_Gain : '<S2>/Scaling' */
  2.5 ,                                 /* Saturation_UpperSat : '<S2>/Saturation' */
  -2.5                                  /* Saturation_LowerSat : '<S2>/Saturation' */
};

