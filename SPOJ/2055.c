#include<stdio.h>
#include<string.h>
typedef long long int ll;
ll decimal_to_base(ll base,ll number);
ll base_to_decimal(ll base,ll number);
int main()
{
	char a[10];
	while(1)
	{
		scanf("%c%c%c",&a[0],&a[1],&a[2]);
		if(a[0]=='e' && a[1]=='n'&&a[2]=='d')
			break;
		else if(a[0]=='t' && a[1]=='o' && a[2]=='-')
		{
			ll base,number;
			scanf("%lld%lld",&base,&number);
			printf("%lld\n",decimal_to_base(base,number));
		}
		else
		{
			ll base;
			scanf("%*c%*c%lld%lld",&base,&number);
			printf("%lld\n",base_to_decimal(base,number));
		}
		scanf("%*c");
	}
	return 0;
}
ll decimal_to_base(ll base,ll number)
{
	ll num[100],i=0,j,x;
	base *=-1;
	while(number)
	{
		num[i++] = number%base;
		number /=base;
		if(num[i-1]<0)
		{
			number++;
			num[i-1] = num[i-1] + (base*-1);
		}
		printf("%lld",num[i-1]);
	}
	printf("\n");
	for(j=i-1;j>=0;j--)
		number = (number*10)+num[j];
	return number;
}
ll base_to_decimal(ll base,ll number)
{
	ll x=1,num=0,sign=1;
	while(number)
	{
		num += sign*(number%10)*x;
		sign *=-1;
		x *=base;
		number /=10;
	}
	return num;
}
