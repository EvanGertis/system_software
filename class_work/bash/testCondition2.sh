#!/bin/bash
# demonstrates conditional testing using more complex conditions (logical and, or, negation).
# Be aware of the difference between string comparisons and numerical comparisons.
if [ $# -ne 2 ]; then
	echo "usage: " $0 "<num1> <num2>"
	exit
fi

num1=$1
num2=$2

if [[ $num1 -gt $num2 ]]; then #this is numerical comparison, not lexicographical comparison
	echo "$num1 > $num2 numerically"
elif [[ $num1 -lt $num2 ]]; then
	echo "$num1 < $num2 numerically"
else
	echo "$num1 == $num2 numerically"
fi

if (( $num1 != $num2 )); then
	echo "$num1 is numerically not equal to $num2"
fi

if (( $num1 > $num2 )); then #use bash's Arithmetic context to do numerical comparison
	echo "$num1 > $num2 numerically"
elif (( $num1 < $num2 )); then
	echo "$num1 < $num2 numerically"
else
	echo "$num1 == $num2 numerically"
fi

if (( $num1 > $num2 && $num1 < $num2*$num2)); then #logical and (&&) supported in Arithmetic context
	echo "$num1 > $num2 && $num1 < $num2*$num2 numerically"
fi

if [ $num1 -ge 100 -a $num2 -ge 100 ]; then #-a is logical and
	echo "both are >= 100 numerically"
fi
if [ $num1 -ge 100 -o $num2 -ge 100 ]; then #-o is logical or
	echo "at least one of them is >= 100 numerically"
fi


if [ ! $num1 -gt 100 ]; then #! is logical negation
	echo "num1 is <=100 numerically"
fi
if [[ ! $num2 -lt 100 ]]; then
	echo "num2 is >=100 numerically"
fi

if [[ $num1 -ge 100 && $num2 -ge 100 ]]; then #[[ ]] are needed; [] will cause bash to complain
	echo "both of them are >= 100 numerically"
fi

if [[ $num1 -ge 100 || $num2 -ge 100 ]]; then
	echo "at least one of them is >= 100 numerically"
fi

if [[ ! $num1 -ge 100 || ! $num2 -ge 100 ]]; then
  echo "at least one of them is not >=100, or at least one of them is < 100 numerically"
fi

if [[ $num1 == $num2 ]]; then #this is lexicographical comparison, not numerical comparison; try 1000 and 50
	echo "$num1 is lexicographically equivalent to $num2"
elif [[ $num1 > $num2 ]]; then
	echo "$num1 comes after $num2 lexicographically"
else
	echo "$num1 comes before $num2 lexicographically"
fi

if [ $num1 != $num2 ]; then
	echo "$num1 is inequivalent to $num2 lexicographically"
fi