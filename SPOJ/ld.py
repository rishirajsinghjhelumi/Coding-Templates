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
	d=n-1
	s=0
	while d%2==0:
		d>>=1
		s+=1
	for i in range(4):
		a=random.randrange(2,n)
		if is_composite(a,d,n,s):
			return 0
	return 1
a=[]
for i in range(120):
	b = 10**i+1
	while b:
		if miller_rabin(b):
			a.append(b%10)
			print i,b%10
			break
		b+=2
print a
