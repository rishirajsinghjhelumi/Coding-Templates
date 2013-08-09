import sys
def mul_base(b,num):
	ans = 0
	f = 1
	while num:
		if num&1:
			ans += f
		num>>=1
		f*=b
	return ans
x=map(int,sys.stdin.read().split())
l = len(x)
for i in range(1,l,2):
	print mul_base(x[i],x[i+1])
