#!/bin/bash
#demonstrate some possible usage of for loop

echo "Bash version ${BASH_VERSION}..." #BASH_VERSION is a predefined variable known to Bash
#echo "Bash version $BASH_VERSION..." #equivalent to the above line
echo "loop test 1"
for i in {0..10..2}	#i will take values 0,2,4,6,8,10
do
	echo i=$i
done

echo
echo "loop test 2"
for var in str1 str2 strn
do
	echo var=$var
	var="computer science" #index variable var is updated inside the loop body
	echo var=$var	#even if index variable var is updated inside the loop body, it is reset to an appropriate value in the precalculated list str1 str2 strn
done

echo
echo "loop test 3"
val=37
for ((i=0;i<20;i++)) #arithmetic context (( )) allows you to write for loops more similar to C and Java
do
	((val=($val*$val)%2017))
	echo val=$val
done
echo after loop test 3, val=$val

echo
echo "loop test 4"
for ((j=0;j<10;j++))
do
	echo j=$j
	let j++	#index variable j is updated inside the loop body and the effect of update maintains; see also testLoop3.sh
done

echo
echo "loop test 5"
for i in {10..0..2}	#i will take values 10,8,6,4,2,0
do
	echo i=$i
done

#My testings show that (1) it is OK to enclose for loop body using {}
#(2) it is NOT OK to enclose while and until loop body using {}
# echo
# echo "loop test 6"
# for ((k=0;k<10;k++))
	# {
		# echo k=$k
		# let k++	#index variable k is updated inside the loop body and the effect of update maintains; see also testLoop3.sh
	# }

# echo
# echo "loop test 7"
# for var in str1 str2 strn
# {
	# echo var=$var
	# var="computer science" #index variable var is updated inside the loop body
	# echo var=$var	#even if index variable var is updated inside the loop body, it is reset to an appropriate value in the precalculated list str1 str2 strn
# }