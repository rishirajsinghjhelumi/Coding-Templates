def fact(n):
	if n==0:
		return 1
	return n*fact(n-1)
for i in range(2,1000):
#print i
	for j in range(i,1000):
		if fact(j) > i**j:
			print j
			break
