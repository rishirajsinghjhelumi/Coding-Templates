def gcd(a,b):
	if b==0:
		return a
	return gcd(b,a%b)
x=input()
while x:
	x=x-1
	b=int(raw_input().split()[0])
	c=int(raw_input().split()[0])
	print gcd(b,c)
