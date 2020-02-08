#!/bin/bash
if [ -f  "makefile.txt" ]; then
	rm makefile.txt
fi

echo "all: prog" >> makefile.txt
echo "prog: $(ls | grep *.c)" >> makefile.txt
echo "	gcc -g -o prog $(ls | grep *c)" >> makefile.txt
