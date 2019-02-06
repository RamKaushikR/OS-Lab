if [ $# -lt 1 ]
then
	echo "More arguments required"
	exit 1
fi
FILE="$1"
if [ -e "$FILE" ]
then
	echo "$FILE exists"
else
	echo "$FILE does not exists"
fi
