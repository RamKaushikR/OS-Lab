A=$1
B=$2
C=$3
if [ $A -gt $B -a $A -gt $C ]
then
	echo $A
elif [ $B -gt $C ]
then 	
	echo $B
else
	echo $C
fi
