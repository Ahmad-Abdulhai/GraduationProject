/* $Date:      
 * $Revision:  1.01 $
 * $Author:    EZ $
 *
 * File: pci1751def.h
 *
 * Copyright (c) 
 */

#ifndef __PCI1751DEF_H__
#define __PCI1751DEF_H__

#include <conio.h>
#include <dos.h>
#include <stddef.h>
#include <stdio.h>
#include <stdlib.h>
//#include "c:\MATLABR12\extern\include\tmwtypes.h"
#include "tmwtypes.h"

//function deglerations

// digital i/o functions
void pci1751_writeDigOut(uint_T baseAddr, 
						 uint_T byte, 
						 uint_T channel, 
						 char_T portName[128]);

uint_T  pci1751_readDigIn(uint_T baseAddr, 
					   uint_T channel,
					   char_T portName[128]);

void pci1751_resetPorts(uint_T baseAddr,
						uint_T channel);



#endif