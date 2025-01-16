#!/bin/bash
# write a .sh to get sum of integers passed as command line arguments

if [[ "$#" -eq 0 ]]; then
	echo "Usage: <filename> <positive_integers>"
	exit 1
fi

echo "Number of argument passed: $#"
sum=0
for i in $@; do
	sum=$((sum+i))
done
echo "Summation of $# natural numbers: $sum"
