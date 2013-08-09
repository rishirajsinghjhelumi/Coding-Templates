#include<stdio.h>
int main()
{
	int i,j,k,test_cases,n,a[100000],b[100000],c[100000],lis=0;
	for(j=0;j<100000;j++)
		a[j]=b[j]=c[j]=0;
	scanf("%d",&n);
	for(j=0;j<n;j++)
		scanf("%d%d",&a[j],&c[j]);
	for(j=0;j<n;j++)
	{
		for(k=0;k<j;k++)
			if( ( a[j] > a[k] ) && ( ( b[k]+1 ) > b[j] ) && (c[j] > c[k]))
				b[j]=b[k]+1;
		if( b[j] > lis)
			lis=b[j];
	}
	printf("%d\n",lis+1);
	return 0;
}
