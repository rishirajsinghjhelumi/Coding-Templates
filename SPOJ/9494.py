while 1:
	x=raw_input().split()
	if x[0] == '0' and x[1] == '0':
		break
	n=int(x[0])
	k=int(x[1])
	print ((n**n) + (n**k) + 2*((n-1)**k + (n-1)**(n-1)))%10000007
