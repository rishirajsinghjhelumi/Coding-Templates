x=raw_input()
y=raw_input()
a=len(x)
b=len(y)
z=0
e={}
for i in range(a):
	for j in range(b):
		if x[i] == y[j]:
			if i==0 or j==0:
				e[(i,j)] = 1
			else:
				e[(i,j)] = e[(i-1,j-1)] + 1
			if e[(i,j)] > z:
				z = e[(i,j)]
		else:
			e[(i,j)] = 0
print z
