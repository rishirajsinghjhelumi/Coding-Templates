import math,re,decimal
t=int(input())
while t:
	t-=1
	while 1:
		try:
			x=int(input())
			break
		except:
			continue
	a = str(decimal.Decimal(round(pow(x,1.0/3),11)))
	sumi = 0
	b=re.search(r"\.",a).start()
	for i in a[:-1]:
		if i!='.':
			sumi += ord(i)-48
	print (sumi%10,a+'0'*(11-len(a)+b))
