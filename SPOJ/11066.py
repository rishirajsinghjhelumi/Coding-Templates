import math
x=input()
while x:
	x=x-1
	b=raw_input().split()
	b[0] = int(b[0])
	b[1] = int(b[1])
	b[2] = int(b[2])
	p=(7*b[0]+5*b[1]+2*b[2])*1.0/(2*(b[0]+b[1]))
	n=p+math.sqrt(p*p-((12*b[2])/(b[0]+b[1])))
	d=(b[1]-b[0])/(n-6)
	a=(b[0] - 2*d)
	print int(n)
	for i in range(int(n)):
		print int(round(a+d*i)),
	print
