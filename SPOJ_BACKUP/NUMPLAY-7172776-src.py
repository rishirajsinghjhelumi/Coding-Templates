one=[0,1]
three=[0,1]
five=[0,1]
seven=[0,1]
for i in range(2,10001):
	one.append(three[i-1])
	three.append(one[i-1]+five[i-1])
	five.append(seven[i-1])
	seven.append(three[i-1]+five[i-1])
t=input()
while t:
	t-=1
	x=input()
	print one[x]+three[x]+five[x]+seven[x]
