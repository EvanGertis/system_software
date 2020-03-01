#!/bin/bash
#demonstrate some possible usage of for loop

if [ $# -ne 2 ]; then
	echo "usage: " $0 "<num1> <num2>"
	exit
fi

if [ $1 -le $2 ]; then
	max=$2
	min=$1
else
	max=$1
	min=$2
fi

echo "loop test 1"
for i in $(seq $min 2 $max) #i will take values min,min+2,min+4,...,up to max
do
	echo i=$i
done

echo
echo "loop test 2"
for i in $(seq $min $max) #i will take values min,min+1,min+2,...,up to max
do
	echo i=$i
done

echo
echo "loop test 3" #`seq 0 2 10` is equivalent to $(seq 0 2 10)
for i in `seq 0 2 10`; do echo i=$i; done #i will take values 0,2,4,6,8,10

echo
echo "loop test 4"
for i in `seq 0 3 20`	#i will take values 0,3,6,9,12,15,18
do
	echo l4: i=$i
	((i=i+1))	#index variable i is updated inside the loop body
	echo l4: i2=$i	#even if index variable i is updated inside the loop body, it is reset to an appropriate value in the precalculated list 0,3,6,9,12,15,18
done

echo after loop test 4, i=$i

echo
echo "loop test 5"
for ((j=$min;j<$max;j++)) #the variables max and min can be accessed in this context
do
	echo j=$j
	let j++	#index variable j is updated inside the loop body and the effect of update maintains; compare with loop test 4 above
done

#My testings show that (1) it is OK to enclose for loop body using {}
#(2) it is NOT OK to enclose while and until loop body using {}
# echo
# echo "loop test 6"
# for i in $(seq $min $max) #i will take values min,min+1,min+2,...,up to max
	# {
		# echo i=$i
	# }