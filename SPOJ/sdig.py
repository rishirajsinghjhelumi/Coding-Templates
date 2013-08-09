a=[[0 for j in range(10)] for i in range(55)]
for i in range(0,1000000):
	b = str(i)
	s = sum([int(j) for j in b])
	a[s][int(b[-1])] += 1
for i in a:
	print i
