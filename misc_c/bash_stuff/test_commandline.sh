#!/bin/bash

echo "using \$*"
for arg in "$*"
do
	echo "$arg"
done

echo "using $\@"
for arg in "$@"
do
	echo "$arg"
done
