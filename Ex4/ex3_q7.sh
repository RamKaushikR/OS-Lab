if [ $# -lt 3 ]
then
	echo Invalid No. of  Arguments
	exit 1
fi
a=`expr $2 - $1`
a=`expr $a + 1`
head -n $2 $3|tail -n $a
