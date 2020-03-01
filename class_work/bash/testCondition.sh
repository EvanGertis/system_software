#!/bin/bash
# test usage of conditional testing in bash
if [ $# -ne 1 ]; then
	echo "usage: " $0 "<num>"
	exit #Notice that multiple statements can appear in the body of the if block.
fi

count=$1
if [ $count -eq 10 ]; then
	echo "Count is 10"
elif [ $count -gt 10 ]; then #elif and else are optional
	echo "Count is greater than 10"
else
	echo "Count is less than 10"
fi
