t=int(input())
while  t:
	t-=1
	x=input().split()
	a=int(x[0])
	b=int(x[1])
	print ("%d/%d"%(((a**b)-1),(a-1)))
