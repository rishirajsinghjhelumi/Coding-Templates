#include<stdio.h>
#include<algorithm>
#define max 100000
typedef long long int lld;
lld a2[60];
lld a3[60];
lld a5[60];
lld a7[60];
lld res[max];
int main()
{
	lld m = 1000000000;
	m *= m;
	int a,b,c,d,k=0;
	a2[0] = a3[0] = a5[0] = a7[0] = 1;
	for(a=1;a<55;a++)
		a2[a] = a2[a-1] * 2;
	for(a=1;a<37;a++)
		a3[a] = a3[a-1] * 3;
	for(a=1;a<19;a++)
		a5[a] = a5[a-1] * 5;
	for(a=1;a<19;a++)
		a7[a] = a7[a-1] * 7;
	lld x;
	for(a=0;a<55;a++)
	{
		x = a2[a];
		for(b=0;b<37;b++)
		{
			if(m / x < a3[b])
				break;
			x *= a3[b];
			for(c=0;c<19;c++)
			{
				if(m / x < a5[c])
					break;
				x *= a5[c];
				for(d=0;d<19;d++)
				{
					if(m / x < a7[d])
						break;
					res[k++] = x * a7[d];
				}
				x /= a5[c];
			}
			x /= a3[b];
		}
	}
	int j;
	std::sort(res,res+k);
	for(j=1;j<37;j++)
		for(a=0;a<100;a++)
			printf("%d %lld\n",j,res[a]);
	return 0;
}
