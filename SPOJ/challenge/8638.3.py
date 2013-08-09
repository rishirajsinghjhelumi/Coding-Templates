r,t=range,input
e={0:0,1:1}
for i in r(2,300):e[i]=e[i-1]+e[i-2]
for i in r(t()):
	s=t()
	print sum(e[i] for i in r(i,i+10))+e[i+246]%10
