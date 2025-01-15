#!/bin/bash

echo Total number of arguments passed: "$#"
sum=0
for i in $@; do
	sum=$((i + sum))
done
echo "Sum is: $sum"
