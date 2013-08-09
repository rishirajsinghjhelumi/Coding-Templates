t=input()
while t:
	t-=1
	credits=[]
	for i in raw_input().split():
		credits.append(int(i))
	marks=[]
	for i in range(6):
		marks.append(raw_input().split())
	passed = 1
	gpa = 0
	k=0
	for i in marks:
		if i[0] == 'ab':a=0
		else:a = float(i[0])
		if i[1] == 'ab':b=0
		else:b = float(i[1])
		if i[2] == 'ab':c=0
		else:c = float(i[2])
		d = float(i[3])
		e = float(i[4])
		if a>=b and c>=b:
			t1 = a+c
		elif b>=c and a>=c:
			t1 = a+b
		elif b>=a and c>=a:
			t1 = b+c
		if e<=50:
			m = 5
		elif 51<=e<61:
			m = 4
		elif 61<=e<71:
			m = 3
		elif 71<=e<81:
			m = 2
		elif 81<=e<91:
			m = 1
		elif 91<=e:
			m = 0
		tot = t1*1.125 + m + 0.5*d
		if tot < 50:
			p = 0
		elif tot==50:
			p = 5
		elif 51<=tot<61:
			p = 6
		elif 61<=tot<71:
			p = 7
		elif 71<=tot<81:
			p = 8
		elif 81<=tot<91:
			p = 9
		elif 91<=tot:
			p = 10
		if p == 0:
			passed = 0
		gpa += p*credits[k]
		k += 1
	if passed == 0:
	 	print "FAILED,",
	else:
	 	print "PASSED,",
	print '%.2f' %round(gpa*1.0/sum(credits),2)
