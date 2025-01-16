#!/bin/bash
# write a shell script to get log of an command line input number

if [[ "$#" -ne 1 ]]; then
       echo "Usage: $0 <positive_integer>"
       exit 1
fi

N=$1
if ! [[ "$N" =~ ^[0-9]+$ ]]; then
       echo "Number must be <positive_integer>"
       exit 1
fi

log=$(awk -v n=$N 'BEGIN {printf "%.2f\n", log(n)/log(10)}' )
echo "The logarithm of $N = $log"