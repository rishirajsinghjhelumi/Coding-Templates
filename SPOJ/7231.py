import math,sys
import psyco
psyco.full()
step = lambda x: 1 + x*4 - (x/2)*2
def fact(n):
	  global step
	  maxq = int(math.floor(math.sqrt(n)))
	  d = 1
	  q = n % 2 == 0 and 2 or 3 
	  while q <= maxq and n % q != 0:
	       q = step(d)
	       d += 1
	  res = []
	  if q <= maxq:
	  	res.extend(fact(n//q))
	  	res.extend(fact(q)) 
	  else:res=[n]
	  return res
while 1:
	i = input()
	if i==-1:
		break
	f = fact(i)
	s = sorted(set(f))
	a = 1
	b = 1
	for y in s:
		z = f.count(y)
		if z&1:
			a *= pow(y,z>>1)
			b *= y
		else:
			a *= pow(y,z>>1)
	print a,b
