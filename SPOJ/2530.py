def f(n):
	if n==0 or n==1:
		return 1
	if n==2:
		return 5
	if n==3:
		return 11
	return f(n-1)+5*f(n-2)+f(n-3)-f(n-4)
for i in range(input()):
	print i+1,f(input())
