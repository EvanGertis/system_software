#!/bin/bash
rm makefile.txt
echo "all: prog" >> makefile.txt
echo "prog: $(ls | grep *.c)" >> makefile.txt
echo "	gcc -o prog $(ls | grep *c)" >> makefile.txt
