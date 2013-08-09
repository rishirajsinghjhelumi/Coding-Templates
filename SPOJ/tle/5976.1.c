#include<stdio.h>
int main()
{
	int test_cases;
	scanf("%d",&test_cases);
	while(test_cases--)
	{
		int m,n,r,c,lr,lc,ur,uc;
		char ch='R';
		scanf("%d%d",&n,&m);
		lr=lc=0;
		ur=n-1;
		uc=m-1;
		unsigned long long int b=0,a=n*m;
		while(1)
		{
			b+=uc-lc+1;
			uc--;
			if(b>=a)
			{
				ch='R';
				break;
			}
			b+=ur-lr;
			ur--;
			if(b>=a)
			{
				ch='D';
				break;
			}
			b+=uc-lc+1;
			lc++;
			if(b>=a)
			{
				ch='L';
				break;
			}
			b+=ur-lr;
			lr++;
			if(b>=a)
			{
				ch='U';
				break;
			}
		}
		printf("%c\n",ch);
	}
	return 0;
}
