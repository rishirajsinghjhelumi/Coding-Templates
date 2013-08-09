x=input()
while x:
	x=x-1
	known=0
	a=[]
	r=raw_input()
	for d in [r[i:j] for i in range(len(r)) for j in range(len(r)+1)]:
		try:
			y=int(d)
			known=known+1
			a.append(y)
		except:
			continue
	for i in a:print i
