#include<stdio.h>
int main()
{
	char ch;
	int count=0;
	scanf("%c",&ch);
	while(ch!='\n')
	{
		if(ch=='y'||ch=='a'||ch=='e'||ch=='i'||ch=='o'||ch=='u'||ch=='U'||ch=='O'||ch=='I'||ch=='A'||ch=='E'||ch=='Y')
			count++;
		scanf("%c",&ch);
	}
	printf("%d\n",count);
	return 0;
}
