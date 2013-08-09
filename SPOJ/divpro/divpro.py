def num_to_digit(num):
	a = []
	while num:
		a.append(num%10)
		num /= 10
	a = a[::-1]
	return a
d = input()
arr = [1,2,3,4,5,6,7,8,9,10,12,14,15,16,18,20,21,24,25]
mat = [0 for j in range(10000)]
l1 = 10 ** (d-1)
l2 = 10 ** (d)
for i in range(l1,l2):
	dig = num_to_digit(i)
	r1 , r2 = 1 , 1
	for j in dig[::2]:
		r1 *= j
	for j in dig[1::2]:
		r2 *= j
	if r2!=0 and r1%r2==0:
		mat[r1/r2] += 1
for i in arr:
	print mat[i],
print
