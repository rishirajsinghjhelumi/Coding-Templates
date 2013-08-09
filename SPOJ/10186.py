while 1:
	try:
		r=raw_input()
		count = 0
		b=int(r)
		for i in r:
			if i!='0':
				if b%int(i) == 0:
					count = count + 1
		print count
	except:
		break
