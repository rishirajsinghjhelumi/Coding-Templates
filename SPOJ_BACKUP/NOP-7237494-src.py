x=raw_input()
a=c=0
for i in x:
	if i.isupper():
		a+=3-c%4
		c=0
	else:c+=1
print a-3
