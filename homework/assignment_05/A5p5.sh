#!/bin/bash
if [ "$#" -ne 1 ] ; then
	echo "ERROR: INVALID NUMBER OF PARAMETERS"
	echo "usage: ./A5p5.sh <positive int>"
fi

if [ $1 -lt 0 ] ; then
	echo "ERROR: INVALID PARAMETER "
	echo "usage: ./A5p5.sh <positive int>"
fi 

start=1
end=$1
while [ $start -lt $end ] ; 
do
	if [ ! $((start % 2)) -eq 0 ] ; then
		echo -n " $start"
	fi
	start=$((start+1))
done
exit 0
