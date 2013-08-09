def gcd(a,b):
	if b==0:
		return a
	return gcd(b,a%b)
lcm = 1;
for i in range(1,21):
	lcm = (i*lcm)/gcd(i,lcm)
print lcm
