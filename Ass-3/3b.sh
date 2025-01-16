#!/bin/bash
# Insert details with p/w & store in 'personal.dat', display the details if p/w matches .sh

while true; do
	echo -e "\n________Menu_______\nEnter 1: Insert personal details \nEnter 2: Display details \nEnter 0: To Exit\n"
	read -p "Enter your choice: " ch
	if [[ $ch -eq 0 ]]; then
		exit 1
	elif [[ $ch -eq 1 ]]; then
		read -p "Enter name: " name
		read -p "Enter roll: " roll
		read -p "Enter password: " pw
		echo "$name | $roll | $pw" >> Personal.dat
	elif [[ $ch -eq 2 ]]; then
		read -p "Enter Password to see personal details: " pass
		n=$(cat Personal.dat | grep $pass | cut -d "|" -f 1)
		r=$(cat Personal.dat | grep $pass | cut -d "|" -f 2)
		if [[ -z $n || -z $r ]]; then
			echo "Wrong Password"
		else
			echo -e "Name: $n\nRoll: $r"
		fi
	else
		echo "Invalid input"
	fi


done

