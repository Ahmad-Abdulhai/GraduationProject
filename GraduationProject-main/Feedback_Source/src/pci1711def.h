/* $Date:      
 * $Revision:  1.01 $
 * $Author:    EZ $
 *
 * File: pci1711def.h
 *
 * Copyright (c) 
 */

#ifndef __PCI1711DEF_H__
#define __PCI1711DEF_H__

//#include "c:\MATLABR12\extern\include\tmwtypes.h"
//#include "conio.h"
#include "tmwtypes.h"

// function deglerations 
// ad functions
void pci1711_selectAdcChannel(uint_T baseAddr, uint_T channel);
void pci1711_setAdcGain(uint_T baseAddr, int_T gain);
void pci1711_startAdcConversion(uint_T baseAddr);
unsigned char pci1711_isAdcConversionFinished(uint_T baseAddr);
real_T pci1711_getVoltage(uint_T baseAddr, uint_T gain);


//da functions
void pci1711_writeToDac(uint_T baseAddr, uint_T channel,
						uint_T range, real_T value );


// digital i/o functions
void pci1711_writeDigout(uint_T baseAddr, uint_T value, uint_T port);
uint_T pci1711_readDigIn(uint_T baseAddr, uint_T port);

void pci1711_resetEncoder(uint_T baseAddr);

#endif
