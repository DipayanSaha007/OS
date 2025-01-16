#!/bin/bash
# write a .sh to sort array from command line argument inputs

if [[ $# -lt 1 ]]; then
	echo "Usage: <filename> <positive_integers>"
	exit 1
fi
echo "Total number of arguments: $#"
bSort() {
	a=("$@")
	n=$#
	local s
	for ((i=0;i<n-1;i++)); do
		s=0
		for ((j=0;j<n-i-1;j++)); do
			if ((a[j] > a[j+1])); then
				t=${a[j]}
				a[j]=${a[j+1]}
				a[j+1]=$t
			fi
			s=1
		done
		if (( $s == 0 )); then
			break 
		fi
	done
	echo "${a[@]}"
}
sorted_array=$(bSort "$@")
echo "Sorted array: $sorted_array"
