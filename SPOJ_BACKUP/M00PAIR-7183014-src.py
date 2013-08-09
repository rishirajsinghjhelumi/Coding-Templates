a=[0,1]
for i in range(2,1001):
	a[i:] = [a[-1] + 2*a[-2]]
while 1:
	try:
		print a[int(raw_input())-1]
	except:
		break
