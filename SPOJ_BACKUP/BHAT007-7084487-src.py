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
	if decimal_to_base( int(x[2]), base_to_decimal(int(x[2]),int(x[0])) + base_to_decimal(int(x[2]),int(x[1])) ) == decimal_to_base( int(x[3]), base_to_decimal(int(x[3]),int(x[0])) + base_to_decimal(int(x[3]),int(x[1])) ):
		print "yes"
	else:
		print "no"
