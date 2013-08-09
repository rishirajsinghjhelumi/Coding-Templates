#include<stdio.h>
#include<ctype.h>
#define max 1000000
int a[max],hash[max<<1];
int main()
{
	int test_cases;
	scanf("%d%*c",&test_cases);
	while(test_cases--)
	{
		int i=0,j=0,m,k,l=0,index=1<<30,sum=0,len=0;
		char ch;
		scanf("%c",&ch);
		while(ch!='\n')
		{
			if(ch==' ')
				sum += 32;
			else if(islower(ch))
				sum += ch - 96;
			else if(isupper(ch))
				sum += ch - 14;
			a[i++] = sum;
			scanf("%c",&ch);
		}
		scanf("%d%d%*c",&m,&k);
		for(j=0;j<i;j++)
		{
			a[j] %=m;
			printf("%d ",a[j]);
			hash[a[j]+k] = j;
		}
		printf("\n");
		for(j=0;j<m+k;j++)
			printf("%d ",hash[j]);
		printf("\n");
		printf("%d %d\n",index,len);
	}
	return 0;
}
