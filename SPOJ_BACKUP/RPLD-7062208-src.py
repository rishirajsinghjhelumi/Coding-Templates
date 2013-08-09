t=input()
for i in range(1,t+1):
	b={}
	x=raw_input().split()
	m = int(x[1])
	poss = 1
	while m:
		m = m - 1
		x=raw_input().split()
		if (x[0],x[1]) in b:
			poss = 0
			break
		else:
			b[(x[0],x[1])] = 1
	while m:
		x=raw_input()
		m=m-1
	print "Scenario #"+str(i)+":",
	if poss==1:
		print "possible"
	else:
		print "impossible"
