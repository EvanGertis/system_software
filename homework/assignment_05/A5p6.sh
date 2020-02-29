#!/bin/bash
start=26
end=36
while [ $start -lt $end ] ; 
do
	./A5p2.sh $start
	start=$((start+1))
done
