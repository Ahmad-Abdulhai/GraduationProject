/*
 * InvertedPD_dt.h
 *
 * Real-Time Workshop code generation for Simulink model "InvertedPD.mdl".
 *
 * Model Version                        : 1.72
 * Real-Time Workshop file version      : 5.0 $Date: 2002/05/30 19:21:33 $
 * Real-Time Workshop file generated on : Thu Mar 01 00:34:54 2012
 * TLC version                          : 5.0 (Jun 18 2002)
 * C source code generated on           : Thu Mar 01 00:34:55 2012
 */

/* data type size table */
static uint_T rtDataTypeSizes[] = {
  sizeof(real_T),
  sizeof(real32_T),
  sizeof(int8_T),
  sizeof(uint8_T),
  sizeof(int16_T),
  sizeof(uint16_T),
  sizeof(int32_T),
  sizeof(uint32_T),
  sizeof(boolean_T),
  sizeof(fcn_call_T),
  sizeof(int_T),
  sizeof(pointer_T),
  sizeof(action_T)
};

/* data type name table */
static const char_T * rtDataTypeNames[] = {
  "real_T",
  "real32_T",
  "int8_T",
  "uint8_T",
  "int16_T",
  "uint16_T",
  "int32_T",
  "uint32_T",
  "boolean_T",
  "fcn_call_T",
  "int_T",
  "pointer_T",
  "action_T"
};

/* data type transitions for block I/O structure */
static DataTypeTransition rtBTransitions[] = {
  {(char_T *)(&rtB.Read_Cart_Encoder1), 0, 0, 12}
};

/* data type transition table for block I/O structure */
static DataTypeTransitionTable rtBTransTable = {
  1U,
  rtBTransitions
};

/* data type transitions for Parameters structure */
static DataTypeTransition rtPTransitions[] = {
  {(char_T *)(&rtP.Digital_To_Analog_Convert_P1_Si[0]), 0, 0, 58}
};

/* data type transition table for Parameters structure */
static DataTypeTransitionTable rtPTransTable = {
  1U,
  rtPTransitions
};

/* [EOF] InvertedPD_dt.h */
