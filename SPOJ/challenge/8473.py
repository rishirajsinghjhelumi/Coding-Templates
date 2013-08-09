def f(n):
	if n==0:
		return 1
	return n*f(n-1)
x=input
for i in range(x()):
	t=x()
	print f(2*t)/(f(t)**2)

