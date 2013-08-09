#include<stdio.h>
#include<string.h>
int main()
{
	long long int i,x=1,two[50];
	for(i=0;i<50;i++)
	{
		two[i] = x;
		x<<=1;
	}
	int test_cases;
	scanf("%d",&test_cases);
	while(test_cases--)
	{
		char str[100];
		scanf("%s",str);
		int len = strlen(str),i,j=0;
		long long int count = 1;
		for(i=1;i<len;i++)
		{
			if(str[i] == str[i-1])
				j++;
			else
			{
				count *=two[j];
				j=0;
			}
		}
		count *=two[j];
		printf("%lld\n",count);
	}
	return 0;
}
