#!/bin/bash
# Write a shell script to find sum of digits & show errors

read -p "Enter number: " num

if ! [[ "$num" =~ ^[0-9]+$ ]]; then
	echo "Usage: Number must be <positive_integer>"
	exit 1
fi

digits=0
sum=0
for ((i=0;i<${#num};i++)); do
	digits=${num:$i:1}
	sum=$((sum + digits))
done

echo "Sum of digits of $num: $sum"