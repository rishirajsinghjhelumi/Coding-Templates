from calendar import*
t=input()
while t:t-=1;x=bin(input());print int(x[-5:],2),month_name[int(x[-9:-5],2)],int(x[:-9],2)
