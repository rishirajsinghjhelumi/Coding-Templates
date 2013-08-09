import math
#import psyco
#psyco.full()
maxi=1000001
m = (maxi-1)>>1
x = int((math.floor(math.sqrt(maxi)-1))/2)
p=[0]*maxi
primes=[2]
for i in range(1,x+1)
	if p[i]==0:
		for j in range(((i+1)*i)<<1,m+1,(i<<1)+1):
			p[j]=1
for i in range(1,m+1):
	if p[i]==0:
		primes.append((i<<1)+1)
k=78498
t = input()
while t:
	t-=1
	n,K=map(int,raw_input().split())
	j,s=0,int(math.sqrt(K))
	fact=[]
	while K!=1:
		X = primes[j]
		d = 0
		while (K%X)==0:
			d+=1
			K/=X
		if d:
			fact.append((X,d))
		j+=1
		if j==k or X>=s:
			break
	if K!=1:
		fact.append((K,1))
	mini=100000000000000000000
	for i in fact:
		X = n
		a,c,f = i[0],0,i[1]
		y = i[0]
		while X//a:
			c += X//a
			a *= y
		if c//f<mini:
			mini = c//f
	print mini
