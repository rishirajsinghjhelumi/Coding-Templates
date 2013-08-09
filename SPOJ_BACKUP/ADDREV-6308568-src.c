#include<stdio.h>
int main()
{
	int test_cases,i;
	scanf("%d",&test_cases);
	for(i=0;i<test_cases;i++)
	{
		int a,b,c=0,d=0,j,k,res,ans=0;
		scanf("%d %d",&a,&b);
		while(a != 0)
		{
			j = a % 10;
			a = a / 10;
			c = 10 * c + j;
		}
		while(b != 0)
		{
			k = b % 10;
			b = b / 10;
			d = 10 * d + k;
		}
		res = c + d;
		while(res != 0)
		{
			j = res % 10;
			res = res / 10;
			ans = 10 * ans + j;
		}
		printf("%d\n",ans);
	}
	return 0;
}
