def fact(n):
	if n==0:
		return 1
	return n*fact(n-1)
mod = 1<<32
for i in range(1,20):
	ans = 0
	for j in range(1,i):
		ans += (fact(i-1)/fact(j)/fact(i-j-1)) * (9**(i-j))
	print ans % mod,",",
