#!/bin/bash
#demonstrate some possible usage of while and until loops
#Note: Unlike Java/C/C++, there is no do-while loops in Bash

echo "loop test 0"
COUNTER=0
while : ; do #: is the null command. The null command does nothing and its exit status is always set to true
	let COUNTER++
	echo "COUNTER=$COUNTER"
	[[ $COUNTER -lt 10 ]] || break	#break out of the while loop when $COUNTER is greater than 9
	#(( $COUNTER < 10 )) || break	#this is equivalent to the above line
done

echo
echo "loop test 1"
COUNTER=0
while [ $COUNTER -lt 10 ]; do
	echo The counter is $COUNTER
	let COUNTER=COUNTER+1 
done

echo
echo "loop test 2"

COUNTER=20
until [ $COUNTER -lt 10 ]; do #Note: until loop is not available in C or Java
	echo COUNTER is $COUNTER
	let COUNTER-=1
done

echo
echo "loop test 3"
a=5
b=20
while [[ $a -lt 20 && $b -gt 10 ]]; do #you can add logical connectives &&,||,! to the condition; be aware when the loop terminates
	echo a=$a,b=$b
	let a++
	let b--
done

echo
echo "loop test 4"
a=5
b=20
until [[ $a -gt 20 && $b -lt 10 ]]; do #you can add logical connectives &&,||,! to the condition; be aware when the loop terminates, i.e. both tests are satisfied
	echo a=$a,b=$b
	let a++
	let b--
done

echo
echo "loop test 5"
a=5
b=20
until [[ $a -gt 20 || $b -lt 10 ]]; do #you can add logical connectives &&,||,! to the condition; be aware when the loop terminates, i.e. at least one of the tests is satisfied
	echo a=$a,b=$b
	let a++
	let b--
done

echo
echo "loop test 6"
COUNTER=0
while (( $COUNTER < 10 )); do #arithmetic context (( )) allows you to write while loops more similar to C and Java
	echo The counter 6 is $COUNTER
	let COUNTER=COUNTER+1 
done

echo
echo "loop test 7"
COUNTER=10
value=30
until (( $COUNTER > 20 || value > 35 )); do #similar to loop test 6, but iterate when condition is false, or until condition is true
	echo The counter 7 is $COUNTER, value is $value
	let COUNTER=COUNTER+1
	if (( $COUNTER < 13 )); then
		continue #break and continue are all supported in Bash loops, just like C/C++/Java
	fi
	let value++
done

echo
echo "loop test 8"
while true; do echo 'Hit CTRL+C'; sleep 1; done
#My testings show that (1) it is OK to enclose for loop body using {}
#(2) it is NOT OK to enclose while and until loop body using {}
# echo
# echo "loop test 8"
# COUNTER=100
# value=60
# until (( $COUNTER > 120 || value > 65 ));
# { #similar to loop test 6, but iterate when condition is false, or until condition is true
	# echo The counter 8 is $COUNTER, value is $value
	# let COUNTER=COUNTER+1
	# if (( $COUNTER < 103 )); then
		# continue #break and continue are all supported in Bash loops, just like C/C++/Java
	# fi
	# let value++
# }

# echo
# echo "loop test 9"
# COUNTER=0
# while (( $COUNTER < 10 )); { #arithmetic context (( )) allows you to write while loops more similar to C and Java
	# echo The counter 9 is $COUNTER
	# let COUNTER=COUNTER+1 
# }