#include<stdio.h>
#include<math.h>
int main()
{
	long long int time,a,d;
	unsigned long long int c=4000000007;
	double b,f;
	int i,j;
	int year,mon,day,hour,min,sec;
	scanf("%lld",&time);
	for(i=0;;i++)
	{
		b=sqrt(i*c+time);
		f=(long long int)(b)*1.000000;
		if(b==f)
		{
			d = f;
			year = (d / 31557600 ) + 1970;
			printf("%d\n",year);
		}
	}
	return 0;
}
