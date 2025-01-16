#!/usr/bin/awk -f
# .awk to get the highest scorer in total

BEGIN {
	FS="~"
	highest=0 
}
NR > 1 && NR < 5 {
	total=$3+$4+$5
	if (highest < total) {
		highest=total
		rec=$0
	}
}
END {
	print "Top Scorer:\n" rec "~" highest
}
