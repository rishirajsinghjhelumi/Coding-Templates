def f(z):
	global e
	x=int(z.split()[0])
	y=int(z.split()[1])
	if(x>y):
		t=x
		x=y
		y=t
	maxi = 0
	for i in range(x,y+1):
		count = 1
		n=i
		if i in e:
			if e[i] > maxi:
				maxi = e[i]
				continue
		else:
			while n!=1:
				if n in e:
					count = count + e[n] -1
					break
				else:
					if n%2 == 1:
						n = 3 * n + 1
					else:
						n = n / 2
				count = count + 1
		e[i] = count
		if count > maxi:
			maxi = count	
	print x,y,maxi
e={}
done=0
while done!=1:
	try:
		z=raw_input()
		f(z)
	except:
		done=1
