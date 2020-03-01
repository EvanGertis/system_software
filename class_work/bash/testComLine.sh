#!/bin/bash
# $0 is script name; $1 is the first command line argument.
# compare with Java and C's ways to access command line arguments
if [ -z $1 ]; then
	echo "usage: " $0 "<directory>"
	exit
fi
ls $1
