#!/bin/bash
# test usage of simple function calls in bash

if [ $# -ne 1 ]; then
	echo "usage: " $0 "<para>"
	exit
fi

echo $1 #print the first command line argument to this script

function quit { # a function with name "quit"
exit
}

function e { # a function with name "e"
echo function e is printing: $1 #Note: $1 is not the first command line argument to this script; instead, it is the first argument for function e
}

function e2 {
echo function e2 is printing: Hello!
}

e Hello #call function e with the argument "Hello"
echo $? #will output 0 to indicate successful function call of e
e World #call function e with the argument "World"
echo $?
e2 #call function e2
quit #calling function quit will exit this script
echo foo
echo $?