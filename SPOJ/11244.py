from math import log
t=input()
while t:
	t=t-1
	p=raw_input().split()
	x=int(p[0])
	y=int(p[1])
	s=int(p[2])
	i=0
	while 1:
		if y*i*i*i*i*i-s*i*i*i+s*i*i-x == 0 :
			break;
		i=i+1
	a=x/(i*i)
	r=1
	n = int(log(y/a)/log(i))+3
	print n
	for j in range(1,n+1):
		print a*r,
		r=r*i
	print
