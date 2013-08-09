#include<stdio.h>
#include<stdlib.h>
int main()
{
	system("wget --no-proxy https://www.spoj.pl/content/skydbms:monster --no-check-certificate -O r.txt");
	FILE *fp=fopen("r.txt","r");
	char ch;
	while(fscanf(fp,"%c",&ch)!=EOF)
		printf("%c",ch);
	return 0;
}
