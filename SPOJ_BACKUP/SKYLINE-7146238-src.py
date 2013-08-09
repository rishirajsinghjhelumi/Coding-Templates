b=[1]
for i in range(1,1001):
	b[i:] = [((b[i-1]*2*(2*i-1))/(i+1))]
while 1:
	x=input()
	if x==0:
		break
	print b[x]%1000000
