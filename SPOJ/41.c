#include<stdio.h>
int main()
{
	int test_cases;
	scanf("%d",&test_cases);
	while(test_cases--)
	{
		int n,i,j,k;
		scanf("%d%*c",&n);
		char ch,a[n][2];
		for(i=0;i<n;i++)
		{
			scanf("%c",&a[i][0]);
			ch='*';
			while(ch!='\n')
			{
				a[i][1] = ch;
				scanf("%c",&ch);
			}
		}
		for(i=0;i<n;i++)
			printf("%c %c\n",a[i][0],a[i][1]);
	}
	return 0;
}
