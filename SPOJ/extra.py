e={}
x=1
while 1:
	if x in e:
		print x
		break
	else:
		e[x]=1
	x=(x+1234567890)%2147483648
