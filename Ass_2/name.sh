n="$1"
if ((${#n} < 5)) || ((${#n} > 15)); then
	echo "The size of username can not be less than '5' or more than '15'"
	exit 1
fi
if ! [[ "$n" =~ ^[a-zA-Z0-9_@#]+$ ]]; then
	echo "The username can only have a-z,A-Z,0-9,_,@,#"
	exit 1
fi
echo "The user name $@ is valid!"
