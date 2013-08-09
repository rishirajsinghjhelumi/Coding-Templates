pz=input()
while 1:
	a=[]
	while 1:
		try:x=raw_input()
		except:break
		try:
			z=int(x)
			break
		except:a.append(x[::-1].split())
	if a==[]:break
	for i in reversed(a):
		for j in i:print (pz-1)*(j+' ')+j,
	print
	pz=z
