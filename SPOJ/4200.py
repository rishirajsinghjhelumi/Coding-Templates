from math import *
t=input()
while t:
	t=t-1
	x=raw_input().split()
	v=int(x[0])
	k1=int(x[1])
	k2=int(x[2])
	pi=2*acos(0.0)
	if k2==0:
		theta = pi/4
	else:
		theta = (pi+atan((-4.0*k1)/k2))/2
	ans = (((v*v)/(10))*(k1*sin(2.0*theta)))+(((v*v)/10)*((k2*sin(theta)*sin(theta))/2))
	print round(theta,3),round(ans,3)
