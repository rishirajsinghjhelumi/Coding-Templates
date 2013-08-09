def C(l):
	global f
	if l==0:f+='0'
	i,a,c=0,1,0
	while l>=a:
		if l&a:c+=1
		i,a=i+1,a<<1
	while a:
		if l&a:
			f+='2'
			if i!=1:f+='(';C(i);f+=')'
			c-=1
			if c:f+='+'
		i,a=i-1,a>>1
while 1:
	try:x=input();f='';C(x);print"%d=%s"%(x,f)
	except:break
