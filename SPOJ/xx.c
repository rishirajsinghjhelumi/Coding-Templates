#include<stdio.h>
unsigned long long int a[2000000],i;
int main()
{
	int t;
	a[0]=3;a[1]=7;
	for(i=2;i<2000000;i++)
		a[i]=a[i-2]+(i+2)*(i+3)/2;
	scanf("%d",&t);
	while(t--)
	{
		scanf("%llu",&i);
		if(i==0)
			printf("0\n");
		else
			printf("%llu\n",a[i-1]*2+((i-1)*(10*i*i+13*i+6))/3);
	}
	return 0;
}
