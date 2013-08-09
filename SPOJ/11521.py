a=[]
count=[]
s=0
b=[]
y=0
[count.append([0 for x in range(26)]) for i in range(15200)]
while 1:
	try:
		x=raw_input()
		a.append(x)
		for i in range(len(x)):
			count[s][ord(x[i])-97] = count[s][ord(x[i])-97] + 1
		s=s+1	
	except:
		break
for i in range(s):
	for j in range(s):
		if i!=j:
			y=1
			for k in range(26):
				if count[i][k] > count[j][k]:
					y=0
					break
		if y==1:
		  	break
	if y==0:
		b.append(a[i])
b.sort()
for i in b:print i
