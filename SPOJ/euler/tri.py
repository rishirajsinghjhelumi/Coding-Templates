maxi = 0
num=100
for i in range(100,1001):
	count=0
	print i
	for a in range(1,1001):
		for b in range(1,1001):
			for c in range(1,1001):
				if a+b+c>i or a+b<c or a+c<b or b+c<a:
					continue
				else:
					if a*a+b*b == c*c:
						count = count + 1
	if count > maxi:
	   	maxi = count
	   	num = i
	   	print num
