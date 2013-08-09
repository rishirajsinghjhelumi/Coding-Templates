def p(n):
	b=[6,2,4,8]
	if n< 1:
		return 1
	return b[n%4]
def f(n):
	a=[1,1,2,6,4]
	if n<5:
		return a[n]
	return (p(n/5)*f(n/5)*f(n%5))%10
while 1:
	try:
		x=raw_input()
		for i in x.split():
			print f(int(i))
	except:
		break
