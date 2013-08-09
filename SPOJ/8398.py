import sys,re
t=input()
while t:
	t-=1
	y = raw_input()
	a,b,c=1,0,0
	z = re.search("x\*x",y).span()
	if y[z[0]-1]=='*':
		a = int(y[:z[0]-1])
	else:
		try:
			a = int(y[:z[0]])
		except:
			a = 1
	try:
		z1 = re.search("\*x",y[z[1]:]).span()
		b = int(y[z[1]:z1[0]])
	except:
		b=0
	try:
		z2 = re.search("=",y[z1[1]:]).span()
		c = int(y[z1[1]:z2[0]])
	except:
		b=0
	print a,b,c
