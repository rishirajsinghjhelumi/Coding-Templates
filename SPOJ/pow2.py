mod = 500000002
print 1
n = k = 2
exec"print n%mod;n=4*n-2*n/k;k+=1;"*100
