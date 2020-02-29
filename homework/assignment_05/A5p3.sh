#!/bin/bash
i=1
while [ $i -lt 4 ] ;
do
	j=1
	echo "$i*$j=$((i*j))"
	while [ $j -lt 6 ] ;
	do
		echo "$i*$j=$((i*j))"
		j=$((j+1))
	done
	i=$((i+1))
done
