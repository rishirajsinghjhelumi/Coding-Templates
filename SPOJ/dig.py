x,y=map(int,raw_input().split())
a=[0]*10
a[0]=1
for i in range(x,y+1):
	b = i
	while(b):
		a[b%10]+=1
		b/=10
print a
