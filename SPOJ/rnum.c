#include<stdio.h>
int p[20];
int main()
{
	p[2]=p[3]=p[5]=p[7]=p[11]=p[13]=p[17]=p[19]=1;
	int m1,i,count=4,a[10],j;
	scanf("%d",&m1);
	for(i=10;i<=m1;i++)
	{
		int x=i,l=0,check=1;
		while(x)
		{
			a[l++]=x%10;
			x/=10;
			if(a[l-1]==0)
			{
				check=0;
				break;
			}
		}
		for(j=0;j<l-1;j++)
			if(p[a[j]+a[j+1]]==0)
			{
				check = 0;
				break;
			}
		if(check)
		{
		//	printf("%d\n",i);
			count++;
		}
	}
	printf("%d\n",count);
	return 0;
}
