a=['2','3','4','5','6','7','8','9']
def check(n):
	global a
	for i in a:
		if i in str(n):
			return 0
	return 1
x=input()
while x:
	x=x-1
	y=input()
	z=y
	while 1:
		if check(y)==1:
			break
		y+=z
	print y
