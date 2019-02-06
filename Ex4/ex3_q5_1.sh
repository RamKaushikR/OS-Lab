a=$1
for x in $(seq 1 $a)
do
	for y in $(seq 1 $x)
	do
		echo -n "* "
	done
	echo ""
done
