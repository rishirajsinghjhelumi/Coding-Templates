i=0
while i!=10000000000:
	if len(str(i)) == len(str(i*2)):
		b=[]
		c=[]
		for j in str(i):
			b.append(j)
		for j in str(i*2):
			c.append(j)
		b.sort()
		c.sort()
		if b==c:
			print i
	i=i+1
