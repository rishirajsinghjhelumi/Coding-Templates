t=input()
while t:
	t-=1
	x=raw_input().split()
	a=raw_input()
	l = len(a)
	b=[a[i:]+a[:i] for i in range(l)]
	b.sort()
	for i in b:
		print i
