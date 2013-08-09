read t
for((;t;t--))
do
	read a b;
	c=$(echo "$a^$b-1" | bc)
	d=$(echo "$a-1" | bc)
	for i in $c
	do
		a=`echo $i | cut -c1-68`
		echo -ne $a
	done
	echo /$d
done
