r,j=range,input
b=[143,231]
for i in r(40):b[i+2:]=[b[-2]+b[-1]]
for i in r(j()):
	s=b[j()-1]
	print s+s%10
