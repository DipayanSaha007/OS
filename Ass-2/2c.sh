#!/bin/bash
# write a .sh to check valid username from command line argument

n="$1"
if [[ $# -ne 1 ]]; then
	echo "Usage: <programname> <username>"
	exit 1
fi
if [[ ${#n} -lt 5 ]] || [[ ${#n} -gt 20 ]]; then
	echo "Username can only be of 5-20 charecters"
	exit 1
fi
if ! [[ $n =~ ^[a-zA-Z0-9@#_]+$ ]]; then
	echo "Username can only contain a-z,A-Z,0-9,@,#,_ "
	exit 1
fi
echo "Username $n is valid."
