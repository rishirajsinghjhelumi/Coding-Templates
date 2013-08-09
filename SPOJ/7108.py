while 1:
	x=raw_input().split()
	if x[0]=='*' and x[1]=='*':
		break
	a = int(x[0],17)
	b = int(x[1],17)
	if a==b:
		print "="
	elif a>b:
		print ">"
	else:
		print "<"
