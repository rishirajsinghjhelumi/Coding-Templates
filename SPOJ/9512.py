while 1:
	x=raw_input().split()
	n = int(x[0])
	m = int(x[1])
	if m|n == 0:
		break
	ex={}
	ey={}
	i=0
	j=0
	count=[]
	while i!=n:
		x=raw_input().split()
		a = int(x[0])
		b = int(x[1])
		if a in ex:
			ex[a].append(b)
		else:
			ex[a] = [b]
		if b in ey:
			ey[b].append(a)
		else:
			ey[b] = [a]
		i+=1
	while j!=m:
		x=raw_input().split()
		c = int(x[0])
		d = int(x[1])
		if c==0:
			if d in ex:
				print len(ex[d])
				for i in ex[d]:
					ey[i].remove(d)
				del ex[d]
			else:
				print 0
		if c==1:
			if d in ey:
				print len(ey[d])
				for i in ey[d]:
					ex[i].remove(d)
				del ey[d]
			else:
				print 0
		j+=1
