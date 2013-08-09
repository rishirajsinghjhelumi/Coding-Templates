#include<stdio.h>
#include<string.h>
int main()
{
	char a[15200][12],b[15200][12],temp[12];
	int s=0,count[15200][26]={0},i,j,k,l=0,y;
	while(scanf("%s",a[s])!=EOF)
	{
		i=0;
		while(a[s][i]!='\0')
			count[s][a[s][i++]-97]++;
		s++;
	}
	for(i=0;i<s;i++)
	{
		for(j=0;j<s;j++)
		{
			if(i!=j)
			{
				y=1;
				for(k=0;k<26;k++)
					if(count[i][k] > count[j][k])
					{
						y=0;
						break;
					}
			}
			if(y==1)
				break;
		}
		if(y==0)
			strcpy(b[l++],a[i]);
	}
	for(i=0;i<l-1;i++)
	{
		for(j=i+1;j<l;j++)
		{
			k=0;
			while(1)
			{	
				if(b[j][k]=='\0' || b[i][k]=='\0')
					break;
				if( b[j][k] < b[i][k] )
				{
					strcpy(temp,b[i]);
					strcpy(b[i],b[j]);
					strcpy(b[j],temp);
					break;
				}
				else if(b[j][k] > b[i][k])
					break;
				k++;
			}
		}	
	}
	for(i=0;i<l;i++)
		printf("%s\n",b[i]);
	return 0;
}
