count=[]
for i in range(5):
	x=raw_input()
	if "FBI" in x:
		count.append(i+1)
if count ==[]:
	print "HE GOT AWAY!"
else:
	for i in count:
	 	print i
