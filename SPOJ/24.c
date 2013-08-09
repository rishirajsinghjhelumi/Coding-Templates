#include<stdio.h>
#include<string.h>
int calc_pro(char a[],char b[],char d[],char C[],int n1,int n2);
char ch,d[10000000],C[10000000],a[10000000],b[10000000];
int main()
{
	int test_cases,i,j,k,l,n1,n2,r,e,m,rem,car,sum,check,x,y,n;
	scanf("%d",&test_cases);
	for(r=0;r<test_cases;r++)
	{
		j=k=n1=n2=m=e=rem=car=sum=x=y=check=i=l=0;
		int ni,nj;
		scanf("%d",&n);
		if(n==1)
		{
			printf("1\n");
			continue;
		}
		ni=n;
		nj=n-1;
		k=l=0;
		while(ni!=0)
		{
			a[k++] = ni % 10+48;
			ni = ni / 10;
		}
		a[k] = '\0';
		n1=k;
		for(i=0;i<n1/2;i++)
		{
			ch = a[i];
			a[i] = a[n1-i-1];
			a[n1-1-i] = ch;
		}
		while(nj!=0)
		{
			b[l++] = nj % 10+48;
			nj = nj / 10;
		}
		b[l] = '\0';
		n2=l;
		for(i=0;i<n2/2;i++)
		{
			ch = b[i];
			b[i] = b[n2-i-1];
			b[n2-1-i] = ch;
		}
		check=calc_pro(a,b,d,C,n1,n2);
		n--;
		n--;
		while(n>=1)
		{
			ni=n;
			k=0;
			while(ni!=0)
			{
				a[k++] = ni % 10+48;
				ni = ni / 10;
			}
			a[k] = '\0';
			n1=k;
			for(i=0;i<n1/2;i++)
			{
				ch = a[i];
				a[i] = a[n1-i-1];
				a[n1-1-i] = ch;
			}
			n2=check;
			for(i=check;i>=0;i--)
				b[check-i]=C[i]+48;
			b[check+1] = '\0';
			check=calc_pro(a,b,d,C,n1,n2+1);
			n--;
		}
		for(i=check;i>=0;i--)
			printf("%c",C[i]+48);
		printf("\n");
	}
	return 0;
}
int calc_pro(char a[],char b[],char d[],char C[],int n1,int n2)
{
	int i,j,k=0,check,rem,x=0,sum,y;
	for(i=n2-1;i>=0;i--)
	{   
		rem=0;
		for(j=n1-1;j>=0;j--)
		{   
			d[k++] = ((b[i]-48)*(a[j]-48) + rem)%10;
			rem = ((b[i]-48)*(a[j]-48)+rem)/10;
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
	C[k+1] ='\0';
	j=0;
	check = k;
	for(j=k;j>=1;j--)
	{   
		if(C[j]==0)
			check--;
		else 
			break;
	}
	return check;
}
