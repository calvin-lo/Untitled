@echo off
Setlocal enabledelayedexpansion

Set "Pattern=.txt"
Set "Replace="

For %%a in (*.txt) Do (
    Set "File=%%~a"
    Ren "%%a" "!File:%Pattern%=%Replace%!"
)

Pause&Exit