def b2d(base,number):
	x=1
	num=0
	sign=1
	while number:
		num +=sign*(number%10)*x
		x *=base
		sign *=-1
		number/=10
	return num
def d2b(base,number):
	num=[]
	i=0
	base *=-1
	if not number:
		num=[0]
		return num
	while number:
		num[i:] = [number%base]
		number /=base
		if num[-1]<0:
			number +=1
			num[-1]=num[-1]+(base*-1)
		i+=1
	return num
while 1:
	x = raw_input().split()
	x1 = x[0].split('-')
	if x1[0]=='end':
		break
	if x1[0]=='to':
		a=''.join(str(i) for i in reversed(d2b(int(x1[1]),int(x[1]))))
		print a
	elif x1[0]=='from':
		print b2d(int(x1[1]),int(x[1]))
