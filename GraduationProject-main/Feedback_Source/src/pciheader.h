/* $Date:      
 * $Revision:  1.0 $
 * $Author:    EZ $
 *
 * File: pciheader.h
 *
 * Copyright (c) 
 * Z-Real Time Software Development 
 */

#ifndef __PCIHEADER_H__
#define __PCIHEADER_H__

#include <dos.h>
#include <stddef.h>
#include "stdio.h"
#include "stdlib.h"
#include "string.h"


typedef int BOOL ;
#define NONE 0
#define ERROR -1
#define OK 1
#define TRUE 1
#define FALSE 0



#ifndef PCI_MAX_BUS
#  define PCI_MAX_BUS	255
#endif  

#ifndef PCI_MAX_DEV
#  define PCI_MAX_DEV	32
#endif  

#ifndef PCI_MAX_FUNC
#  define PCI_MAX_FUNC	8
#endif /


#define	PCI_CONFIG_ADDR			0x0cf8	// write 32 bits to set address 
#define	PCI_CONFIG_DATA			0x0cfc	// 8, 16, or 32 bit accesses 

//PCI command bits 
#define PCI_CMD_IO_ENABLE		0x0001	// IO access enable 
#define PCI_CMD_MEM_ENABLE		0x0002	// memory access enable
#define PCI_CMD_MASTER_ENABLE	0x0004	// bus master enable 
#define PCI_CMD_MON_ENABLE		0x0008	// monitor special cycles enable 
#define PCI_CMD_WI_ENABLE		0x0010	// write and invalidate enable 
#define PCI_CMD_SNOOP_ENABLE	0x0020	// palette snoop enable 
#define PCI_CMD_PERR_ENABLE		0x0040	// parity error enable 
#define PCI_CMD_WC_ENABLE		0x0080	// wait cycle enable 
#define PCI_CMD_SERR_ENABLE		0x0100	// system error enable 
#define PCI_CMD_FBTB_ENABLE		0x0200	// fast back to back enable 

/* PCI base address mask bits */

#define PCI_MEMBASE_MASK	~0xf	/* mask for memory base address */
#define PCI_IOBASE_MASK		~0x3	/* mask for IO base address */
#define PCI_BASE_IO			0x1	/* IO space indicator */
#define PCI_BASE_BELOW_1M	0x2	/* memory locate below 1MB */
#define PCI_BASE_IN_64BITS	0x4	/* memory locate anywhere in 64 bits */
#define PCI_BASE_PREFETCH	0x8	/* memory prefetchable */

/* Base Address Register Memory/IO Attribute bits */

#define PCI_BAR_SPACE_MASK	(0x01)
#define PCI_BAR_SPACE_IO	(0x01)
#define PCI_BAR_SPACE_MEM	(0x00)

#define PCI_BAR_MEM_TYPE_MASK   (0x06)
#define PCI_BAR_MEM_ADDR32      (0x00)
#define PCI_BAR_MEM_BELOW_1MB	(0x02)
#define PCI_BAR_MEM_ADDR64      (0x04)
#define PCI_BAR_MEM_RESERVED    (0x06)

#define PCI_BAR_MEM_PREF_MASK   (0x08)
#define PCI_BAR_MEM_PREFETCH    (0x08)
#define PCI_BAR_MEM_NON_PREF    (0x00)

#define PCI_BAR_ALL_MASK        (PCI_BAR_SPACE_MASK | \
                                 PCI_BAR_MEM_TYPE_MASK | \
                                 PCI_BAR_MEM_PREF_MASK)

/* PCI header type bits */

#define PCI_HEADER_TYPE_MASK	0x7f	/* mask for header type */
#define PCI_HEADER_PCI_PCI		0x01	/* PCI to PCI bridge */
#define PCI_HEADER_TYPE0        0x00    /* normal device header */
#define PCI_HEADER_MULTI_FUNC	0x80	/* multi function device */

/* PCI configuration device and driver */
 
#define SNOOZE_MODE             0x40    /* snooze mode */
#define SLEEP_MODE_DIS          0x00    /* sleep mode disable */

// Standard device configuration register offsets 
// Note that only modulo-4 addresses are written to the address register 

#define	PCI_CFG_VENDOR_ID		0x00
#define	PCI_CFG_DEVICE_ID		0x02
#define	PCI_CFG_COMMAND			0x04
#define	PCI_CFG_STATUS			0x06
#define	PCI_CFG_REVISION		0x08
#define	PCI_CFG_PROGRAMMING_IF	0x09
#define	PCI_CFG_SUBCLASS		0x0a
#define	PCI_CFG_CLASS			0x0b
#define	PCI_CFG_CACHE_LINE_SIZE	0x0c
#define	PCI_CFG_LATENCY_TIMER	0x0d
#define	PCI_CFG_HEADER_TYPE		0x0e
#define	PCI_CFG_BIST			0x0f
#define	PCI_CFG_BASE_ADDRESS_0	0x10
#define	PCI_CFG_BASE_ADDRESS_1	0x14
#define	PCI_CFG_BASE_ADDRESS_2	0x18
#define	PCI_CFG_BASE_ADDRESS_3	0x1c
#define	PCI_CFG_BASE_ADDRESS_4	0x20
#define	PCI_CFG_BASE_ADDRESS_5	0x24
#define	PCI_CFG_CIS				0x28
#define	PCI_CFG_SUB_VENDER_ID	0x2c
#define	PCI_CFG_SUB_SYSTEM_ID	0x2e
#define	PCI_CFG_EXPANSION_ROM	0x30
#define	PCI_CFG_RESERVED_0		0x34
#define	PCI_CFG_RESERVED_1		0x38
#define	PCI_CFG_DEV_INT_LINE	0x3c
#define	PCI_CFG_DEV_INT_PIN		0x3d
#define	PCI_CFG_MIN_GRANT		0x3e
#define	PCI_CFG_MAX_LATENCY		0x3f
#define PCI_CFG_SPECIAL_USE     0x41
#define PCI_CFG_MODE            0x43

/*---PCI Functions---*/
#define PCI_BIOS_PRESENT          0x01
#define FIND_PCI_DEVICE           0x02
#define READ_CONFIG_DWORD         0x0a
#define PCI_FUNCTION_ID           0xb1


/* Function Prototypes */
int findPciDevice  (int vendorId, int deviceId,	int index, 
					int * pBusNo, int * pDeviceNo, 	int * pFuncNo);

int pciConfigInByte (int busNo, int deviceNo,  int funcNo,
					 int address,  unsigned char * pData);

int pciConfigInLong (int busNo, int deviceNo,
					 int funcNo, int address,
					 unsigned long * pData);

int pciConfigBdfPack (int busNo, int deviceNo, int funcNo);

void getPCI1711BaseAddress (int *AddrData) ;

void getPCI1751BaseAddress (int *AddrData) ;

#endif