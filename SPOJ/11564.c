#include<stdio.h>
int main()
{
	while(1)
	{
		long long int a,b;
		int num=1;
		char ch;
		scanf("%lld",&a);
		scanf("%c",&ch);
		if(ch==' ')
		{
			scanf("%lld",&b);
			num++;
		}
		if(num==2)
			if(a==0 && b==0)
				break;
		if(num==1)
		{
			long long int x,y,d,mod;
			d = a / 23;
			mod = a % 23;
			if(d%2 == 0 && mod != 0)
			{
				x = (d/2)*23 + 2;
				y = (d/2)*23 + mod;
			}
			else if(d%2==1 && mod == 0)
			{
				x = ((d-1)/2)*23 + 2;
				y = ((d-1)/2)*23 + 23;
			}
			else if(d%2==1 && mod!=0)
			{
				y = (((d-1)/2)+1)*23 + 1;
				x = ((d-1)/2)*23 + mod + 1;
			}
			else if(d%2==0 && mod ==0)
			{
				y = (d/2)*23 + 1;
				x = y;
			}
			printf("%lld, %lld\n",x,y);
		}
		else if(num==2)
		{
			long long int number = a+b-2;
			long long int x,y,d,mod;
			d = number / 23;
			mod = number % 23;
			if(d%2 == 0 && mod != 0)
			{
				x = (d/2)*23 + 2;
				y = (d/2)*23 + mod;
			}
			else if(d%2==1 && mod == 0)
			{
				x = ((d-1)/2)*23 + 2;
				y = ((d-1)/2)*23 + 23;
			}
			else if(d%2==1 && mod!=0)
			{
				y = (((d-1)/2)+1)*23 + 1;
				x = ((d-1)/2)*23 + mod + 1;
			}
			else if(d%2==0 && mod ==0)
			{
				y = (d/2)*23 + 1;
				x = y;
			}
			if(x==a && y==b)
				printf("%lld\n",number);
			else
				printf("No Number\n");
		}
	}
	return 0;
}
