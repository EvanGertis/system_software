#!/bin/bash
if [ -f  "makefile.txt" ]; then
	rm makefile.txt
fi

echo "all: prog" >> makefile.txt
echo "prog: $(ls | grep *.cpp)" >> makefile.txt
echo "	g++ -g -o prog $(ls | grep *.cpp)" >> makefile.txt
