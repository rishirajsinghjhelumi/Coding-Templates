t=input()
while t:
	t=t-1
	y=raw_input()
	a=int(y.split()[0])
	b=int(y.split()[1])
	print abs(a*a-2*b)
