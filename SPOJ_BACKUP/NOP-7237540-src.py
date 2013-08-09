a=c=0
for i in input():a,c=(a+3-c%4,0)if i.isupper()else(a,c+1)
print(a-3)
