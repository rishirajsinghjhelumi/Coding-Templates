import re
a=[]
e=[[]]
p=[]
f=[]
j=0
d={}
while 1:
	try:
		a.append(raw_input())
	except:
		break
for i in a:
	if re.search(r"/status",i):
		e[j].append(i)
	if re.search(r"TODO|HISTORY",i):
		j=j+1
		e.append([])
for i in range(j+1):
	p.append([])
	for l in e[i]:
		p[i].append((l.split("/")[2]).split(",")[0])
for i in range(j):
	x=0
	f.append([])
	for l in p[i]:
		if x==3:
			f[i].append(l)
		if re.search(r'[a-z]+',l):
			x=x+1
for i in range(1,j):
	for l in f[i]:
		if l not in f[0]:
			if l not in d:
				d[l] = 1
			else:
				d[l] = d[l]+1
for j in reversed(range(1,max(d.values())+1)):
	b=[x for x in d if d[x]==j]
	b.sort()
	for i in b:
		print i
