def gcd(a,b):
	if b==0:
		return a
	return gcd(b,a%b)
def pollard(n):
	x,y = 2,2
	while 1:
		x1,y1,y1 = x*x+1,y*y+1,y*y+1
		x,y,s = x1%n,y1%n,gcd(abs(x-y),n)
		if s!=1 and s!=n:
			return s
def factor(n):
	fact=[]
	while n!=1:
		x = pollard(n)
		n/=x
		fact.append(x)
	fact.sort()
	return fact
for i in factor(input()):
	print i,
