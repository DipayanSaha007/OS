#!/bin/bash
echo Total number of arguments: "$#"
bsort() {
	local a=("$@")
	local n=$#
	local s
	for ((i=0; i<n-1; i++)); do
		s=0
		for ((j=0; j<n-i-1; j++)); do
			if (( a[j] > a[j+1] )); then
				t=${a[j]}
				a[j]=${a[j+1]}
				a[j+1]=$t
				s=1
			fi
		done
		if (( $s == 0 )); then
			break
		fi
	done
	echo "${a[@]}"
}
if (( $# == 0 )); then
	echo "Please provide integers to sort."
	exit 1
fi
sorted_array=$(bsort "$@")
echo "Sorted array: $sorted_array"
