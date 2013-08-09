#include<stdio.h>
int p[10000]={0},prime[1100],k=0;
int main()
{
	int i,j;
	for(i=2;i<101;i++)
		if(!p[i])
			for(j=i+i;j<10000;j+=i)
				p[j]=1;
	for(j=1001;j<10000;j+=2)
		if(!p[j])
			prime[k++] = j;
	int test_cases;
	scanf("%d",&test_cases);
	while(test_cases--)
	{
		int p1,p2,count=0;
		scanf("%d%d",p1,p2);

	}
	return 0;
}
