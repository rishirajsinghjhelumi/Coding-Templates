sum1=0
for x in range(1,20):
	m=1<<x
	p_m = 1<<(x-1)
	count = 0
	for i in range(p_m+1,m+1):
		a=bin(i)[2:]
		c1=0
		c0=0
		for j in a:
			if j=='0':
				c0+=1
			else:
				c1+=1
		if c0==c1:
			count +=1
	sum1+=count
	print m,count,sum1
