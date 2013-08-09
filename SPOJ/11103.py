p=[0 for j in range(1000000)]
prime=[]
for i in range(2,1000000):
	if p[i] == 0:
		prime.append(i)
		for j in range(2*i,1000000,i):
			p[j] = 1
k = len(prime)
def gcd(a,b):
	if b==0:
		return a
	return gcd(b,a%b)
for t in range(1,input()+1):
	y=input()
	lcm = 1
	numbers=[]
	for i in raw_input().split():
		lcm = (lcm*(int(i)))/gcd(lcm,int(i))
	l = 0
	while lcm!=1:
		d=0
		while lcm%prime[l]==0:
			lcm /=prime[l]
			d=1
		if d==1:
			numbers.append(prime[l])
		l=l+1
		if l == k:
			break
	print "Case #"+str(t)+":",len(numbers)
	for i in numbers:
		print i
