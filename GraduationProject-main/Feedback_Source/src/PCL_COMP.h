/* $Revision: 0.99 $
 * Copyright (c) 2000-2001 to whomever wants to have it 
 *
 * File    : pcl_comp.h
 *
 * Abstract:
 *      Compiler dependent functions such as _enable(), _disable(), etc., are
 *      defined in this file.
 *      Currently only the WATCOM compiler is supported !!!!!
 * 		
 */

#ifndef __PCL_COMP__
# define __PCL_COMP__

# ifdef __WATCOMC__
#  include <dos.h>
#  include <conio.h>

#  define EnableInterrupts              _enable()
#  define DisableInterrupts             _disable()
#  define GetIntrVector(num)            _dos_getvect(num)
#  define SetIntrVector(num,isr)        _dos_setvect(num,isr)
#  define ISR_PTR_TYPE                  __interrupt __far

#  define ReadByteFromHwPort(addr)      inp(addr)
#  define WriteByteToHwPort(addr,val)   outp(addr,val)
# else
#  ifdef MATLAB_MEX_FILE
#   define ACCESS_HW                     0
#   define ReadByteFromHwPort(addr)      0
#   define WriteByteToHwPort(addr,val)   /* do nothing */
#  endif
# endif /* __WATCOMC__ */

#endif 

/* EOF: plc_comp.h */
