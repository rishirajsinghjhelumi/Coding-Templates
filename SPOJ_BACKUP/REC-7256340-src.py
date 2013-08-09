import sys
#import psyco
#psyco.full()
def fib(a,b,n,mod):
        m1,m2=a,1
	a1,a2=1,0
        t=1
	while n:
		x,y=m1,m2
		if n&1:
		      t1,t2=a1,a2
		      a1,a2=(x*t1)%mod,(x*t2+y)%mod
		n>>=1
		m1,m2=(x*x)%mod,(x*y+y)%mod
	return(a1+a2*b)%mod
x=map(int,sys.stdin.read().split())
l=len(x)
i=1
while i!=l:
        a,b,n,mod=x[i:i+4]
        print fib(a,b,n,mod)
	i+=4
