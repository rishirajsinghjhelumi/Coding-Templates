#include<stdio.h>
int main()
{
	char a[][100]={"Sunday","Monday","Tuesday","Wednesday","Thursday","Friday","Saturday"};
	int test_cases;
	scanf("%d",&test_cases);
	while(test_cases--)
	{
		int y,m,d,w;
		scanf("%d%d%d",&d,&m,&y);
		w = dow(y,m,d);
		printf("%s\n",a[w]);
	}
	return 0;
}
int dow(int y, int m, int d)
{
	static int t[] = {0, 3, 2, 5, 0, 3, 5, 1, 4, 6, 2, 4};
	y -= m < 3;
	return (y + y/4 - y/100 + y/400 + t[m-1] + d) % 7;
}
