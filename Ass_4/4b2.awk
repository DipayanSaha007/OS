#!/usr/bin/awk -f

BEGIN {FS="~"; highest1=0}; NR>1 && NR<6 {total1=$3; if(highest1<total1) {highest1=total1; rec1=$0}}; END {print rec1"~"highest1"~Subject_1"} 
BEGIN {FS="~"; highest2=0}; NR>1 && NR<6 {total2=$4; if(highest2<total2) {highest2=total2; rec2=$0}}; END {print rec2"~"highest2"~Subject_2"} 
BEGIN {FS="~"; highest3=0}; NR>1 && NR<6 {total3=$5; if(highest3<total3) {highest3=total3; rec3=$0}}; END {print rec3"~"highest3"~Subject_3"}  
