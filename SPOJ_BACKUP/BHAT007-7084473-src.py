def base_to_decimal(b,num):
	ans = 0
	y=1
	while num:
		ans += (num%10)*y
		y *= b
		num /= 10
	return ans
def decimal_to_base(b,num):
	ans = ''
	while num:
		ans = str(num%b) + ans
		num /= b
	return ans
t=input()
while t:
	t = t - 1
	x=raw_input().split()
	num1 = int(x[0])
	num2 = int(x[1])
	b1 = int(x[2])
	b2 = int(x[3])
	z1 = decimal_to_base( b1, base_to_decimal(b1,num1) + base_to_decimal(b1,num2) )
	z2 = decimal_to_base( b2, base_to_decimal(b2,num1) + base_to_decimal(b2,num2) )
	if z1 == z2:
		print "yes"
	else:
		print "no"
