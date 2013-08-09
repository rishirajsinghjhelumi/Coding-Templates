def C(n,k):
	if k==0:
		return 1
	return C(n-1,k-1)*n/k
for i in range(input()):
	x=raw_input().split()
	n=int(x[0])-1
	k=int(x[1])-1
	print C(n,k)
