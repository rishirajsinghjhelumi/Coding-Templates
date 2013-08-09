count = 0
i = 2
while i!=40000:
	x=raw_input().split()
	if len(x)==len(set(x))and len(set(x))>=3:
		print i
		count +=1
	i +=1
print count
