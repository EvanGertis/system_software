#!/bin/bash
# demonstration of usage of local variables and return values in functions of bash
if [ $# -ne 2 ]; then
	echo "usage: " $0 "<num1> <num2>"
	exit
fi

function square {
local r=$1 #r is a local variable; if there is also a global variable named r, it is not affected: i.e. global variables can be hidden by local variables
((r = $r * $r))
#echo in square, para1=$1 r=$r
local y=r
((y=y+1))
echo $y
return $r #Note: return value will be truncated to the range 0~255, even if inside square r can have a larger range of values
}

function cubic {
local r=$1 #r is a local variable; if there is also a global variable named r, it is not affected
((r = $r * $r *$r))
echo $r
#echo $r #multiple lines of output could be captured when you call this function like "$(cubic 15)"; see below
}

function increment {
local r=$1
((r = $r + 1))
#echo in increment, para1=$1 r=$r
return $r #Note: return value will be truncated to the range 0~255, even if inside increment r can have a larger range of values
}

increment $1 #call function increment with the first command line argument of this script
((r1 = $?)) #this illustrates how to get the return value of a function all
echo "r1="$r1

square $2 #call function square with the second command line argument of this script
((r2 = $?))
echo "r2="$r2

#the following are optional and will NOT be tested
echo $(cubic 15) #this calls function cubic with argument 15 and captures the output from "echo $r"; this output will not be limited to 0~255
x=$(cubic 16) #we can also save the output from calling function cubic with argument 16 into a variable
echo x\=$x
w=`cubic 17` #equivalent to w=$(cubic 17)
echo w\=$w
echo $(square 9) #this calls function square with argument 9 and captures the output from "echo $y"; this output will not be limited to 0~255
echo $? #this should print 0, not 81
z=$(ls) #we can also save the output of calling an external program into a variable
echo $z #print a flattened output of ls in one line
