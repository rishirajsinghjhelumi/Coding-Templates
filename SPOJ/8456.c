#include<stdio.h>
int p[10010]={0},i,j;
int main()
{
	for(i=2;i<=101;i++)
		if(!p[i])
			for(j=i+i;j<10010;j+=i)
				p[j]=1;
	int test_cases;
	scanf("%d",&test_cases);
	for(i=1;i<=test_cases;i++)
	{
		int n;
		scanf("%d",&n);
		if(p[n])
			printf("%d:NOTPRIME\n",i);
		else
			printf("%d:%d\n",i,(n==3)?2:1);
	}
	return 0;
}
