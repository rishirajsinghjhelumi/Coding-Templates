#import psyco
#psyco.full()
t=input()
while  t:
	t-=1
	x=raw_input().split()
	a=int(x[0])
	b=int(x[1])
	print "%d/%d"%((pow(a,b)-1),(a-1))
