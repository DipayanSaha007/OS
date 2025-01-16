#!/bin/bash
# Write a shell script to find if a given year is leap yr or not

read -p "Enter a year(Format: YYYY): " y

if ! [[ "$y" =~ ^[0-9]+$ ]]; then
	echo "Invalid year!!"
	exit 1
fi

n=0
if [[ $((y % 4)) == 0 ]]; then
	if [[ $((y % 100)) != 0 ]] || [[ $((y % 400)) == 0 ]]; then
		n=1
	fi
fi

if [[ $n == 1 ]]; then
	echo "$y is a Leap Year."
else
	echo "$y is not a Leap Year."
fi