#!/bin/bash

# CSCI 3060/ SOFE 3980 Course Project Front End
# Group: Untitled
# Member: Calvin Lo, Albert Fung, Karan Chandwaney

# Purpose: kill process with SIGINT to keep main script running while killing C++ program after each individual test ends

# sleep for 0.01 seconds
sleep 0.01
# send SIGINT signal to the process named output
pkill -2 output 