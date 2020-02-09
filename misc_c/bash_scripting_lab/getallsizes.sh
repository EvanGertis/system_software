#!/bin/bash

if [ -z $* ] 
then
	echo "ERROR: file input required"
fi

for arg in $*

do
	if [ -e $arg ]
	then
		echo "file $arg"
		stat --printf="%s\n" $arg
		echo "bytes"
	else
		echo "ERROR: $arg doesn't exist"
	fi
done
