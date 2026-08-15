@echo off

call compile.bat sol
if %errorlevel% neq 0 exit /b
call compile.bat main
if %errorlevel% neq 0 exit /b
call compile.bat gen
if %errorlevel% neq 0 exit /b

set TC=10
set i=0
:loop
echo TEST %i%
gen.exe
main.exe
sol.exe
fc /w main.out main.ans
if %errorlevel% neq 0 exit /b
set /a i=i+1
if %i% neq %TC% goto loop