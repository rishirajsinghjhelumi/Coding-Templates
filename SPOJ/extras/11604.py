import math
t=input()
while t:
	t=t-1
	n=raw_input()
	x=long(n.split()[0])
	y=long(n.split()[1])
	z=long(n.split()[2])
	a=((z*x+z*(math.sqrt(x*x+y*y+2*y)))/(y+2*z))
	if a==int(a) and a<x:
		print int(round(a))
	else:
		print "Not this time."
