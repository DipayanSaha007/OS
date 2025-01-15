fact=1
echo "Enter the number "
read n
for((i=1;i<=$n;i++)); do
	fact=$((fact*i))
done
echo "The factorial is: $fact"
