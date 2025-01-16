#!/bin/bash
# write a shell script to find factorial of a user given number

read -p "Enter a number: " n

if ! [[ "$n" =~ ^[0-9]+$ ]]; then
	echo "Usage: <filename> <positive_integer>"
	exit 1
fi

fact=1
for ((i=1;i<=n;i++)); do
	fact=$((fact*i))
done
echo "Factorial of $n: $fact"