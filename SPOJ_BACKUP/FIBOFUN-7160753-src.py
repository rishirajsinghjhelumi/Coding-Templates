def fib(n,mod):
	a=1
	b=0
	p=0
	q=1
	prev_a=0 
	prev_p = 0
	while n>0:
		if n%2==0:
			prev_p = p
			p = (p*p + q*q)%mod
			q = (2*prev_p*q + q*q)%mod
			n >>= 1
		else :
			prev_a = a
			a = (b*q + a*q + a*p)%mod
			b = (b*p + prev_a*q)%mod
			n-=1
	return b
t=input()
while t:
	t-=1
	x=raw_input().split()
	a=int(x[0])
	b=int(x[1])
	n=int(x[2])
	mod=int(x[3])
	ans = ((a*fib(n,mod))%mod + (b*fib(n+1,mod))%mod-b+mod)%mod;
	print ans
