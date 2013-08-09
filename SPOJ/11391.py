from itertools import combinations
t=input()
while t:
	t-=1
	x = raw_input().split()
	n = int(x[0])
	m = int(x[1])
	a = int(x[2])
	d = int(x[3])
	x=[]
	for i in range(5):
		x[i:] =[a+i*d]
	b=[]
	r1 = 0
	r2 = 0
	sign=1
	n-=1
	for i in range(1,6):
		c = combinations(x,i)
		for j in c:
			d = 1
			for l in j:
				d *=l
			if sign==1:
			 	r1 += n/d
			 	r2 += m/d
			else:
			 	r1 -= n/d
				r2 -= m/d
			print d
		sign *= -1
	print (m-n+1)-(r2-r1)
