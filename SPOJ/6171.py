t=input()
while t:
	t=t-1
	n=input()
	count = n/2 + 1
	y=raw_input().split()
	e={}
	d=1
	for i in y:
		if i in  e:
			e[i] = e[i] + 1
		else:
			e[i] = 1
	for i in e:
		if e[i] >= count:
			print "YES",i
			d=0
			break
	if d==1:
		print "NO"
