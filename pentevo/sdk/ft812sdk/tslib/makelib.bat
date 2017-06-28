@echo off

set path=%path%;c:\Tools\PROG\SDCC\bin\

if not exist obj md obj
del /q /s obj >nul
del *.lib
copy *.c obj
copy *.h obj
cd obj

sdcc-lib-split.exe tsfunc.c >>lib.lst

for /f %%i in (lib.lst) do (
  echo %%i
  sdcc -mz80 --std-sdcc11 --opt-code-speed -c %%i -o %%i.rel
  sdcclib ../ts.lib %%i.rel
)

pause
