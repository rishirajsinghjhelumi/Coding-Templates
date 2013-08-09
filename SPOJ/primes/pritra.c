#include <stdio.h>
#include <stdlib.h>
#define DO(P,R,I,M,E,S,i0,v0,i1,v1,i2,v2,i3,v3,i4,v4,i5,v5,i6,v6,i7,v7) k=P;\
									  if (!(sieve[n] & (1<<R)))\
{ \
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
						18             if ((m += i5) < eos) { *m |= (1<<v5);\
							19               if ((m += i6) < eos)   *m |= (1<<v6);\
							20 } } } } } } }
21 char bits[] = {1,7,11,13,17,19,23,29} ;
22 int i,a[5000010];
23 int main()
	24 {
		25   unsigned long p,q,r,k=0,n,s;
		26   char *m,*e,*eos,*sieve;
		27   long bytes;
		28   bytes = 1 + (100000000)/30;
		29   if (!(sieve = malloc(bytes))) printf("Out of memory.\n"), exit(0);
		30   if (bytes > 30) for (k = r = (bytes-1)/30; (q = r/k) < k; k >>= 1) k += q;
		31   eos = sieve + bytes; s = k + 1; *sieve = 1;
		32   for (n = p = q = r = 0; n < s; n++)
			33   { DO(p++,0,28, 0, 2, 0,p,0,r,1,q,2,k,3,q,4,k,5,q,6,r,7); r++;
				34     DO(q++,1,24, 6,14, 1,r,5,q,4,p,0,k,7,p,3,q,2,r,6,p,1); r++; q++;
				35     DO(p-1,2,26, 9,22, 4,q,0,k,6,q,1,k,7,q,3,r,5,p,2,r,4); r++;
				36     DO(q-1,3,28,12,26, 5,p,5,q,2,p,1,k,7,r,4,p,3,r,0,k,6);
				37     DO(q+1,4,26,15,34, 9,q,5,p,6,k,0,r,3,p,4,r,7,k,1,p,2); r++;
				38     DO(p+1,5,28,17,38,12,k,0,q,4,r,2,p,5,r,3,q,7,k,1,q,6); r++; q++;
				39     DO(q++,6,26,20,46,17,k,5,r,1,p,6,r,2,k,3,p,7,q,0,p,4); r++;
				40     DO(p++,7,24,23,58,28,r,0,k,7,r,6,q,5,p,4,q,3,p,2,q,1);
				41   }
		42   a[1]=2,a[2]=3,a[3]=5;
		43   int tot=3;
		44   for (p = 0; p < bytes&&tot<=5000000; p++)
			45     for (k = 0; k < 8; k++)
			46       if (!(sieve[p] & (1<<k))) a[++tot]=30 * p+bits[k];
		47   scanf("%ld",&bytes);
		48   while(bytes--)
			49   {
				50       scanf("%d",&i);
				51       printf("%d\n",a[i]);
				52   }
		53   return 0;
		54 }
