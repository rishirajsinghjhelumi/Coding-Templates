x=input()
e={}
while x:
	y=input()
	if y in e:
		del e[y]
	else:
		e[y] = 1
	x=x-1
for i in e:
	print i
