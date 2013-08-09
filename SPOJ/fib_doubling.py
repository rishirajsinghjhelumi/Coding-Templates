def fibonacci(n):
	if n == 0:
		return (0, 1)
	else:
		a , b = fibonacci(n>>1)
		c = a * (2 * b - a)
		d = b * b + a * a
		return (d, c + d) if n&1 else(c,d)
