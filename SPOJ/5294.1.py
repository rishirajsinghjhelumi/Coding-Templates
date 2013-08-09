import sys,copy
def fib(a,b,n,mod):
	m=[a,1,0,1]
	a=[1,0,0,1]
	while n:
		if n&1:
			t=[0]*4
			t[0] = (m[0]*a[0]+m[1]*a[2])%mod
			t[1] = (m[0]*a[1]+m[1]*a[3])%mod
			t[2] = (m[2]*a[0]+m[3]*a[2])%mod
			t[3] = (m[2]*a[1]+m[3]*a[3])%mod
			a = copy.copy(t)
		n>>=1
		t=[0]*4
		t[0] = (m[0]*m[0]+m[1]*m[2])%mod
		t[1] = (m[0]*m[1]+m[1]*m[3])%mod
		t[2] = (m[0]*m[2]+m[2]*m[3])%mod
		t[3] = (m[2]*m[1]+m[3]*m[3])%mod
		m = copy.copy(t)
	return (a[0]+a[1]*b)%mod
x=map(int,sys.stdin.read().split())
a=len(x)
for i in range(1,a,4):
	a,b,n,mod=x[i:i+4]
	if mod==1:
		print 1
	elif n==0:
		print 1
	else:
		print fib(a,b,n,mod)
