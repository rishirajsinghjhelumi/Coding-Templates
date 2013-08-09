def sumgp(r,n):
	return n if n<2 else (1+pow(r,n/2))*sumgp(r,n/2) + (pow(r,n-1) if n%2 else 0)
r,n=map(int,raw_input().split())
print sumgp(r,n)
