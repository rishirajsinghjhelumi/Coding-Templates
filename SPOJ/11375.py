t=input()
for i in range(1,t+1):
	x=raw_input().split()
	n=int(x[0])
	m=int(x[1])
	r1 = []
	r2 = []
	spy = 0
	while m:
		m = m - 1
		y=raw_input().split()
		if y[0] in r2:
			spy = 1
		else:
			r1.append(y[0])
		if y[1] in r1:
			spy = 1
		else:
			r2.append(y[1])
	print "Scenario #"+str(i)+":",
	if spy==1:
		print "spied"
	else:
		print "spying"
