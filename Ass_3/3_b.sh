while true; do
	echo "Enter 1 to accept personal details and store them"
	echo "Enter 2 to display the details"
	echo "Enter 3 to exit"
	read ch
	if [[ $ch -eq 1 ]]; then
		read -p "Enter name: " name
		read -p "Enter roll no.: " roll
		read -p "Enter password: " pass
		echo "$name $roll $pass">>personal.dat
	elif [[ $ch -eq 2 ]]; then
		read -p "Enter password to see details: " pass
		name=$( cat personal.dat | grep $pass | cut -d " " -f 1 )
		roll=$( cat personal.dat | grep $pass | cut -d " " -f 2 )
		if [[ -z $name || -z $roll ]]; then
			echo "Wrong password"
		else
			echo "Username: $name"
			echo "Roll No.: $roll"
		fi
	elif [[ $ch -eq 3 ]]; then
		exit 0
	fi
done
