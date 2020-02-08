#!/bin/bash
echo $# "total arguments"
echo $0 $1 $2 $3
shift
echo $0 $1 $2
shift
echo $0 $1
echo "exit status: " $?
