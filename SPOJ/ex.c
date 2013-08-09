#!/usr/bin/bc -l

define mod(n, l)
{
	auto oldscale,ret
		oldscale=scale
		scale=0
		ret=(n/l)*l
		scale=oldscale
		return n-ret
}

define logfactorial(n)
{
	auto i,res
		if (n<10000) {
			res=0
				for (i=1;i<=n;i++) {
					res+=l(i)
				}
			return res/l(10)
		}
	res=n*l(n)-n+1/2*l(2*a(1)*4*n)+1/12/n-1/360/(n^3)+1/1260/(n^5)-1/1680/(n^7)+1/1188/(n^9)-691/2730/12/11/(n^11)+7/6/14/13/(n^13)
		return res/l(10)
}

define firstdigits(n,k)
{
	auto log
		log=logfactorial(n)
		log=mod(log,1)+k-1+10^(-42)
		return e(log*l(10));
}

define lastdigits(n,l)
{
	auto i,res,pow10l
		res=1
		pow10l=10^l
		if (n>1000 && l<150) {
			return 0
		}
	for (i=2;i<=n;i++) {
		res=mod(res*i,pow10l)
			if (res==0) break;
	}
	return res
}

define output(n, c)
{
	auto log,ciphers,i,oldscale
		if (n==0) {
			for (i=0;i<c;i++) {
				print "0"
			}
			return
		}
	log=l(n)/l(10)
		ciphers=log+10^(-42)-mod(log+10^(-42),1)+1
		for (i=0;i<c-ciphers;i++) {
			print "0"
		}
	oldscale=scale
		scale=0
		print n/1
		scale=oldscale
}

scale=70

t=read()
	while (t--) {
		n=read()
			k=read()
			l=read()
			b=lastdigits(n,l)
			a=firstdigits(n,k)

			dummy=output(a,k)
			print " "
			dummy=output(b,l)
			print "\n"
	}


