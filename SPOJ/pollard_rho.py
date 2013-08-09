import random
def gcd(a,b):
	return a if b==0 else gcd(b,a%b)
def rho(n):
	if n%2==0:
		return (2,1)
	x,y,c,d=2,2,1,1
	while d==1:
		x = ( (x*x)%n + c )%n
		y = ( (y*y)%n + c )%n
		y = ( (y*y)%n + c )%n
		d = gcd(abs(x-y),n)
	x = 1 if d!=n else 0
	return(d,x)
def factor(n):
	fact=[]
	while n!=1:
		y = rho(n)
		x = y[0]
		n/=x
		fact.append(x)
	fact.sort()
	return fact
for i in factor(input()):
	print i,
