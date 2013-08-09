a=[2,3]
b=2
c=3
for i in range(10001):
	d = b + c
	b = c
	c = d
	a.append(d)
while 1:
	try:
		x=input()
		print a[x-1]
	except:
		break
