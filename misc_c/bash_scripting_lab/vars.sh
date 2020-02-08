#!/bin/bash
if [[ $# -eq 0 ]] ; 
then
	echo "Enter your name as an argument"
	exit 1
fi

name=$1
echo "hi $name"
