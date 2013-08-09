#include<stdio.h>
#include<math.h>
#define max 110000000
#define log2(x) log(x)/log(2)
#define root sqrt(max)+1
typedef unsigned long long int ull;
ull i,j,k=0,count=0;
char p[max];
//ull primes[max/10];
int main()
{
	for(i=2;i<root;i++)
		if(!p[i])
			for(j=i*i;j<max;j+=i+i)
				p[j]='1';
	count=2;
	for(i=3;i<max;i+=2)
		if(!p[i])
		{
			count += (int)(log2(i)) + 1;
			//primes[k++] = i;
		}
	printf("%llu\n",count);
	return 0;
}
