a=0
b=1
i=2
x=['0','1']
while i!=100000:
	c = a + b
	a = b
	b = c
	x.append(str(b)[:40])
	i+=1
for i in x:
	print i
