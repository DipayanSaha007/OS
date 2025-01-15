while true; do
	echo "Press 1 to Sort the records in reverse order of Roll number"
	echo "Press 2 to Replace lower case letters with the upper case letters"
	echo "Press 3 to find out the records with unique name"
	echo "Press 4 to Display only the 2nd and 3rd lines"
	echo "Press 5 to Exit"
	echo -e "\nEnter your choice:"
	read ch
	if [[ $ch -eq 1 ]]; then
		sort -t '|' -k2 -r Students.dat>Sorted.dat
		echo -e "Sorted in reverse order of Roll number & stored in 'Sorted.dat'\n"
	elif [[ $ch -eq 2 ]]; then
		tr '[:lower:]' '[:upper:]' < Sorted.dat > Sorted_temp.dat && mv Sorted_temp.dat Sorted.dat
		echo -e "Replaced lower case with upper case & stored in 'Sorted.dat'\n"
	elif [[ $ch -eq 3 ]]; then
		cut -d '|' -f1 Sorted.dat | sort | uniq >> Students.dat
		echo -e "Unique names stored in 'Students.dat'\n"
	elif [[ $ch -eq 4 ]]; then
		sed -n '2,3p' Students.dat
		echo ""
	elif [[ $ch -eq 5 ]]; then
		exit 0
	else
		echo "Invalid Input!!"
	fi
done
