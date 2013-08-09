p=[2,3,5,7,11,13,17,19,23,29,31,37,41,43,47,53,59,61,67,71,73,79,83,89,97,101,103,107,109,113,127,131,137,139,149,151,157]
prod=[1]
a=1
for i in p:
	a*=i
	prod.append(a)
l = len(prod)
for i in range(20):
	x=input()
	ans=1
	for j in range(l):
		if prod[j] > x:
			ans = prod[j-1]
			break
	print ans
