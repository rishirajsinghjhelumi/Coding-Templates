#include <stdio.h>
#include <stdlib.h>
#define DO(P,R,I,M,E,S,i0,v0,i1,v1,i2,v2,i3,v3,i4,v4,i5,v5,i6,v6,i7,v7) k=P;\
									  if (!(sieve[n] & (1<<R)))\
{ printf(" %ld",30*n + bits[R]);\
	e = eos - I*n - M;\
	for (m = sieve + (30*n + E) * n + S; m < e; m += i0)\
	{ *m        |= (1<<v0); *(m += i1) |= (1<<v1);\
		*(m +=i2) |= (1<<v2); *(m += i3) |= (1<<v3);\
		*(m +=i4) |= (1<<v4); *(m += i5) |= (1<<v5);\
		*(m +=i6) |= (1<<v6); *(m += i7) |= (1<<v7);\
	}\
	if (m < eos) { *m|=(1<<v0);\
		if ((m += i1) < eos) { *m |= (1<<v1);\
			if ((m += i2) < eos) { *m |= (1<<v2);\
				if ((m += i3) < eos) { *m |= (1<<v3);\
					if ((m += i4) < eos) { *m |= (1<<v4);\
						if ((m += i5) < eos) { *m |= (1<<v5);\
							if ((m += i6) < eos)   *m |= (1<<v6);\
						} } } } } } }
char bits[] = {1,7,11,13,17,19,23,29} ;

int main(int argc, char *argv[])
{
	unsigned long p,q,r,k=0,n,s;
	char *m,*e,*eos,*sieve;
	long bytes,atol();

	if (argc!=2) printf("usage: %s (<bytes_used> or -<maxprime>)\n",*argv), exit(0);
	if ((bytes=atol(argv[1])) < 0) bytes = 1 + (-bytes)/30;
	if (!(sieve = calloc(bytes,1))) printf("Out of memory.\n"), exit(0);
	if (bytes > 30) for (k = r = (bytes-1)/30; (q = r/k) < k; k >>= 1) k += q;
	eos = sieve + bytes; s = k + 1; *sieve = 1; printf("2 3 5");
	for (n = p = q = r = 0; n < s; n++)
	{ DO(p++,0,28, 0, 2, 0,p,0,r,1,q,2,k,3,q,4,k,5,q,6,r,7); r++;
		DO(q++,1,24, 6,14, 1,r,5,q,4,p,0,k,7,p,3,q,2,r,6,p,1); r++; q++;
		DO(p-1,2,26, 9,22, 4,q,0,k,6,q,1,k,7,q,3,r,5,p,2,r,4); r++;
		DO(q-1,3,28,12,26, 5,p,5,q,2,p,1,k,7,r,4,p,3,r,0,k,6);
		DO(q+1,4,26,15,34, 9,q,5,p,6,k,0,r,3,p,4,r,7,k,1,p,2); r++;
		DO(p+1,5,28,17,38,12,k,0,q,4,r,2,p,5,r,3,q,7,k,1,q,6); r++; q++;
		DO(q++,6,26,20,46,17,k,5,r,1,p,6,r,2,k,3,p,7,q,0,p,4); r++;
		DO(p++,7,24,23,58,28,r,0,k,7,r,6,q,5,p,4,q,3,p,2,q,1);
	}
	printf(" ...");
	for (p = bytes - s; p < bytes; p++)
		for (k = 0; k < 8; k++)
			if (!(sieve[p] & (1<<k))) printf(" %ld",30 * p + bits[k]);
	for (p = 0, n=3; p < bytes; p++)
		for (k = 0; k < 8; k++) n += !(sieve[p] & (1<<k));
	printf("\n%ld primes found\n", n);
	exit(0);
}
