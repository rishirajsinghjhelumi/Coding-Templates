def power(n,k,mod):
	temp = 1
	ans=1
	while k>0:
		if k&temp:
			ans = (ans*n)%mod
			k-=temp
		temp <<=1
		n = (n * n)%mod
	return ans%mod
fib=[1,1]
i=2
while i!=1000001:
	fib[i:] = [fib[-1]+fib[-2]]
	i+=1
t=input()
while t:
	t=t-1
	x=input()
	print power(2,fib[x-1],1000000007)
