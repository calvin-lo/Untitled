#!/bin/bash
for file in *;
do
	if diff $file $1 
	then
		echo $file and $1 are the same
	else
		echo $file and $1 are not the same
		diff $file $1 >> "massdiff.log"
	fi
done