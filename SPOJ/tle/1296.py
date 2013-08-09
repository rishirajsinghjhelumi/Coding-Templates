x,y,z,w=[],[],[],[]
n=input()
for i in range(n):
	inp=raw_input()
	x.append(int(inp.split()[0]))
	y.append(int(inp.split()[1]))
	z.append(int(inp.split()[2]))
	w.append(int(inp.split()[3]))
a=[(i,j,k,l) for i in x for j in y for k in z for l in w if i+j+k+l==0]
print len(a)
