#include<stdio.h>
#include<string.h>
int main()
{
	char a[20][20]={"zero","one","two","three","four","five","six","seven","eight","nine","ten",
		"eleven","twelve","thirteen","fourteen","fifteen","sixteen","seventeen","eighteen","nineteen"},
	     b[8][20]={"twenty","thirty","forty","fifty","sixty","seventy","eighty","ninety"};
	int t;
	scanf("%d%*c",&t);
	while(t--)
	{
		char ch,w[100][50]={'\0'};
		int i,j=0,k=0,n=0,p=0;
		scanf("%c",&ch);
		while(ch!='\n')
		{
			if(ch==' ')
			{
				w[j][k] = '\0';
				k=0;
				j++;
			}
			else
				w[j][k++] = ch;
			scanf("%c",&ch);
		}
		for(i=0;i<=j;i++)
		{
			if(strcmp(w[i],"thousand")==0)
			{
				n+=p*1000;
				p=0;
			}
			else if(strcmp(w[i],"hundred")==0)
			{
				n+=p*100;
				p=0;
			}
			else
			{
				for(k=0;k<20;k++)
					if(strcmp(w[i],a[k])==0)
					{
						p+=k;
						break;
					}
				for(k=0;k<8;k++)
					if(strcmp(w[i],b[k])==0)
					{
						p+=10*(k+2);
						break;
					}
			}
		}
		printf("%d\n",n+p);
	}
	return 0;
}
