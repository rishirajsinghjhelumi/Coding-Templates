def power(n,k):
	temp = 1
	ans=1
	while k>0:
		if k&temp:
			ans = (ans*n)
			k-=temp
		temp <<=1
		n = (n * n)
	return ans;
t=input()
while  t:
	t-=1
	x=raw_input().split()
	a=int(x[0])
	b=int(x[1])
	print "%d/%d"%((power(a,b)-1),(a-1))
