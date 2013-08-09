x=input()
f={}
fof={}
count = 0
while x:
	y=raw_input()
	b=y.split()
	f[b[0]] = 1
	for i in range(int(b[1])):
		if b[i+2] not in fof:
			fof[b[i+2]] = 1
			count = count + 1
	x=x-1
for i in f:
	if i in fof:
	 	count = count - 1
print count
