a="zero one two three four five six seven eight nine ten eleven twelve thirteen fourteen fifteen sixteen seventeen eighteen nineteen twenty".split()
b="twenty thirty forty fifty sixty seventy eighty ninety".split()
n=input()
w=''
p=' '
t=n/1000
n-=1000*t
h=n/100
x=n=n-100*h
e=n/10
n-=e*10
if t:
	if t<21:w+=a[t]+p
	else:
		z=t/10;
		w+=b[z-2]+p
		s=t-z*10;
		if t:w+=a[s]+p
	w+="thousansd"+p
if h:w+=a[h]+p+"hundred"+p
if x<21 and e:w+=a[x]+p
else:
	if e:w+=b[e-2]+p
	if n or not(t|e|h|n):w+=a[n]+p
print w[:-1]
