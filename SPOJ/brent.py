def gcd(a,b):
	return a if b==0 else gcd(b,a%b)
def brent(n):
	xi,xm,i=2,2,1
	while i:
		xi = (xi*xi + 1)%n
		s = gcd(abs(xi-xm),n)
		if s <> 1 and s <> n:
			return s
		if i&(i-1)==0:
			xm=xi
def brent2(n):
	c = 11
	y, r, q, m = 1, 1, 1, 137
	while 1:
		x = y
		for i in range(1, r + 1):
			y = (y * y + c) % n
			k = 0
			while 1:
				ys = y
				for i in range(1, min(m, r - k) + 1):
					y = (y * y + c) % n
					q = (q * abs(x - y)) % n
					g = gcd(q, n)
					k += m
				if k >=r or g > 1:
					break
		r *= 2
		if g > 1:
			break
	if g == n:
		while 1:
			ys = (ys * ys + c) % n
			g = gcd(abs(x - ys), n)
			if g > 1:
				break
	return g
def factor(n):
	fact=[]
	while n!=1:
		x = brent2(n)
		print x
		n/=x
		fact.append(x)
	fact.sort()
	return fact
for i in factor(input()):
	print i,
