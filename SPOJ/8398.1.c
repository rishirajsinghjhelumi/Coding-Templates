#include<stdio.h>
#include<string.h>
int main()
{
	int test_cases;
	scanf("%d%*c",&test_cases);
	while(test_cases--)
	{
		char ch;
		int a=0,b,c=0,x=0,D,y=0,z=0;
		scanf("%c",&ch);
		if(ch!='x')
		{
			if(ch=='-')
			{
				scanf("%c",&ch);
				x=1;
			}
			while(ch!='*')
			{
				a=(a<<3)+(a<<1)+ch-48;
				scanf("%c",&ch);
			}
			if(x==1)
				a=-1*a;
		}
		else
			a=1;
		if(a==1)
			scanf("%*c%*c");
		else
			scanf("%*c%*c%*c");
		scanf("%c",&ch);
		if(ch=='=')
		{
			b=c=0;
			scanf("%*c%*c");
		}
		else if(ch=='-'||ch=='+')
		{
			x=(ch=='-')?1:0;
			scanf("%c",&ch);
			if(ch=='x')
			{
				b=1;
				if(x==1)
					b=-1;
			}
			else
			{
				while(1)
				{
					if(ch=='*' || ch=='=')
						break;
					z=(z<<3)+(z<<1)+ch-48;
					scanf("%c",&ch);
				}
				if(x==1)
					z=-1*z;
				if(ch=='=')
				{
					b=0;
					c=z;
					scanf("%*c%*c");
				}
				else if(ch=='*')
				{
					b=z;
					scanf("%*c");
				}
			}
		}
		if(ch!='=')
		{
			scanf("%c",&ch);
			if(ch=='=')
			{
				c=0;
				scanf("%*c%*c");
			}
			else if(ch=='+' || ch=='-')
			{
				x=(ch=='-')?1:0;
				scanf("%c",&ch);
				while(ch!='=')
				{
					c=(c<<3)+(c<<1)+ch-48;
					scanf("%c",&ch);
				}
				if(x==1)
					c=-1*c;
				scanf("%*c%*c");
			}
		}
		//printf("a==%d b==%d c==%d\n",a,b,c);
		D=b*b-4*a*c;
		if(D==0)
			printf("Equal roots.\n");
		else if(D>0)
			printf("Distinct real roots.\n");
		else
			printf("Imaginary roots.\n");
	}
	return 0;
}
