@echo off
Setlocal enabledelayedexpansion

Set "Pattern=input.txt"
Set "Replace=_loginlogout_.in"

For %%a in (*.txt) Do (
    Set "File=%%~a"
    Ren "%%a" "!File:%Pattern%=%Replace%!"
)

Set "Pattern=output.txt"
Set "Replace=_loginlogout_.out"

For %%a in (*.txt) Do (
    Set "File=%%~a"
    Ren "%%a" "!File:%Pattern%=%Replace%!"
)
Exit