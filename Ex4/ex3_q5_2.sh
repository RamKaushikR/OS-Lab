s=$1
for i in $(seq 1 $s)
do
	j=`expr 10 - $i`
	for k in $(seq 1 `expr $j - 1`)
	do
		echo -n " "
	done
	for k in $(seq 1 $i)
	do
		echo -n "$i "
	done
	echo ""
done
