a = [i for i in range(3,35000,2)]
b=[2]
while len(b)<3000:
	if len(a)<a[0]:
		b.extend(a)
		break
	b.append(a[0])
	del a[::a[0]]
while 1:
	x=input()
	if x==0:
		break
	else:
		print b[x-1]
