r,t=range,input
f=lambda x:x<2 or f(x-2)+f(x-1)
for i in r(t()):
	s=t()
	print sum([f(i)for i in r(s,s+10)])+f(s+246)%10
