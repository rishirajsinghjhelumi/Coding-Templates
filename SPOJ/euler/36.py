sumi= 0
for i in range(1,1000000):
	a = [x for x in str(i)]
	b = [x for x in reversed(str(i))]
	c=bin(i)[2:]
	d = [x for x in str(c)]
	e = [x for x in reversed(str(c))]
	if d==e and a==b:
		sumi += i
print sumi
