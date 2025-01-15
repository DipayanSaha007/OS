echo "Enter a number: "
read n 

if ! [[ "$n" =~ ^[0-9]+$ ]]; then
	echo "ERROR: The number is not a positive number"  
	exit 1 
fi 

s=0 
for ((i=0; i<${#n}; i++)); do 
	digit="${n:$i:1}" 
	s=$((s + digit))
done 
echo "The sum of numbers of $n is: $s" 



