#include<stdio.h>
#include<math.h>
int main()
{
	int test_cases;
	scanf("%d",&test_cases);
	while(test_cases--)
	{
		long long int x,y,s,i,j,a,r=1,n,d;
		scanf("%lld%lld%lld",&x,&y,&s);
		for(i=0;;i++)
			if(y*i*i*i*i*i-s*i*i*i+s*i*i-x==0)
				break;
		a=x/(i*i);
		r=i;
		printf("%lld\n",n);
		r=1;
		for(j=1;j<n;j++)
		{
			printf("%lld ",a*r);
			r=r*i;
		}
		printf("%lld\n",a*r);
	}
	return 0;
}
