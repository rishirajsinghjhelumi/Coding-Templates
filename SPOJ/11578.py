case = 1
while 1:
	try:
		t=input()
		x=raw_input().split()
		e={}
		count = 0
		for i in x:
			if i not in e and i!='0':
				count = count + 1
				e[i] = 1
		print "Case "+str(case)+":",count
		case = case + 1
	except:
		break
