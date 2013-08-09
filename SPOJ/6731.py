def fact(n):
	if n==0:
		return 1
	return n*fact(n-1)
while 1:
	try:
		x=raw_input().split()
		n=int(x[0])
		k=int(x[1])
		y=1
		for i in raw_input().split():
			y=y*fact(int(i))
		print fact(n)/y
	except:
		break
