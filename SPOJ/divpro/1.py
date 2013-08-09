for a in range(55):
	for b in range(37):
		for c in range(19):
			for d in range(19):
				ans = (2**a)*(3**b)*(5**c)*(7**d)
				if ans <= 10**18:
					print ans
