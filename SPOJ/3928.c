#include<stdio.h>
#include<math.h>
typedef long long int ull;
ull digit[9][10];
ull count[2][10];
ull num_digits(ull x,ull n);
ull zero(ull x, ull n);
int main()
{
	ull i,c=1,x,j;
	ull d[9]={0,1,10,190,2890,38890,488890,5888890,68888890};
	for(i=0;i<9;i++)
		digit[i][0]=d[i];
	for(i=1;i<9;i++)
	{
		x = i*c;
		for(j=1;j<10;j++)
			digit[i][j] = x;
		c*=10;
	}
	ull a,b,t;
	while(scanf("%lld%lld",&a,&b) && (a|b))
	{
		if(a>b)
		{
			t=b;
			b=a;
			a=t;
		}
		num_digits(b,0);
		num_digits(a-1,1);
		zero(b,0);
		zero(a-1,1);
		for(i=0;i<10;i++)
			printf("%lld ",count[0][i]-count[1][i]);
		printf("\n");
	}
	return 0;
}
ull num_digits(ull x,ull n)
{
	ull i,ten=1;
	for(i=0;i<10;i++)
		count[n][i] = 0;
	ull a[10],j=0,b,min=0;
	while(x)
	{
		a[j++] = x%10;
		x/=10;
		ten*=10;
	}
	ten/=10;
	for(i=j-1;i>=0;i--)
	{
		b = a[i];
		ull num=0;
		for(j=0;j<10;j++)
			count[n][j] += b*digit[i][j];
		for(j=1;j<b;j++)
			count[n][j] += ten;
		for(j=i-1;j>=0;j--)
			num = num*10 + a[j];
		count[n][b] += num+1;
		ten/=10;
	}
}
ull zero(ull x, ull n)
{
	ull d,j=0,r=0,rem=0,v;
	count[n][0] = 0;
	while(x)
	{
		d=x%10;
		x/=10;
		if(j)
		{
			count[n][0]+=d*pow(10,j-1)*j;
			if(!d) 
				rem+=(pow(10,j)-1)-r;
		}
		r = pow(10,j++)*d+r;
	}
	count[n][0] -= rem;
}
