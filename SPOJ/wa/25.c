#include<stdio.h>
int main()
{
	int a,b,c,i,test_cases,a_fill=0,b_fill=0,steps=0,sub=0,xa_fill=0,xb_fill=0,xsteps=0;
	scanf("%d",&test_cases);
	for(i=0;i<test_cases;i++)
	{
		steps=xsteps=sub=a_fill=b_fill=xa_fill=xb_fill=0;
		scanf("%d %d %d",&a,&b,&c);
		if(b>a)
		{
			a=a+b;
			b=a-b;				// Variable Swapping
			a=a-b;
		}
		int r=a%b,a1=a,b1=b;
		while(r!=0)
		{
			a1=b1;
			b1=r;
			r=a1%b1;
		}
		printf("%d\n",b1);
		if(c==0)
			steps=0;
		else if(c==a || c==b)
			steps=1;
		else if(b1 >b || (c>a && c>b))
			steps=-1;
		else if(b1!=1)
			steps=-1;
		else
		{
			while(a_fill!=c && b_fill!=c && xa_fill!=c && xb_fill!=c)
			{
				if(xa_fill==0)
				{
					xa_fill=b;
					xsteps++;
				}
				else if(xb_fill==a)
				{
					xb_fill=0;
					xsteps++;
				}
				else
				{
					sub=a-xb_fill;
					xa_fill=xa_fill-sub;
					xb_fill=a;
					if(xa_fill<0)
					{
						xb_fill=xb_fill+xa_fill;
						xa_fill=0;
					}
					xsteps++;
				}
				if(a_fill==0)
				{
					a_fill=a;
					steps++;
				}
				else if(b_fill==b)
				{
					b_fill=0;
					steps++;
				}
				else
				{
					sub=b-b_fill;
					a_fill=a_fill-sub;
					b_fill=b;
					if(a_fill<0)
					{
						b_fill=b_fill+a_fill;
						a_fill=0;
					}
					steps++;
				}
			}
		}
		printf("%d\n",steps);
	}
	return 0;
}
