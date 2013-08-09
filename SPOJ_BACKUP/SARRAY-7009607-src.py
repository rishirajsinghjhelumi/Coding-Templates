x=raw_input()
l=len(x)
e={}
a=[x[i:] for i in range(l)]
for i in range(l):
	e[a[i]] = i
a.sort()
for i in a:
	print e[i]
