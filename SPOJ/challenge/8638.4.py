r,j=range,input
b=[0,1]
for i in r(300):b[i+2:]=[b[-2]+b[-1]]
for i in r(j()):
	s=j()
	x=sum(b[s:s+10])
	print x
