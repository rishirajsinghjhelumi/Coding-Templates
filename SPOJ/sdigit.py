a=[[0 for j in range(73)] for i in range(8)]
for i in range(10):
	a[0][i] = 1
x = 18
for i in range(1,8):
	a[i][0] = 1
	a[i][x] = 1
	for j in range(1,10):
		a[i][j] = a[i-1][j]+a[i][j-1]
		a[i][x-j] = a[i][j]
	for j in range(10,x/2+1):
		a[i][j] = a[i-1][j] + a[i][j-1] - a[i-1][j-10]
		a[i][x-j] = a[i][j]
	x+=9
for i in a:
	print i
