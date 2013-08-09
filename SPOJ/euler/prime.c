#include<stdio.h>
#include<math.h>
int i,p[1000000]={0},j,prime[1000000],k=0;
unsigned long long int sum =0;
int main()
{
	for(i=2;i<1000000;i++)
		if(p[i]==0)
		{
			prime[k++] = i;
			for(j=2*i;j<1000000;j=j+i)
				p[j] = 1;
		}
	return 0;
}
