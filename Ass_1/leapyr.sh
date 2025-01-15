echo "Enter a year(in format: YYYY): "
read y
if((y % 400 == 0)); then
	x=1
elif((y % 100 == 0)); then
	x=0
elif((y % 4 == 0)); then
	x=1
else 
	x=0 
fi

if((x==1)); then
	echo "The year $y is a leap year!" 
else 
	echo "The year $y is not a leap year"
fi
