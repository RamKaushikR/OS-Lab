if [ $# -ne 3 ]
then
	echo Insufficient arguments
	exit 1
fi
case "$2" in
	"+") echo `expr $1 + $3`
	;;
	"-") echo `expr $1 - $3`
	;;
	"*") echo `expr $1 \* $3`
	;;
	"/") if [ $3 -ne 0 ]
	     then
		echo `expr $1 / $3`
	     else 
		echo Invalid
	     fi
	;;
esac 
