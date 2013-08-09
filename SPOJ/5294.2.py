import sys
bit=[1,2]
b = 2
for i in range(2,340):
	b<<=1
	bit[i:] = [b]
def calc(a,n,mod,bit,start):
	x=1
	if n==0:
		return 1
	for i in range(340):
		if bit[i]>n:
			r=i-1
			break
	for j in range(r):
		x=(x*(pow(a,bit[j],mod)+1))%mod
	n=n-(bit[r])
	start=pow(a,bit[r],mod)
	return (x+start*calc(a,n,mod,bit,start))%mod
t=input()
while t:
	t-=1
	a,b,n,mod = map(int,raw_input().split())
	if n:
		p = calc(a,n-1,mod,bit,1)
		ans = (pow(a,n,mod) + b*p)%mod
	else:
	 	ans = 1
	print ans
