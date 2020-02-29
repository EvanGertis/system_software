#!/bin/bash
if [ "$#" -ne 1 ] ; then
	echo "ERROR: INVALID PARAMETER COUNT"
	echo "usage: ./A5p1.sh <int>"
	exit 1
fi

if ! [[ "$1" =~ ^[0-9]+$ ]]; then
	echo "ERROR: INVALID PARAMETER TYPE"
	echo "usage: ./A5p2.sh <int>"
	exit 1
fi 
number=$1
count=0
while [ $number -gt 1 ]
do
	echo -n "$number "
	count=$((count+1))
	if [ $((number % 2)) -ne 0 ] ; then
		number=$(((3*number+1)/2))
	else
		number=$((number/2))
	fi	
done 
echo " $number"
echo "Length of the sequence: $((count+1))"
exit 0