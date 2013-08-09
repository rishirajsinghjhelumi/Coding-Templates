#include<stdio.h>
#include<math.h>
#define max 10000010
#define root sqrt(max)+1
int gcd(a,b)
{
	if(b==0)
		return a;
	return gcd(b,a%b);
}
int i,j,k=1;
int p[max]={0};
int main()
{
	for(i=2;i<root;i++)
		if(!p[i])
			for(j=i+i;j<max;j+=i)
				p[j]=1;
	p[0]=p[1]=1;
	int test_cases;
	scanf("%d",&test_cases);
	while(test_cases--)
	{
		int a,b,i,j;
		scanf("%d%d",&a,&b);
		unsigned long long int count = 0;
		for(i=1;i<=a;i++)
		{
			if(p[i]==0)
				count += b/i;
			else
			{
				for(j=1;j<=b;j++)
				{
					if(p[gcd(i,j)]==0)
						count++;
				}
			}
		}
		printf("%llu\n",count);
	}
	return 0;
}
