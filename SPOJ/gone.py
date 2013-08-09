p=[2,3,5,7,11,13,17,19,23,29,31,37,41,43,47,53,59,61,67,71,73]
count=0
x=1
y=10
m=[0 for j in range(73)]
for z in range(10):
	count = 0
	for i in range(x,y):
		b = str(i)
		s = sum([int(j) for j in b])
		if s in p:
			count +=1
	b = str(y-1)
	s = sum([int(j) for j in b])
	if s>72:
	  	break
	print s,count
	m[s] = count
	x = y + 10
	y = y + 10
print m
