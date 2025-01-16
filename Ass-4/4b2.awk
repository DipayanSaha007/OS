#!/usr/bin/awk -f
# .awk to get top scorer for each subject

BEGIN {
	FS="~"
	h1=0
	h2=0
	h3=0
}
NR > 1 && NR < 5 {
	t1=$3
	if (h1 < t1) {
		h1=t1
		rec1=$0
	}
	t2=$4
	if (h2 < t2) {
		h2=t2
		rec2=$0
	}
	t3=$5
	if (h3 < t3) {
		h3=t3
		rec3=$0
	}
}
END {
	print "Top Scorers:\n" rec1 "~Subject_1\n" rec2 "~Subject_2\n" rec3 "~Subject_3"
}
