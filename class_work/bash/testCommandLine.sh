#!/bin/bash
# test usage of several special variables in bash.
# $#: number of command line arguments.
# $*: the aggregate command line arguments.
# $@: a list of all command line arguments.
echo "number of command line arguments is $#"
echo

echo
echo testing \$* and \$@ WITH quotes
echo

echo "using \$* "
for arg in "$*"
do
   echo "$arg"
done

echo "using \$@ "
for arg in "$@"
do
   echo "$arg"
done

echo
echo testing \$* and \$@ WITHOUT quotes
echo

echo "using \$* "
for arg in $*
do
   echo "$arg"
done

echo "using \$@ "
for arg in $@
do
   echo "$arg"
done
