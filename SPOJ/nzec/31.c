#include<stdio.h>
int main()
{
	int test_cases,i,j,k,l,n1,n2,r,e,m,rem,car,sum,check,x,y,a[100000],b[100000];
	char ch,d[1000000],C[1000000];
	scanf("%d",&test_cases);
	scanf("%*c");
	for(r=0;r<test_cases;r++)
	{
		j=k=n1=n2=m=e=rem=car=sum=x=y=check=i=l=0;
		for(e=0;e<100000;e++)
			a[e]=b[e]=0;
		while(ch!=' ')
		{
			scanf("%c",&ch);
			a[j]=ch-48;
			j++;
		}
		n1=j-1;
		while(ch!='\n')
		{
			scanf("%c",&ch);
			b[k]=ch-48;
			k++;
		}
		n2=k-1;
		k=0;
		for(i=n2-1;i>=0;i--)
		{
			rem=0;
			for(j=n1-1;j>=0;j--)
			{
				d[k++] = (b[i]*a[j] + rem)%10;
				rem = (b[i]*a[j]+rem)/10;
			}
			d[k++] = rem;
			x++;
			for(y=0;y<x;y++)
				d[k++] = 0;
		}
		k=rem=0;
		for(i=0;i<n1+n2;i++)
		{
			sum=0;
			y=0;
			for(j=1;j<=n2;j++)
			{
				if(i <= n1+j-1)
					sum = sum + d[y+i];
				y=y+j+ n1;
			}
			C[k++] = (sum+rem) %10;
			rem=(sum+rem)/10;
		}
		C[k]=rem;
		j=0;
		check=k;
		for(j=k;j>=1;j--)
		{
			if(C[j]==0)
				check--;
			else 
				break;
		}
		for(i=check;i>=0;i--)
			printf("%c",C[i]+48);
		printf("\n");
	}
	return 0;
}
