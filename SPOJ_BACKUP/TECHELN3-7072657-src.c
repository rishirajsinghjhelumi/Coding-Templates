#include<stdio.h>
#include<string.h>
int main()
{
	int test_cases;
	scanf("%d%*c",&test_cases);
	while(test_cases--)
	{
		char ch[10000];
		scanf("%s",ch);
		if( (ch[strlen(ch)-1]-48)%2==0 )
			printf("Mandark\n");
		else
			printf("Dexter\n");
	}
	return 0;
}
