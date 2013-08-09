import re
e,j,d,s,r=[[]],0,{},re.search,range
while 1:
	try:
		x=raw_input()
		if s(r"/status",x):e[j].append(((x.split("/")[2]).split(",")[0]))
		if s(r"TODO|History",x):j=j+1;e.append([])
	except:break
for i in r(3,j,2):
	for l in e[i]:
		if l not in e[1]:
			if l in d:d[l]=d[l]+1
			else:d[l]=1
l=max(d.values())+1
while l:
	b=[x for x in d if d[x]==l]
	b.sort()
	if l==1:
		for i in r(len(b)-j/2+1):print b[i]
	else:
		for i in b:print i 
	l=l-1
