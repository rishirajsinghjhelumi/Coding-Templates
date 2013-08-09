#include<stdio.h>
int get_digits(int n,int *s)
{
	while(n)
	{
		s[n%10]++;
		n/=10;
	}
}
int main()
{
	int i,j,m,count=0;
	while(scanf("%d",&m) && m)
	{
		count=0;
		for(i=1;i<=m;i++)
		{
			int s[10]={0};
			get_digits(i,s);
			if(s[3]==s[6] && s[6]==s[9] && s[3]>0)
				count++;
		}
		printf("%d\n",count);
	}
	return 0;
}
