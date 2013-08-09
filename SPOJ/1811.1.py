a=raw_input()
b=raw_input()
z=0
for i in set([a[i:j] for i in range(len(a)) for j in range(len(a)+1) if len(a[i:j])>0]):
	if i in b:
		if len(i) > z:
			z = len(i)
print z
