#!/bin/bash
# show permission, number of files, last modification time of a file or directory using .sh
echo "Current Directory: $(pwd)"
read -p "Enter file/directory name: " n
if [ ! -e "$n" ]; then
	echo "Invalid Input"
	exit 1
fi
while true; do
	echo -e "\n________Menu_______\nEnter 1: Show permission of file/directory \nEnter 2: Show no. of file/directory under current directory \nEnter 3: Show last modification time\nEnter 0: To Exit\n"
	read -p "Enter your choice: " ch
	if [[ $ch -eq 0 ]]; then
		exit 1
	elif [[ $ch -eq 1 ]]; then
		echo "Permissions of '$n': $(ls -l | grep $n | cut -d " " -f 1)"
	elif [[ $ch -eq 2 ]]; then
		echo -e "Under current directory:- Number of files:  $(ls -l | cut -d " " -f 1 | grep "-" | wc -l)\n\tNumber of directories: $(ls -l | cut -d " " -f 1 |  grep "d" | wc -l)"
	elif [[ $ch -eq 3 ]]; then
		echo -e "Last modification of '$n': $( ls -l | grep $n | cut -d " " -f 6-8 )\n AND: $(stat -c %y "$n")"
	else
		echo "Invalid input"
	fi


done
