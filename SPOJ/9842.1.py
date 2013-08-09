b=[1]
for i in range(1,15):
	b[i:] = [((b[i-1]*2*(2*i-1))/(i+1))]
for i in range(input()):
	print b[input()]
