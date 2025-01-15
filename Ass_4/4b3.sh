#!/bin/bash

if [[ "$#" -ne 2 ]]; then
	echo "Usage: ./4b3.sh <input_file_name> <subject_name>"
	exit 0
fi
subject_name=$2
file=$1
if  [ "$subject_name" != "Subject_1" ] && [ "$subject_name" != "Subject_2" ] && [ "$subject_name" != "Subject_3" ]; then
    echo "Invalid subject name. Must be 'Subject_1', 'Subject_2', or 'Subject_3'."
    exit 1

fi
 
awk -v name="$subject_name" -f 4b3.awk "$file"  
