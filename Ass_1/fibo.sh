echo "enter the number: " 
read n 
a=0 
b=1 
echo "The fibonacci series:  "  
echo "$a"  
echo "$b" 
for ((i=2;i<n;i++)); do  
	c=$(($a + $b)) 
	echo "$c"  
	a=$b 
	b=$c 
done
