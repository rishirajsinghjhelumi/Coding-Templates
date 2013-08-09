#include<stdio.h>
long long int find_sum_dig(int n);
unsigned long long int x[10],u[10];
int main()
{
	int a,b,i;
	unsigned long long int c=1;
	for(i=1;i<=10;i++)
	{
		x[i-1] = 45*i*c;
		u[10-i] = c;
		c=(c<<3)+(c<<1);
	}
	scanf("%d%d",&a,&b);
	while(a!=-1 && b!=-1)
	{
		printf("%lld\n",find_sum_dig(b)-find_sum_dig(a-1));
		scanf("%d%d",&a,&b);
	}
	return 0;
}
long long int find_sum_dig(int n)
{
	int i,j=0,a=n;
	int t[10],s[10];
	long long int sum=0;
	for(i=1000000000;i>=1;i/=10)
	{
		t[9-j] = a/i;
		s[9-j]=a=a-t[9-j]*i;
		j++;
	}
	sum+=t[0]*(t[0]+1)/2;
	for(i=1;i<10;i++)
	{
		if(t[i] == 0)
			continue;
		sum+=(t[i]*x[i-1])+(t[i]*(t[i]-1)/2)*u[9-i]+(1+s[i])*t[i];
	}
	return sum;
}
