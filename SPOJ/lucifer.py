x = input()
y = input()
count = 0
p=[2,3,5,7,11,13,17,19,23,29,31,37,41,43,47]
for i in range(x,y+1):
	 b = str(i)[::-1]
	 xo = b[::2]
	 xe = b[1::2]
	 se = sum([int(j) for j in xe])
	 so = sum([int(j) for j in xo])
	 c=se-so
	 if c in p:
	 	print i
	 	count +=1
print count
