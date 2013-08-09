#include<stdio.h>
int power(int ,int );
int gen_prime(int , int , int [],int );
int main()
{
	int test_cases,b[50],a[100000],k=0,check,i,j,n,sum,l=0,gen=0,count[50],m,prev_n=0,x,temp;
	scanf("%d",&test_cases);
	while(test_cases--)
	{
		k=i=j=m=l=x=0;
		for(i=0;i<50;i++)
			count[i] = 0;
		scanf("%d",&n);
		temp=n;
		if(n > prev_n)
		{
			gen=gen_prime(gen,n,a,gen);
			prev_n=n;
		}
		while(n!=1)
		{
			if(n %  a[k] == 0)
			{
				n = n / a[k];
				b[l] = a[k];
				count[l]++;
			}
			else
			{
				if(count[l]!=0)
					l++;
				k++;
			}
		}
		sum=1;
		for(i=0;i<=l;i++)
		{
			x=(power(b[i],count[i]+1)-1)/(b[i]-1);
			sum *=x;
		}
		sum = sum - temp;
		printf("%d\n",sum);
	}
	return 0;
}
int power(int n,int x)
{
	int i,p=n;
	if(x==0)
		return 1;
	for(i=0;i<x-1;i++)
		n = n * p;
	return n;
}
int gen_prime(int n,int m, int a[],int k)
{
	int i,j,check=0;
	a[k++] = 2;
	if(n<3)
		n=3;
	for(i=n;i<=m;i++)
	{   
		check=0;
		for(j=0;j<k;j++)
			if(i % a[j] == 0)
			{   
				check = 1;
				break;
			}   
		if(check==0)
			a[k++] = i;
	}
	return k;
}
