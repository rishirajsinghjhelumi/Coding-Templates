one=[0,1]
three=[0,1]
five=[0,1]
seven=[0,1]
res=[0,4]
i = 1 
while i!=10001:
	i+=1
	one[i:] = [three[i-1]]
	three[i:] = [one[i-1]+five[i-1]]
	five[i:] = [seven[i-1]]
	seven[i:] = [three[i-1]+five[i-1]]
	res[i:] = [one[-1]+three[-1]+five[-1]+seven[-1]]
t=input()
while t:
	t-=1
	x=input()
	print res[x]
