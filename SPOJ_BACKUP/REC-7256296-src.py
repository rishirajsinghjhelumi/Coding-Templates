import sys
import psyco
psyco.full()
def fib(a,b,n,mod):
        m=(a,1,0,1)
	ans=(1,0,0,1)
        t=1
	while n:
		x,y,z,w=m
		if n&1:
		      t1,t2,t3,t4=ans
		      ans=(x*t1+y*t3)%mod,(x*t2+y*t4)%mod,0,1
		n>>=1
		m=(x*x+y*z)%mod,(x*y+y*w)%mod,0,1
	return(ans[0]+ans[1]*b)%mod
x=map(int,sys.stdin.read().split())
l=len(x)
i=1
while i!=l:
        a,b,n,mod=x[i:i+4]
        print fib(a,b,n,mod)
	i+=4
