mod1=1000000007
mod2=mod1-1
mod4=mod2/2-1
a=1
for i in range(1,79982):
	a = (4*i-2)*a/i
for i in range(100):
	for j in range(100):
		print pow(i,pow(j,a,mod2),mod1)
#print mod1,mod2,mod3,mod4,mod5
#100000 100000 100000
#99999 99999 99999
#754901378
#471351505 
