import random
def is_composite(a,d,n,s):
	if pow(a,d,n)==1:
		return 0
	for i in range(s):
		if pow(a,(1<<i)*d,n)==n-1:
			return 0
	return 1
def miller_rabin(n):
	if n==2:
		return 1
	if (n%2==0 and n!=2) or (n%3==0 and n!=3) or (n%5==0 and n!=5):
		return 0
	d,s=n-1,0
	while d%2==0:
		d,s = d>>1,s+1
	a=random.randrange(2,n)
	if is_composite(a,d,n,s):
		return 0
	return 1
t=input()
while t:
	t-=1
	check = miller_rabin(input())
	print "YES" if check else "NO"
