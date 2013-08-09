#include<stdio.h>
int main()
{
	int test_cases;
	scanf("%d",&test_cases);
	while(test_cases--)
	{
		int t,b,num1,num2,ans=0,y=1,d1,d2,x;
		scanf("%d%d%d%d",&t,&b,&num1,&num2);
		while((num1)||(num2))
		{
			d1 = num1%b;
			d2 = num2%b;
			num1 /=b;
			num2 /=b;
			x = (d1+d2)%b;
			ans += x*y;
			y *=b;
		}
		printf("%d %d\n",t,ans);
	}
	return 0;
}
