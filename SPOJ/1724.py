t=input()
while t:
	t-=1
	n=input()
	y=n*(n+2)*((n<<1)+1)
	if n&1:print (y-1)>>3
	else:print y>>3
