def C(l):
	global f
	if l==0:f+='0'
	i,a,c=0,1,0
	while l>=a:
		if l&a:c+=1
		i+=1;a*=2
	while a:
		if l&a:
			f+='2';c-=1
			if i!=1:f+='(';C(i);f+=')'
			if c:f+='+'
		i-=1;a/=2
while 1:
	try:x=input();f='';C(x);print"%d=%s"%(x,f)
	except:break
