#include<stdio.h>
int main()
{
	int test_cases;
	scanf("%d%*c",&test_cases);
	while(test_cases--)
	{
		char ch;
		int i,j,count=1,max=0,len,p_len=0,m_len;
		scanf("%c",&ch);
		if(ch=='\n')
		{
			test_cases++;
			continue;
		}
		printf("%d\n",max);
	}
	return 0;
}
