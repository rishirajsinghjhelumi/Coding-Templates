def gcd(a,b):
	if b==0:
		return a
	return gcd(b,a%b)
x=int(input())
while x:
	x=x-1
	b=input()
	c=input()
	print (gcd(b,c))
