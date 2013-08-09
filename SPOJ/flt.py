import math
import sys
main=[[],[],[],[],[],[],[],[],[],[]]
for i in range(2,10,1):
	temp=1
	for j in range(0,670,1):
		main[i].append(temp)
		temp=temp*i
		test=int(raw_input())
		while test>0:
		line=raw_input()
		lis=line.split()
		k=int(lis[0])
		n=int(lis[1])
		ans=0
		while n>0:
		ans=ans+main[k][int(math.log(n,2))]
		n=n-main[2][int(math.log(n,2))]
		print ans
		test=test-1
