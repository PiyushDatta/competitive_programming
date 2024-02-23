@echo off

REM run command
if not exist "out" ( 
    mkdir "out"
)
g++ main.cc -o "out/main.out" & "out/main.out"
g++ check.cc -o "out/check.out" & "out/check.out"
