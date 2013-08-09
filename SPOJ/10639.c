#include<stdio.h>
int main()
{
	int test_cases;
	scanf("%d",&test_cases);
	while(test_cases--)
	{
		int n,x,y,r;
		char ch1,ch2;
		scanf("%d",&n);
		n--;
		x = n/5;
		y = n%5;
		if( ( !(x%2) && y) || ( x%2 && !y ) )
		{
			if(y==0)
				ch1='W',ch2='R';
			else if(y==1)
				ch1='W',ch2='L';
			else if(y==2)
				ch1='A',ch2='L';
			else if(y==3)
				ch1='A',ch2='R';
			else if(y==4)
				ch1='M',ch2='R';
			r = (y)?x+1:x;
		}
		else
		{
			if(y==0)
				ch1='W',ch2='L';
			else if(y==1)
				ch1='W',ch2='R';
			else if(y==2)
				ch1='M',ch2='R';
			else if(y==3)
				ch1='A',ch2='R';
			else if(y==4)
				ch1='A',ch2='L';
			r = (y)?x+1:x;
		}
		if(n)
			printf("%d %c %c\n",r,ch1,ch2);
		else
			printf("poor conductor\n");
	}
	return 0;
}
