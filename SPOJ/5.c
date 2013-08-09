#include<stdio.h>
int main()
{
	int test_cases;
	scanf("%d%*c",&test_cases);
	while(test_cases--)
	{
		char a[1000000];
		int i,j,k,len,changed=0,x,large=0,palin=1;
		for(i=0;a[i-1]!='\n';i++)
			scanf("%c",&a[i]);
		a[i-1] = '\0';
		len = i-1;
		if(len%2==0)
		{
			x=len/2-1;
			for(i=0;i<len/2;i++)
			{
				if(a[i] - 48 == a[i+1+x] - 48)
					continue;
				else if(a[i] - 48 > a[i+1+x] - 48)
				{
					large = 1;
					break;
				}
				else if(a[i] - 48 < a[i+1+x] - 48)
				{
					large = 0;
					break;
				}
			}
			if(large==1)
				for(i=x;i>=0;i--)
					a[len-1-i] = a[i];
			else
			{
			}
		}
		else
		{
			x=len/2;
			for(i=0;i<len/2;i++)
			{
				if(a[i] - 48 == a[i+1+x] - 48)
					continue;
				else if(a[i] - 48 > a[i+1+x] - 48)
				{
					large = 1;
					break;
				}
				else if(a[i] - 48 < a[i+1+x] - 48)
					break;
			}
			for(i=0;i<len/2;i++)
				if(a[i] - 48 != a[len-1-i] - 48)
				{
					palin=0;
					break;
				}
			printf("l==%d  p==%d\n",large,palin);
			if((palin==0 && large==0)||(palin==1))
			{
				while(1)
				{
					if(x<0 || changed==1)
						break;
					else if(a[x] - 48 != 9)
					{
						a[x] = a[x] + 1;
						a[len-x-1] = a[x];
						changed=1;
					}
					else if(a[x] - 48 == 9)
						a[x] = a[len-x-1] = '0';
					x--;
				}
			}
			if(x>=0)
				for(i=x;i>=0;i--)
					a[len-1-i] = a[i];
			else if(x<0 && changed==0)
			{
				a[0] = a[len] = '1';
				a[len+1] = '\0';
			}
		}
		printf("%s\n",a);
	}
	return 0;
}
