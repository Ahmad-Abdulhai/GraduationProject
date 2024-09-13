set MATLAB=C:\MATLAB6p5
set MSVCDir=c:\program files\microsoft visual studio\vc98
set MSDevDir=c:\program files\microsoft visual studio\common\msdev98
C:\MATLAB6p5\rtw\bin\win32\envcheck INCLUDE "c:\program files\microsoft visual studio\vc98\include"
if errorlevel 1 goto vcvars32
C:\MATLAB6p5\rtw\bin\win32\envcheck PATH "c:\program files\microsoft visual studio\vc98\bin"
if errorlevel 1 goto vcvars32
goto make
:vcvars32
set VSCommonDir=\common
call "C:\MATLAB6p5\toolbox\rtw\rtw\private\vcvars32_600.bat"
:make
nmake -f IP2.mk ADD_MDL_NAME_TO_GLOBALS=1 VISUAL_VER=6.0
@if not errorlevel 0 echo The make command returned an error of %errorlevel%
