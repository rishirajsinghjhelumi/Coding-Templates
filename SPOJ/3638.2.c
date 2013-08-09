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
		while(1)
		{
			if(ch=='\n'||ch==' ')
				break;
			p_len++;
			scanf("%c",&ch);
		}
		if(p_len>=1)
			max = count = 1;
		else
			max=count=0;
		if(ch!='\n')
		{
			scanf("%c",&ch);
			while(ch!='\n')
			{
				len = 0;
				while(1)
				{
					if(ch=='\n'||ch==' ')
						break;
					len++;
					scanf("%c",&ch);
				}
				if(p_len==len)
					count++;
				else if(len!=p_len)
				{
					if(count > max)
						max = count;
					count = 1;
					p_len = len;
				}
				if(ch!='\n')
					scanf("%c",&ch);
			}
		}
		if(count > max)
			max = count;
		printf("%d\n",max);
	}
	return 0;
}
