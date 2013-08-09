a="zero one two three four five six seven eight nine ten eleven twelve thirteen fourteen fifteen sixteen seventeen eighteen nineteen twenty".split()
b="twenty thirty forty fifty sixty seventy eighty ninety".split()
r=range
for i in r(input()):
	n=p=0
	for j in raw_input().split():
		if j=="thousand":n,p=n+p*1000,0
		if j=="hundred":n,p=n+p*100,0
		for i in r(20):p+=i if j==a[i]else 0
		for i in r(8):p+=10*i+20 if j==b[i]else 0
	print n+p
