#!/bin/bash
function printProduct() {
i=$1
while [ $i -lt 4 ] ;
do
        j=$2
        echo "$i*$j=$((i*j))"
        while [ $j -lt 6 ] ;
        do
                echo "$i*$j=$((i*j))"
                let j++
        done
        let i++
done
}

printProduct 1 2
