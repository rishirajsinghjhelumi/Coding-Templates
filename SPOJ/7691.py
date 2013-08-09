n=input()
l = 0
e={}
count = 0
len1 = 0
while n:
	n -= 1
	x = raw_input().split()
	num = int(x[1])
	if x[0] == "insert":
		l += 1
		if e.has_key(num):
			e[num] += 1
			count -=1
		else:
		 	e[num] = 1
		 	count += 1
		 	len1 +=1
		if l==0 or l==1:
			print "neither"
		else:
		 	homo = 0
		 	hetero = 0
		 	if len1>=2:
		 		hetero = 1
		 	if count!=l:
		 		homo = 1
		 	if homo and hetero:
		 		print "both"
		 	elif homo and not hetero:
		 		print "homo"
		 	elif hetero and not homo:
		 		print "hetero"
	else:
		if e.has_key(num):
			l -= 1
			e[num] -= 1
			if e[num] == 0:
				del e[num]
				count-=1
				len1-=1
			elif e[num]==1:
				count+=1
		if l==0 or l==1:
			print "neither"
		else:
		 	homo = 0
		 	hetero = 0
		 	if len1>=2:
		 		hetero = 1
		 	if count!=l:
		 		homo = 1
		 	if homo and hetero:
		 		print "both"
		 	elif homo and not hetero:
		 		print "homo"
	 		elif hetero and not homo:
	 			print "hetero"
