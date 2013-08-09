#include<stdio.h>
int main()
{
	int test_cases;
	scanf("%d",&test_cases);
	scanf("%*c");
	while(test_cases--)
	{
		long long int ans=0,a[2];
		char ch='*',c='*';
		int k=0;
		while(c!='=')
		{
			scanf("%c",&c);
			if(c>=48 && c<=57)
			{
				k++;
				a[k-1]=0;
				a[k-1]=(a[k-1]<<3) + (a[k-1]<<1) + c - 48;
				while(1)
				{
					scanf("%c",&c);
					if( c<48 || c>57 )
						break;
					a[k-1]=(a[k-1]<<3) + (a[k-1]<<1) + c - 48;
				}
				if(k == 2)
				{
					if(ch == '*')
						ans = a[0] * a[1];
					else if(ch == '/')
						ans = a[0] / a[1];
					else if(ch == '+')
						ans = a[0] + a[1];
					else if(ch == '-')
						ans = a[0] - a[1];
					k--;
					a[0] = ans;
				}
			}
			if(c=='*' || c=='/' || c=='+' || c=='-' )
				ch = c;
		}
		scanf("%*c");
		printf("%lld\n",a[0]);
	}
	return 0;
}
