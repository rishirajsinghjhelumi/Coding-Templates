a=[1,8,95,1183]
for i in range(4,18):a[i:]=[15*a[-1]-32*a[-2]+15*a[-3]-a[-4]]
for i in range(1,18):print a[i]
