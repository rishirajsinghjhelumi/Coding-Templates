#include<stdio.h>
int main()
{
	int test_cases;
	scanf("%d",&test_cases);
	while(test_cases--)
	{
		long long int m,n,r;
		char ch;
		scanf("%lld%lld",&n,&m);
		if(n<=m)
			ch = (n&1)?'R':'L';
		else
			ch = (m&1)?'D':'U';
		printf("%c\n",ch);
	}
	return 0;
}
