#!/bin/bash
if [ "$#" -ne 1 ] ; then
	echo "ERROR: INVALID NUMBER OF PARAMETERS"
	echo "usage: $0 <positive int>"
	exit 1
fi

if [ $1 -lt 0 ] ; then
	echo "ERROR: INVALID PARAMETER "
	echo "usage: $0 <positive int>"
	exit 1
fi 

start=1
end=$1
if [ $end -eq $start ] ; then
	echo -n "$start"
fi

while [ $start -lt $end ] ; 
do
	if [ ! $((start % 2)) -eq 0 ] ; then
		echo -n " $start"
	fi
	let start++
done
exit 0
