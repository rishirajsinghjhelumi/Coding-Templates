import re
e,p,f,j,d,r,s=[[]],[],[],0,{},range,re.search
while 1:
	try:
		x=raw_input()
		if s(r"/status",x):e[j].append(x)
		if s(r"TODO|HISTORY",x):j=j+1;e.append([])
	except:break
[p.append([((l.split("/")[2]).split(",")[0])for l in e[i]])for i in r(j+1)]
for i in r(j):
	x=0
	f.append([])
	for l in p[i]:
		if x==3:f[i].append(l)
		if s(r'[a-z]+',l):x=x+1
for i in r(1,j):
	for l in f[i]:
		if l not in f[0]:
			if l in d:d[l]=d[l]+1
			else:d[l]=1
j=max(d.values())+1
while j:
	b=[x for x in d if d[x]==j]
	b.sort()
	for i in b:print i 
	j=j-1
