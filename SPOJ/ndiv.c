#include<stdio.h>
#include<math.h>
#define max 60000
#define root sqrt(max)+1
int i,j,k=1;
char p[max];
char a[30000];
int val[30000];
int mult(int n , int len);
int main()
{
	for(i=2;i<root;i++)
		if(!p[i])
			for(j=i+i;j<max;j+=i)
				p[j]='1';
	int len=1;
	for(i=0;i<30000;i++)
		a[i]='0';
	a[0] = '2';
	for(i=3;i<max;i+=2)
		if(!p[i])
			len = mult(i,len);
	i=len-1;
	while(a[i--]=='0');
	i+=2;
	for(;i--;)
		printf("%c",a[i]);
	printf("\n");
	return 0;
}
int mult(int n , int len)
{
	int i,x;
	len += ceil(log10(n));
	for(i=0;i<len;i++)
	{
		x = val[i] + (a[i]-48)*n;
		a[i] = x%10 + 48;
		val[i+1] = x/10;
	}
	return len;
}
