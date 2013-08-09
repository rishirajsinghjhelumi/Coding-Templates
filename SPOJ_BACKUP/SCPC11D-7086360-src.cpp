#include<stdio.h>
#include<algorithm>
int main()
{
	while(1)
	{
		long long int a[3];
		scanf("%lld%lld%lld",&a[0],&a[1],&a[2]);
		if(a[0] == 0 && a[1] == 0 && a[2] == 0)
			break;
		std::sort(a,a+3);
		printf("%s\n",(a[0]*a[0] + a[1]*a[1] == a[2]*a[2])?"right":"wrong");
	}
	return 0;
}
