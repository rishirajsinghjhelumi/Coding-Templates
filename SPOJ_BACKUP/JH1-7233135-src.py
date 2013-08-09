t=input()
while t:
	t-=1
	x=input()
	a=map(int,raw_input().split())
	if -sum([i for i in a[::2]if i<0])>sum([i for i in a[1::2]if i>0]):print "Every Girl Lies!"
	else:print "Some Mirrors Lie!"
