#include<stdio.h>
int main()
{
	int i,j,k,test_cases,n,a[10000],b[10000],lis;
	lis=0;
	for(j=0;j<10000;j++)
		a[j]=b[j]=0;
	scanf("%d",&n);
	for(j=0;j<n;j++)
		scanf("%d",&a[j]);
	for(j=0;j<n;j++)
	{
		for(k=0;k<j;k++)
			if( ( a[j] > a[k] ) && ( ( b[k]+1 ) > b[j] ) )
				b[j]=b[k]+1;
		if( b[j] > lis)
			lis=b[j];
	}
	printf("%d\n",lis+1);
	return 0;
}
