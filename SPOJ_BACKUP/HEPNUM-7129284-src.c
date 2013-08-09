#include<stdio.h>
#include<string.h>
int main()
{
	char a[1000000],b[1000000];
	while(1)
	{
		scanf("%s%s",a,b);
		if(strcmp(a,"*")==0 && strcmp(b,"*")==0)
			break;
		int l1=strlen(a),l2=strlen(b),i,j,k,x,c;
		for(i=0;i<l1;i++)
			if(a[i]!='0')
				break;
		for(j=0;j<l1;j++)
			if(b[j]!='0')
				break;
		if((l1-i)!=(l2-j))
		{
			if(l1-i>l2-j)
				printf(">");
			else
				printf("<");
		}
		else
		{
			x = l1 - i;
			c = 1;
			for(k=0;k<x;k++)
			{
				if(a[i+k]>b[j+k])
				{
					c = 0;
					printf(">");
					break;
				}
				else if(a[i+k]<b[j+k])
				{
					c = 0;
					printf("<");
					break;
				}
			}
			if(c)
				printf("=");
		}
		printf("\n");
	}
	return 0;
}
