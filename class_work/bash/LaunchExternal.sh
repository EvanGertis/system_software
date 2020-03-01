#!/bin/bash
#demonstrates launching external programs: type "LaunchExternal.sh LeapYear_cmdline"
#LeapYear_cmdline.c is an example C program in Folio compiled as LeapYear_cmdline

if [ $# -ne 1 ]; then
	echo "usage: $0 <exefile>";
	exit;
fi

for ((i=2000;i<=2020;i=i+1))
do
	#echo "i=$i"
	$1 $i #The first command line argument $1 is supposed to be an executable program to be launched, such as LeapYear_cmdline; $i will be the first command line argument passed to the launched program
done
