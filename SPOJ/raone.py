count = 0
p=[2,3,5,7,11,13,17,19,23,29,31,37,41,43,47]
x=0
y=1000
for z in range(100):
	count = 0
	for i in range(x,y):
		 b = str(i)[::-1]
		 xo = b[::2]
		 xe = b[1::2]
		 se = sum([int(j) for j in xe])
		 so = sum([int(j) for j in xo])
		 c=se-so
		 if c == 1:
		 	count +=1
	print x,y-1,count
	x = y
	y = x + 1000
