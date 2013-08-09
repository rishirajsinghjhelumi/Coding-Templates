#include<stdio.h>
int main()
{
	char ch,a[5000];
	int t=1;
	while(1)	
	{
		scanf("%c",&ch);
		if(ch=='-')
		{
			while(ch!='\n')
				scanf("%c",&ch);
			break;
		}
		else
		{
			int i=0,j=0,count=0;
			while(ch!='\n')
			{
				if(ch == '{')
					a[j++] = '{';
				else if(ch=='}' && j==0)
				{
					a[j++] = '{';
					count++;
				}
				else if(ch=='}' && j!=0)
					j--;
				scanf("%c",&ch);
			}
			count = count + j/2;
			printf("%d. %d\n",t++,count);
		}
	}	
	return 0;
}
