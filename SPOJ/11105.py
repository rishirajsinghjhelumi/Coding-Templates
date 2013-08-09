import re
for j in range(input()):
	x=raw_input()
	pos = [0]
	for i in re.finditer(r"@",x):
		pos.append(i.start())
	res=[]
	pos.remove(pos[-1])
	for i in pos:
		a=re.search(r"[a-zA-Z0-9_.]+@[a-zA-Z0-9]+\.co.in|[a-zA-Z0-9_.]+@[a-zA-Z0-9]+\.com|[a-zA-Z0-9_.]+@[a-zA-Z0-9]+\.org|[a-zA-Z0-9_.]+@[a-zA-Z0-9]+\.edu",x[i:])
		if a:
			res.append(a.group())
	count = len(res)
	for i in res:
		if re.search(r"@",i).start()<5:
			count -= 1
	print "Case #"+str(j+1)+":",count
	for i in res:
		if re.search(r"@",i).start()>=5:
			print i
