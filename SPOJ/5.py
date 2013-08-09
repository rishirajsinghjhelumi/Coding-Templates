a=0
b=0
c=0
d=1
e=1
x={}
i=4
x[1] = 0
x[2] = 0
x[3] = 0
x[4] = 1
print a
print b
print c
print d
while i<=5394:
	e=a+b+c+d
	print e
	i=i+1
	x[i] = e
	a=b
	b=c
	c=d
	d=e
s=0
for i in range(1919,5395):
	s = s + x[i]
print s%1000000007
