import itertools,sys,os
def main():
	x=input()
	while x!=0:
		z=[]
		count=0
		for i in raw_input().split():
			z.append(int(i))
		for i in itertools.combinations(z,3):
			if i[0]+i[1]<i[2]:
				count=count+1
			elif i[1]+i[2]<i[0]:
				count=count+1
			elif i[0]+i[2]<i[1]:
				count=count+1
		print count
		x=input()
	sys.exit()
if __name__ == "__main__":
	    main()
