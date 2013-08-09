import random
def power(n,k,mod):
	temp = 1
	ans=1
	while k>0:
		if k&temp:
			ans = (ans*n)%mod
			k-=temp
		temp <<=1
		n = (n * n)%mod
	return ans%mod;
def is_composite(a,d,n,s):
	if power(a,d,n)==1:
		return 0
	for i in range(s):
		if power(a,(1<<i)*d,n)==n-1:
			return 0
	return 1
def miller_rabin(n):
	if n==2:
		return 1
	if (n%2==0 and n!=2) or (n%3==0 and n!=3) or (n%5==0 and n!=5):
		return 0
	d=n-1
	s=0
	while d%2==0:
		d>>=1
		s+=1
	for i in range(10):
		a=random.randrange(2,n)
		if is_composite(a,d,n,s):
			return 0
	return 1
t=input()
while t:
	t-=1
	check = miller_rabin(input())
	if check:
		print "YES"
	else:
	 	print "NO"
