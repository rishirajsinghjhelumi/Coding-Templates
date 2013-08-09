mod = 250000001*2
a=[1]
for i in range(1,501):
	x = (4*i-2)/i
	y = (4*i-2)%i
	a[i:] = [(x*a[-1] + (a[-1]/i)*y)]
for i in a:
	print i%mod
