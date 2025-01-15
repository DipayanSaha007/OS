#!/usr/bin/awk -f

BEGIN {
	FS="~"
	if (name=="Subject_1") field=3
	else if (name=="Subject_2") field=4
	else if (name=="Subject_3") field = 5
	else {
		print "Invalid name."
		exit 1
	}
	marks=0

}
NR>1 && NR<6 {
	marks+=$field
}
END {
	avg=marks/4
	print "Average marks for " name ": " avg
} 
