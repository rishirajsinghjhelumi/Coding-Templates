#include<stdio.h>
int main()
{
	int i,a[1000010]={0},b,j,pos[1000010];
	for(i=2;i<=100;i++)
	{
		b = i*i*i;
		for(j=b;j<=1000000;j+=b)
			a[j] = 1;
	}
	b=1;
	for(i=1;i<=1000000;i++)
		if(a[i] == 0)	
			pos[i] = b++;
	int test_cases,t;
	scanf("%d",&test_cases);
	for(t=1;t<=test_cases;t++)
	{
		int n;
		scanf("%d",&n);
		if(a[n]==0)
			printf("Case %d: %d\n",t,pos[n]);
		else
			printf("Case %d: Not Cube Free\n",t);
	}
	return 0;
}
