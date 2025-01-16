#!/bin/bash
# Write a .sh to do Ass-4 a)

while true; do
	echo -e "\n________MENU________\nEnter 1: To sort in reverse order of roll & store in 'Sorted.dat'\nEnter 2: Replace lower case with upper case & store in 'Sorted.dat'\nEnter 3: To find unique names & store into 'Students.dat'\nEnter 4: To display 2nd and 3rd lines from 'Students.dat'\nEnter 0: To Exit\n"
	read -p "Enter your choice: " ch
	if [[ $ch -eq 0 ]]; then
		exit 1
	elif [[ $ch -eq 1 ]]; then
		echo "Done & stored in 'Sorted.dat'. $(cat Students.dat | sort -t "|" -k 2 -r -o Sorted.dat)"
	elif [[ $ch -eq 2 ]]; then
		echo "Done & srored in 'Sorted.dat'. $(cat Sorted.dat | tr [:lower:] [:upper:] > Sorted.dat)"
	elif [[ $ch -eq 3 ]]; then
		echo "Done & stored in 'Students.dat'. $(cat Sorted.dat | cut -d "|" -f 1 | sort | uniq >> Students.dat)"
	elif [[ $ch -eq 4 ]]; then
		sed -n 2,3p Students.dat
	else
		echo "Invalid choice"
	fi

done
