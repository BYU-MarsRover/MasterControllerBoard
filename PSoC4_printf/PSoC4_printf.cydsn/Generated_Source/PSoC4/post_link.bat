@REM This script allows a 3rd party IDE to use CyHexTool to perform
@REM any post processing that is necessary to convert the raw flash
@REM image into a complete hex file to use in programming the PSoC.
@REM USAGE: post_link.bat
@REM    arg1: Persistant path back to the directory containing the app project.
@REM    arg2: Path (relative to arg1) of the directory where the hex files go.
@REM    arg3: Name of the project.
@REM NOTE: This script is auto generated. Do not modify.

"C:\Program Files\Cypress\PSoC Creator\2.2\PSoC Creator\bin\cyvalidateide.exe" -dev CY8C4245AXI-483 -ide "%~1\%~3" -flsAddr 0x0 -flsSize 0x8000 -sramAddr 0x20000000 -sramSize 0x1000
@IF %errorlevel% NEQ 0 EXIT /b %errorlevel% 
move "%~1\%~2\%~n3.hex" "%~1\%~2\%~n3.ihx"
@IF %errorlevel% NEQ 0 EXIT /b %errorlevel% 
"C:\Program Files\Cypress\PSoC Creator\2.2\PSoC Creator\bin\cyhextool" -o "%~1\%~2\%~n3.hex" -f "%~1\%~2\%~n3.ihx" -prot "%~dp0protect.hex" -id 4C81193 -a EEPROM=90200000:0,PROGRAM=00000000:8000,CONFIG=80000000:1000,PROTECT=90400000:40 -meta 1101 -chipProt 01 
@IF %errorlevel% NEQ 0 EXIT /b %errorlevel% 
CD /D "C:\Keil\UV4"
@IF %errorlevel% NEQ 0 EXIT /b %errorlevel% 
IF EXIST "C:\Users\wbz\Desktop\Element14 Posts\028 - Tiny PrintF - NS\PSoC4_printf.cywrk.Archive03\PSoC4_printf\PSoC4_printf.cydsn\PSoC4_printf.svd" "C:\Keil\UV4\SVDConv.exe" "C:\Users\wbz\Desktop\Element14 Posts\028 - Tiny PrintF - NS\PSoC4_printf.cywrk.Archive03\PSoC4_printf\PSoC4_printf.cydsn\PSoC4_printf.svd" -o "C:\Users\wbz\Desktop\Element14 Posts\028 - Tiny PrintF - NS\PSoC4_printf.cywrk.Archive03\PSoC4_printf\PSoC4_printf.cydsn" --generate=sfr -n "PSoC4_printf"
IF NOT EXIST "C:\Users\wbz\Desktop\Element14 Posts\028 - Tiny PrintF - NS\PSoC4_printf.cywrk.Archive03\PSoC4_printf\PSoC4_printf.cydsn\PSoC4_printf.svd" rem "C:\Users\wbz\Desktop\Element14 Posts\028 - Tiny PrintF - NS\PSoC4_printf.cywrk.Archive03\PSoC4_printf\PSoC4_printf.cydsn\PSoC4_printf.sfr"
@IF %errorlevel% NEQ 0 EXIT /b %errorlevel% 
