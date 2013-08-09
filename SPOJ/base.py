def int_to_base(n,b):
	x = ""
	while n:
		x = str(n%b) + x
		n /= b
	return x
for j in range(11):
	print j,int_to_base(j,3)
b = input()
for i in range(7):
	count = [0 for j in range(b)]
	s = [str(j) for j in range(b)]
	for j in range(b**i,b**(i+1)):
		a = int_to_base(j,b)
		for j in range(b):
			if s[j] in a:
				count[j]+=1
	print count
