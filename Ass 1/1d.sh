#!/bin/bash
# white a .sh to get fibonacci series

read -p "Enter the range: " n
if ! [[ "$n" =~ ^[0-9]+$ ]]; then
	echo -e "Usage: The number must be <positive_integer>\n"
	exit 1
fi
a=0
b=1
if [[ $n -eq 0 ]]; then
	echo -e "Range is 0 T_T"
elif [[ $n -eq 1 ]]; then
	echo "Fibonacci Series: $a"
elif [[ $n -eq 2 ]]; then
	echo "Fibonacci Series: $a, $b"
elif [[ $n -gt 2 ]]; then
	echo -n "Fibonacci Series: $a, $b"
	for ((i=2;i<n;i++)); do
		c=$((a+b))
		echo -n ", $c"
		a=$b
		b=$c
	done
	echo
else
	echo "Code is wrong.."
fi
