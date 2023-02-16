/* $Date:      
 * $Revision:  0.99 $
 * $Author:    EZ $
 *
 * File: pcl812def.h
 *
 * Copyright (c) 
 */

#ifndef __PLC812DEF__
#define __PLC812DEF__

//#include "\MATLABR11\extern\include\tmwtypes.h"
#include "tmwtypes.h"
//#include "pcl_comp.h"

// function deglerations 
// ad functions
void pcl812_selectAdcChannel(uint_T baseAddr, uint_T channel);
void pcl812_setAdcGain(uint_T baseAddr, int_T gain);
void pcl812_startAdcConversion(uint_T baseAddr);
uint_T pcl812_isAdcConversionFinished(uint_T baseAddr);
real_T pcl812_getVoltage(uint_T baseAddr, real_T Ratio);

//da functions
void pcl812_writeToDac(uint_T baseAddr, uint_T channel, uint_T value );

// digital i/o functions
void pcl812_writeHighDigout(uint_T baseAddr, uint_T value );
void pcl812_writeLowDigout(uint_T baseAddr, uint_T value );
uint_T pcl812_readHighDigIn(uint_T baseAddr);
uint_T pcl812_readLowDigIn(uint_T baseAddr);
void pcl812_resetEncoder(uint_T baseAddr);




#endif 

/* EOF:  pcl812def.h */
