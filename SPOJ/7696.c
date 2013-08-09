#include<stdio.h>
#include<string.h>
#define max 50030
char res[max];
char v[5] = {'a','e','i','o','u'};
char c[21] = {'b','c','d','f','g','h','j','k','l','m','n','p','q','r','s','t','v','w','x','y','z'};
int main()
{
	int test_cases;
	scanf("%d%*c",&test_cases);
	while(test_cases--)
	{
		char ch;
		int k=0;
		int alpha[26]={0};
		while(scanf("%c",&ch) && ch!='\n')
		{
			int check = 1,x,i;
			for(i=0;i<5;i++)
				if(ch==v[i])
				{
					check = 0;
					x = i;
					break;
				}
			if(check)
				for(i=0;i<21;i++)
					if(ch==c[i])
					{
						x = i;
						break;
					}
			res[k++] = !check?c[(alpha[ch-97]*5+x)%21]:v[(alpha[ch-97]*21+x)%5];
			alpha[ch-97]++;
		}
		res[k]='\0';
		printf("%s\n",res);
	}
	return 0;
}
