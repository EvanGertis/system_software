#!/bin/bash
if [[ -z $1 ]] 
then
	echo "Error: file required"
	exit 1
fi

if [[ -e $1 ]] 
then
	echo "file is:  "  
	stat --printf="%s\n" $1
       	echo "bytes"
else
	echo "File doesn't exisit"
fi
