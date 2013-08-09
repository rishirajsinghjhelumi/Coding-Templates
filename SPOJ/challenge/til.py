from math import *
def f(n,m):
	a=1
     	for i in range(1,int(ceil(m/2))+1):
             for j in range(1,int(ceil(n/2))+1):
                   a=a*4*((cos((pi*j)/(n+1)))**2+(cos((pi*i)/(m+1)))**2)
     	return a
t=input()
while t:
	t-=1
	a,b=map(int,raw_input().split())
	if a%2 and b%2:
		print 0
	else:
		print"%d"%f(a,b)
