#!/bin/bash

#string

var=evan
if [ $1 = $var ] ; then echo "string $1 = $var "   ; fi 
if [ $1 == $var ] ; then echo "string $1 == $var " ; fi
if [ $1 != $var ] ; then echo "string $1 != $var " ; fi
if [ $1 \< $var ] ; then echo "string $1 is less than $var " ; fi
if [[ $1 > $var ]] ; then echo "string $1 greater than $var " ; fi
if [ -n $1 ] ; then echo "string $1 is not  empty " ; fi
if [ -z $1 ] ; then echo "string $1  is empty " ; fi

#numeric
a=1

if [ $a -eq $1 ] ; then echo "number $a equals $1 " ; fi
if [ $a -ne $1 ] ; then echo "number $a does not equal $1 " ; fi
if [ $a -gt $1 ] ; then echo "number $a is greater than $1 " ; fi
if [ $a -lt $1 ] ; then echo "number $a is less than $1 " ; fi

#file/dir

if [ -d $1 ] ; then echo "$1 exists and is a directory " ; fi
if [ -e $1 ] ; then echo "$1 exists " ; fi
if [ -f $1 ] ; then echo "$1 exists and is not a directory! " ; fi
if [ -r $1 ] ; then echo "$1 exists and is readable " ; fi
if [ -s $1 ] ; then echo "$1 exists and has a size greater than 0 " ; fi
if [ -w $1 ] ; then echo "$1 exists and is writable" ; fi
if [ -x $1 ] ; then echo "$1 exists and is executable" ; fi
