#!/bin/bash
if [ "$#" -ne 1 ] ; then
   echo "ERROR: ARGUMENT COUNT"
   echo "usage: $0 <dir>"   
   exit 1
fi 

if [ ! -d $1 ] ; then
	echo "ERROR: INVALID PARAMETER TYPE"
       	echo "usage: ./A5p1.sh <dir>"
	exit 1
fi

fileCount=0
directoryCount=0
executableCount=0

for entry in "$1"/*
do
	if [ -d "$entry" ] ; then 
		let directoryCount++;
	fi
	if [ -f "$entry" ] ; then
		if [ -x "$entry" ] ; then 
			let executableCount++;
		else
			let fileCount++;
		fi
	fi
done
echo "Number of executable files in $1: $executableCount";
echo "Number of non-executable files in $1: $fileCount";
echo "Number of subdirectories in $1: $directoryCount";
