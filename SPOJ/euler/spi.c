#include<stdio.h>
int a[2000][2000],p[17000]={0},k=0;
void generate(int n)
{
	int i,h,c=n*n;
	for(h=0;h<n/2;h++)
	{
		for(i=h;i<n-h;i++)
			a[h][i]=c--;
		for(i=h+1;i<n-h;i++)
			a[i][n-h-1]=c--;
		for(i=n-h-1-1;i>=h;i--)
			a[n-h-1][i]=c--;
		for(i=n-h-1-1;i>h;i--)
			a[i][h]=c--;
	}
	if(n%2!=0)
		a[(n/2)][(n/2)]=c--;
}
void prime_seive()
{
	int i,j;
	for(i=2;i<17000;i++)
		if(p[i]==0)
		{
			for(j=2*i;j<17000;j=j+i)
				p[j] = 1;
		}
	p[1] = 1;
}
int main()
{
	generate(1001);
	int i,j;
	unsigned long long int sum=0;
	for(i=0;i<1001;i++)
	{
		sum+=a[i][i];
		sum+=a[i][1000-i];
	}
	printf("%llu\n %d\n",sum,a[1001/2][1001/2]);
	return 0;
}
