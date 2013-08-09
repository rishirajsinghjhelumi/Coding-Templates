import re
c=input()
d=input()
count = 0
while c!=d:
	b=str(c)
 	if b==b[::-1] and re.search(r"[2345679]",b)==None:
          print c
	  count +=1
	c+=1
print "count==",count
