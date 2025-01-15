#!/bin/bash 

if [ "$#" -ne 1 ]; then 
	echo "Usage: $0 <positive_integer>"
	exit 1 
fi 
N="$1"
if ! [[ "$N" =~ ^[0-9]+$ ]]; then 
	echo "Error: Input must be a positive integer"  
	exit 1 
fi 
if ((N <= 0)); then  
	echo "Error: Input must be greater than zero"  
	exit 1 
fi 

log10=$(echo "scale=10; l($N) / l(10)" | bc -l)  
log=$(printf "%.2f" "$log10")
echo "The common logarithm of $N is: $log"
