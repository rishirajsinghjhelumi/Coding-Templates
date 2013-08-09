import sys
import psyco
psyco.full()
def fib(a,b,n,mod):
        m1,m2,a1,a2=a,1,1,0
	while n:
		if n&1:
		      a1,a2=(m1*a1)%mod,(m1*a2+m2)%mod
		n>>=1
		m2,m1=(m1*m2+m2)%mod,(m1*m1)%mod
	return(a1+a2*b)%mod
x=map(int,sys.stdin.read().split())
l=len(x)
i=1
while i!=l:
        a,b,n,mod=x[i:i+4]
        print fib(a,b,n,mod)
	i+=4
