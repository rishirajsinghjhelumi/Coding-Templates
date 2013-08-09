import math,sys
#import psyco
#psyco.full()
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
x = map(int,sys.stdin.read().split())
for i in x:
	if i==0:
		break
	a = fact(i)
	s = sorted(set(a))
	for j in s:
		print("%d^%d"%(j,a.count(j))),
	print
