from math import *
r=range
for i in r(input()):
	n,m=map(int,raw_input().split())
	x=1
     	for i in r(1,int(ceil(n/2))+1):
             for j in r(1,int(ceil(m/2))+1):
                   x*=4*(cos(pi*i/(n+1))**2+cos(pi*j/(m+1))**2)
	print 0 if n&1 and m&1 else"%d"%x
