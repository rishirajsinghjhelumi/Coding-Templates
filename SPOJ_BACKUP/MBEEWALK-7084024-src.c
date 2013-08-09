#include<stdio.h>
int main()
{
	int test_cases,a[]={1, 0, 6, 12, 90, 360, 2040, 10080, 54810, 290640, 1588356, 8676360, 47977776, 266378112, 1488801600};
	scanf("%d",&test_cases);
	while(test_cases--)
	{
		int n;
		scanf("%d",&n);
		printf("%d\n",a[n]);
	}
	return 0;
}
