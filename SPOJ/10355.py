t=input()
while t:
	t-=1
	x=raw_input().split()
	print str(((1<<(int(x[0])+1))-(1<<(int(x[1])+1))))+".00"
