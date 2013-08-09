from calendar import *
for i in range(input()):
	x=bin(input())[2:]
	print int(x[-5:],2),month_name[int(x[-9:-5],2)],int(x[:-9],2)
