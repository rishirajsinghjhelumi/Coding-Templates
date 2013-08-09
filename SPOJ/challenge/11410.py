import re
e,j,d,s,r=[[]],0,{},re.search,range
while 1:
	try:
		x=raw_input()
		if s(r"/status",x):e[j].append(((x.split("/")[2]).split(",")[0]))
		if s(r"TODO|History",x):j+=1;e.append([])
	except:break
for i in r(3,j,2):
	for l in e[i]:
		if l not in e[1]:
			d[l]=d[l]+1 if l in d else 1
f=sorted(sorted(d.items()),key=lambda x:x[1],reverse=True)
for i in f:
	if i[0].isupper():print i[0]
	else:break
	
