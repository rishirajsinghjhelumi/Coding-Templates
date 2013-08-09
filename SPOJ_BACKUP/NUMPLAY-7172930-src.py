one=[0,1]
three=[0,1]
five=[0,1]
seven=[0,1]
i = 1 
while i!=10000:
	i+=1
	one[i:] = [three[i-1]]
	three[i:] = [one[i-1]+five[i-1]]
	five[i:] = [seven[i-1]]
	seven[i:] = [three[i-1]+five[i-1]]
t=input()
while t:
	t-=1
	x=input()
	print one[x]+three[x]+five[x]+seven[x]

