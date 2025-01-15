while true; do
	echo "Enter 1 to show the permissions of a file or directory"
	echo "Enter 2 to show the number of files and directories under current directory separately"
	echo "Enter 3 to show the last modification time of a file in current directory"
	echo "Enter 4 to exit from menu"
	read ch
	if [[ $ch -eq 1 ]]; then
		read -p "Enter file or directory name: " n
		if [[ $n == "" ]]; then
			echo "Invalid Input"
		else
			echo "$( ls -l | grep $n | cut -d " " -f 1 )"
		fi
	elif [[ $ch -eq 2 ]]; then
		echo "Number of files: $( ls -l | cut -d " " -f 1 | grep "^[-]" | wc -l )"
		echo "Number of directories: $( ls -l | cut -d " " -f 1 | grep "d" | wc -l )"
	elif [[ $ch -eq 3 ]]; then
		read -p "Enter file name: " n
		if [[ $n == "" ]]; then
			echo "Invalid Input"
		else
			echo "$( ls -l | grep $n | cut -d " " -f 7-9 )"
		fi
	elif [[ $ch -eq 4 ]]; then
		exit 0
	fi
done
