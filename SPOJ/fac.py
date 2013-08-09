f=[1]
for i in range(1,1001):
	x = i
	while x%41==0:
		x/=41
	f[i:] = [f[i-1]*x]
for i in range(1001):
	print f[i]
