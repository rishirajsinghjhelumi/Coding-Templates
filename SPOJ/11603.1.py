diff=[[0 for j in range(30)]for i in range(30)]
for i in range(30):
	diff[0][i] = 1
for i in range(1,30):
	for j in range(i):
		diff[i][j] = 0
	k = 1
	for j in range(i,30):
		diff[i][j] = k*diff[i-1][j]
		k+=1
t=input()
while t:
	t-=1
	d=input()
	c = map(int,raw_input().split())
	a=[0]*30
	a[d+1] = c[d]/(d+1);
	for i in range(d-1,-1,-1):
		s1=0;
		for j in range(i,d+1):
			s1 += diff[i][j]*c[j];
		for j in range(i+2,d+2):
			s1 -= diff[i][j]*a[j];
		print s1
		a[i+1] = s1/diff[i][i+1];	
	for i in range(1,d+2):
		print a[i],
	print
