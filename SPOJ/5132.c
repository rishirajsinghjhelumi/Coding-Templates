#include<stdio.h>
#include<string.h>
int main()
{
	char a[10000],b[10000];
	scanf("%s",a);
	while(strcmp(a,".")!=0)
	{
		int len=strlen(a),i,j,n;
		scanf("%d",&n);
		strcpy(b,a);
		for(i=0;i<n;i++)
			strcat(a,b);
		for(i=0;i<len;i++)
		{
			for(j=i;j<n*len;j++)
				printf("%c",a[j]);
			for(j=0;j<i;j++)
				printf("%c",a[j]);
			printf("\n");
		}
		scanf("%s",a);
	}
	return 0;
}
