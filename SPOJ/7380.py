x=0
n=1
a=1
for i in range(1,110):
	x=x*10+9
	while 1:
		if a>x:
			print "dig==",i,"n==",n-1
			break
		n+=1
		a *=n
