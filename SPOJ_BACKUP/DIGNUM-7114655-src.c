#include<stdio.h>
#include<string.h>
int main()
{
	char a[100000],b[100000],c[100000],ch;
	int number[10000];
	while(scanf("%c",&ch)!=EOF)
	{
		int i,j=0,k,x,y,z,l=0;
		while(ch!='\n')
		{
			a[l++] = ch;
			scanf("%c",&ch);
		}
		a[l] = '\0';
		for(i=0;i<l;i++)
			scanf("%c",&b[i]);
		b[i] = '\0';
		scanf("%*c");
		for(i=0;i<l;i++)
			scanf("%c",&c[i]);
		c[i] = '\0';
		scanf("%*c");
		for(i=0;i<l;i+=3)
		{
			x = i;
			y = i+1;
			z = i+2;
			if(a[x]==' '&&a[y]==' '&&a[z]==' '&&b[x]==' '&&b[y]==' '&&b[z]=='|'&&c[x]==' '&&c[y]==' '&&c[z]=='|')
				number[j++] = 1;
			else if(a[x]==' '&&a[y]=='_'&&a[z]==' '&&b[x]==' '&&b[y]=='_'&&b[z]=='|'&&c[x]=='|'&&c[y]=='_'&&c[z]==' ')
				number[j++] = 2;
			else if(a[x]==' '&&a[y]=='_'&&a[z]==' '&&b[x]==' '&&b[y]=='_'&&b[z]=='|'&&c[x]==' '&&c[y]=='_'&&c[z]=='|')
				number[j++] = 3;
			else if(a[x]==' '&&a[y]==' '&&a[z]==' '&&b[x]=='|'&&b[y]=='_'&&b[z]=='|'&&c[x]==' '&&c[y]==' '&&c[z]=='|')
				number[j++] = 4;
			else if(a[x]==' '&&a[y]=='_'&&a[z]==' '&&b[x]=='|'&&b[y]=='_'&&b[z]==' '&&c[x]==' '&&c[y]=='_'&&c[z]=='|')
				number[j++] = 5;
			else if(a[x]==' '&&a[y]=='_'&&a[z]==' '&&b[x]=='|'&&b[y]=='_'&&b[z]==' '&&c[x]=='|'&&c[y]=='_'&&c[z]=='|')
				number[j++] = 6;
			else if(a[x]==' '&&a[y]=='_'&&a[z]==' '&&b[x]==' '&&b[y]==' '&&b[z]=='|'&&c[x]==' '&&c[y]==' '&&c[z]=='|')
				number[j++] = 7;
			else if(a[x]==' '&&a[y]=='_'&&a[z]==' '&&b[x]=='|'&&b[y]=='_'&&b[z]=='|'&&c[x]=='|'&&c[y]=='_'&&c[z]=='|')
				number[j++] = 8;
			else if(a[x]==' '&&a[y]=='_'&&a[z]==' '&&b[x]=='|'&&b[y]=='_'&&b[z]=='|'&&c[x]==' '&&c[y]==' '&&c[z]=='|')
				number[j++] = 9;
			else if(a[x]==' '&&a[y]=='_'&&a[z]==' '&&b[x]=='|'&&b[y]==' '&&b[z]=='|'&&c[x]=='|'&&c[y]=='_'&&c[z]=='|')
				number[j++] = 0;
		}
		for(i=0;i<j;i++)
			printf("%d",number[i]);
		printf("\n");
	}
	return 0;
}
