import math
maxi=320
p=[1]*maxi
a=int(math.sqrt(maxi))+1
primes=[0]
for i in range(2,a+1):
	if p[i]:
		for j in range(i+i,maxi,i):
			p[j] = 0
k=1
print "2,",
for i in range(3,maxi,2):
	if p[i]:
		print str(i)+",",
		k+=1
		
for i in primes[1:]:
	x=str(i)
	if x==x[::-1]:
		k+=1
		a=1
		for j in x:
			if int(j):
				a*=int(j)
#print str(primes[a])+",",
#print k
print k
