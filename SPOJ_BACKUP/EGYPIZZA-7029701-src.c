#include<stdio.h>
int main()
{
	int n,count12=0,count14=0,count34=0,pizzas=0;
	scanf("%d%*c",&n);
	while(n--)
	{
		char ch1,ch2;
		int j;
		scanf("%c%*c%c%*c",&ch1,&ch2);
		if(ch1 =='1' && ch2 == '2')
			count12++;
		else if(ch1 == '1' && ch2 == '4')
			count14++;
		else if(ch1 == '3' && ch2 == '4')
			count34++;
	}
	pizzas += (count12%2==0)?count12/2:count12/2+1;
	int x=count12%2;
	if(count14==count34)
		pizzas += count14;
	else
	{
		if(count34 > count14)
			pizzas += count34;
		else
		{
			pizzas += count34;
			count14 = count14 - count34;
			pizzas += count14/4;
			int t=count14%4;
			if(t!=0)
			{
				if(x==1)
				{
					if(t==3)
						pizzas+=1;
				}
				else
					pizzas +=1;
			}
		}
	}
	printf("%d\n",pizzas+1);
	return 0;
}
