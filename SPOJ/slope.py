x=0
y=10
for z in range(1000):
	count = 0
	for j in range(x,y):
		b = str(j)
		l = len(b)
		c = 0
		for i in range(1,l-1):
			if b[i-1]>b[i] and b[i+1]>b[i]:
				c +=1
			if b[i-1]<b[i] and b[i+1]<b[i]:
				c +=1
		count +=c
	print x,y,count
	x = y
	y = y + 10
