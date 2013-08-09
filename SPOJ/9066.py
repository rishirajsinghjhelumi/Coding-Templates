b=[]
x=input()
for i in raw_input().split():
	b.append(int(i))
q=input()
while q:
	q=q-1
	x=raw_input().split()
	if x[0] == 'Q':
		print sum(set(b[int(x[1])-1:int(x[2])]))
	elif x[0] == 'U':
		b[int(x[1])-1] = int(x[2])
