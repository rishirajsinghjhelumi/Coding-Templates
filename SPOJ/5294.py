import sys
def calc(a,n,mod,start):
	if n==0:
		return 1
	x,b,i=1,1,0
	while 1:
		if b>n:
			r=i-1
			break
		b<<=1
		i+=1
	b=1
	for j in range(r):
		x=(x*(pow(a,b,mod)+1))%mod
		b<<=1
	start = pow(a,b,mod)
	return (x+start*calc(a,n-b,mod,start))%mod
x=map(int,sys.stdin.read().split())
a=len(x)
for i in range(1,a,4):
	a,b,n,mod = x[i:i+4]
	if n:
		print (pow(a,n,mod) + b*calc(a,n-1,mod,1))%mod
	else:
	 	print 1
