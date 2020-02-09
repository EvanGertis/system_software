#!/bin/bash

echo "hello $USER"

if [ $HOME == $PWD ] 
then
	echo "you are in the home directory"
else
	echo "you are not in the home directory"
fi


