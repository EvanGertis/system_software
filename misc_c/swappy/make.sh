#!/bin/bash
rm makefile.txt
echo "all: prog" >> makefile.txt
echo "prog: $(ls | grep *.c)" >> makefile.txt
echo "	gcc -g -o prog $(ls | grep *c)" >> makefile.txt
