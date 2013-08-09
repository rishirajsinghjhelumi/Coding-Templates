num = "12345"
arr = []
l = len(num)
ans = [[0 for j in range(l)] for i in range(l)]
for i in range(1,1<<l):
	x = i
	b = bin(i)[2:]
	a = ''
	if len(b)!=l:
		b = '0'*(l - len(b)) + b
	for j in range(l):
		if b[j] == '1':
			a = a + num[j]
	b = a
	if len(b)!=l:
		b = '0'*(l - len(b)) + b
	for i in range(l):
		if b[i]!='0':
			ans[int(b[i])-1][i] +=1

for i in range(l):
	for j in range(l):
		print ans[i][j],
	print

