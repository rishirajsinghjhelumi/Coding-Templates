a=0
x=[]
while a<2**20:
	x.append(int(bin(a)[2:]))
	a+=1
a=input()
while a:
	a-=1
	y=input()
	r=1
	while 1:
		if x[r]%y==0:
			break
		r+=1
	print x[r]
