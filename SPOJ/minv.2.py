def iterative_egcd(a, b):
	x,y, u,v = 0,1, 1,0
	while a != 0:
		q,r = b/a,b%a; m,n = x-u*q,y-v*q
		b,a, x,y, u,v = a,r, u,v, m,n
	return b, x, y
def modinv(a, m):
	g, x, y = iterative_egcd(a, m)  
	if g != 1:
		return None
	else:
		return x % m
def crt(a1,a2,m1,m2,mod4,mod5,mod3):
	x1 = (a1*m1)%mod4
	x1*=2
	x2 = ((a2-x1)*m2)%mod5
	return (x1 + 2*mod4*x2)%mod3
def crt2(a2,m2,mod4,mod3):
	return (2*mod4*a2*m2)%mod3
def pow_fact(n):
	x,p,s=0,41,41
	while 1:
		a = n/s
		if a==0:
			break
		x+=a
		s*=p
	return x
mod1 = 1000000007
mod2 = mod1 - 1
mod3 = mod2/2 - 1
mod4 = 148721
mod5 = 1681
mod6 = 41
m1 = modinv(2,mod4)
m2 = modinv(2*mod4,mod5)
f=[1]
r1,r2 = 21,40
for i in range(1,200010):
	x = i
	while x%41==0:
		x/=41
	f[i:] = [(f[i-1]*x)%mod5]
a=[1]
for i in range(1,100010):
	a[i:] = [(a[-1]*(4*i-2)*modinv(i,mod4))%mod4]
for r in range(1,100001):
	x = f[2*r]*(modinv(f[r],mod5)**2)
	if r>=r1 and r<=r2:
		x*=41
		if r>840:
			x=0
	elif r>840 and r>=r1 and r<=r2:
		x*=41
	if r==r2:
		r1=r1+41
		r2=r1+19
	print x%mod5
#print crt(a[r],x%mod5,m1,m2,mod4,mod5,mod3)
