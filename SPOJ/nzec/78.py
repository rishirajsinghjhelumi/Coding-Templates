def fact(n):
	if n==0:
		return 1
	return n*fact(n-1)
x=int(input())
while x:
	x=x-1
	xx=input()
	y=int(xx.split()[0])
	z=int(xx.split()[1])
	print (round(fact(y-1)/(fact(z-1)*fact((y-z)))))
