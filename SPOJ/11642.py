x=input()
for i in range(1,51):
	if i*(i-1)==2*x:
		n = i
		break
c=[]
for i in raw_input().split():
	c.append(int(i))
for i in range(1,c[0]/2+1):
	a=[]
	b=[]
	check=1
	for l in c:
		b.append(l)
	a.append(i)
	for j in range(n-1):
		for k in range(j):
				try:
					b.remove(a[k]+a[-1])
				except:
					check = 0
					break
		a.append(b[0]-a[0])
		if check==0:
		   	break
	if check:
		for k in range(j+1):
				try:
					b.remove(a[k]+a[-1])
				except:
					check = 0
					break
	if b==[]:
	 	break
if len(a)==n:
	for i in a:
		print i,
	print
