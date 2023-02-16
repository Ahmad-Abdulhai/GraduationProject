/* $Date:      
 * $Revision:  1.0 $
 * $Author:    EZ $
 *
 * File: ServoTHeader.h
 *
 * Copyright (c) 
 */

#ifndef __SERVOTHEADER_H__
#define __SERVOTHEADER_H__

#include "tmwtypes.h"


// function declerations
void	servoTrainer_SetIOConfig(uint_T baseAddr);

void	servoTrainer_setInputChannelGrayCode(uint_T baseAddr);
void	servoTrainer_setInputChannelADC(uint_T baseAddr);

void	servoTrainer_writeToDac (uint_T baseAddr, int mode, real_T value);

void	servoTrainer_startADConversion(uint_T baseAddr);
uint_T  servoTrainer_isAdcConversionFinished(uint_T baseAddr);
uint_T  servoTrainer_getAdcValue (uint_T baseAddr);


void     servoTrainer_BcontrolMode(uint_T baseAddr, int value);
void     servoTrainer_SwitchControl(uint_T baseAddr, int mode);

//int      servoTrainer_readIndex(uint_T baseAddr);
uint_T   servoTrainer_readPortClower(uint_T baseAddr);
uint_T   servoTrainer_readPortAPositionReadMode(uint_T baseAddr, int reset);




#endif