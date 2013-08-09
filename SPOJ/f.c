#include<stdio.h>
#include<ctype.h>
int main()
{
int c=0,a=0;
char ch;
while(ch!='\n')
{
scanf("%c",&ch);
if(isupper(ch))
{
if(c==0)
a+=3;
else if(c%3!=0)
a+=3-c%3;
c=0;
}
else
c++;
}
printf("%d\n",a-3);
return 0;
}
