def base_to_decimal(b,num,l):
	ans = 0
	y=1
	for i in range(l):
		ans += int(num[l-i-1])*y
		y *= b
	return ans
def decimal_to_base(b,num):
	ans = ''
	while num:
		ans = str(num%b) + ans
		num /= b
	return ans
def nim_sum_base(b,x1,x2,l):
	ans = ''
	for i in range(l):
		ans += str((int(x1[i])+int(x2[i]))%b)
	return ans
t = input()
while t:
	t-=1
	x=raw_input().split()
	b=int(x[1])
	x1 = decimal_to_base(b,int(x[2]))
	x2 = decimal_to_base(b,int(x[3]))
	l1 = len(x1)
	l2 = len(x2)
	l = l1
	if l1 < l2:
		x1 = '0'*(l2-l1) + x1
		l = l2
	elif l2 < l1:
		x2 = '0'*(l1-l2) + x2
		l = l1
	print x[0],base_to_decimal(b,nim_sum_base(b,x1,x2,l),l)
