t=input()
while t:
	t=t-1
	x=input()
	a=round(0.5+0.5*(0.5-(1.0/((x+1)*(x+2)))),11)
	print str(a)+(13-len(str(a)))*'0'
