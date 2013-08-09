a='1'
for i in range(10):
	b = ''
	for j in a:
		if j=='0':
			b = b + '10'
		else:
			b = b + '01'
	l = len(b)
	count = 0
	for j in range(l-1):
		if b[j]=='0' and b[j+1]=='0':
			count += 1
	print count
	a = b
