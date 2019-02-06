I=5
while [ $I -ge 1 ]
do
	echo -n -e $I
	if [ $I -ne 1 ]
	then
		echo -n -e " "
	else
		echo -n -e "\n"
	fi
	I=`expr $I - 1`
done
