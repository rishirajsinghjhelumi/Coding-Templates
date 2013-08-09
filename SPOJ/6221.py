import sys
x=map(int,sys.stdin.read().split())
l = len(x)
for i in range(1,l,2):
	b,f,ans = bin(x[i+1])[:1:-1],x[i],0
	fac = 1
	for j in b:
		if j=='1':
			ans += fac
		fac *=f
	print ans
