#include<stdio.h>
#define range 100000000000
#define U 1
#define L 0
#define max 10000000
typedef unsigned long long int ull;
ull a[max+10][2];
int main()
{
	a[1][0] = a[1][1] = 1;
	ull i,j=2,k=2,count=1,times=2;
	while(count<=range)
	{
		for(i=0;i<times;i++)
		{
			a[j][L] = a[j-1][U] + 1;
			a[j][U] = a[j][L] + k - 1;
			j++;
			count += k;
		}
		k++;
		times = a[k][U] - a[k][L] + 1;
	}
	j--;
	printf("K==%llu times==%llu\n",k,times);
	printf("count==%llu\n",count);
	printf("%llu L=%llu H=%llu\n",j,a[j][L],a[j][U]);
	return 0;
}
