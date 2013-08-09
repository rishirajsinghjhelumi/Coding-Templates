a="zero one two three four five six seven eight nine ten eleven twelve thirteen fourteen fifteen sixteen seventeen eighteen nineteen twenty".split()
b="twenty thirty forty fifty sixty seventy eighty ninety".split()
n=input()
w=[]
t=n/1000
n-=1000*t
h=n/100
x=n=n-100*h
e=n/10
n-=e*10
if t:
	if t<21:w.append(a[t])
	else:
		z=t/10;
		w.append(b[z-2])
		s=t-z*10;
		if t:w.append(a[s])
	w.append("thousand")
if h:w.append(a[h]+' '+"hundred")
if x<21 and e:w.append(a[x])
else:
	if e:w.append(b[e-2])
	if n or not(t|e|h|n):w.append(a[n])
for i in w:print i,
