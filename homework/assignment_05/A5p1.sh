#!/bin/bash
fileCount=0
directoryCount=0
executableCount=0

for entry in "$1"/*
do
	if [ -d "$entry" ] ; then 
		directoryCount=$((directoryCount+1));
	fi
	if [ -f "$entry" ] ; then
		if [ -x "$entry" ] ; then 
			executableCount=$((executableCount+1));
		else
			fileCount=$((fileCount+1));
		fi
	fi
done
echo "Number of executable files in <dir>: $executableCount";
echo "Number of non-executable files in <dir>: $fileCount";
echo "Number of subdirectories in <dir>: $directoryCount";
