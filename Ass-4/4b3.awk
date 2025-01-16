#!/usr/bin/awk -f
# .awk to get avg markes for a given subject

BEGIN {
	FS="~"
	sum=0
	total=0
	print "Enter subject number: (1 for 'Subject_1', 2 for 'Subject_2', 3 for 'Subject_3')\n"
	getline n < "-"
}
NR > 1 && NR < 5 {
	if (n == 1)
		total=$3
	else if (n == 2)
		total=$4
	else if (n == 3)
		total=$5
	else {
		print "Wrong input"
		exit
	}
	sum+=total
}
END {
	if (sum != 0) {
		print "Average Score of Subject_" n ": " sum/3
	}
	else {
		exit
	}

}

