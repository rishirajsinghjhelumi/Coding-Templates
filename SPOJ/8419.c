#include<stdio.h>
long long gcd(long long a,long long b)
{ 
	if(b==0)
		return a;
	return gcd(b,a%b);
}
int main()
{ 
	long long test_cases,x1,y1,x2,y2,n1,n2,flag;
	scanf("%lld",&test_cases);
	while(test_cases--)
	{ 
		scanf("%lld%lld%lld%lld",&x1,&y1,&x2,&y2);
		if(x1<0)
			x1=-x1;
		if(y1<0)
			y1=-y1;
		if(x2<0)
			x2=-x2;
		if(y2<0)
			y2=-y2;
		n1=gcd(x1,y1);
		n2=gcd(x2,y2);
		flag=0;
		while (n1 > 0 && n1 < n2)
			n1 *= 2;
		if(n1==n2)
			printf("YES\n");
		else
			printf("NO\n");
	}
	return 0;
} 
