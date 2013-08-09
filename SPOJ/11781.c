#include <math.h>
#include <stdio.h>
#include <string.h>
void sub(char *a ,unsigned n,int);
void multd(char * s, size_t len, unsigned n)
{
	unsigned values[len];
	memset(values, 0, sizeof(unsigned) * len);
	for(size_t i = len; i--; )
	{
		unsigned x = values[i] + (s[i] - '0') * n;
		s[i] = '0' + x % 10;
		if(i) values[i - 1] += x / 10;
	}
	puts(s);
}
void factd(char * s, size_t len, unsigned n)
{
	memset(s, '0', len - 1);
	s[len - 1] = '1';
	puts(s);
	for(; n > 1; --n) 
		multd(s, len, n);
}
int main(void)
{
	unsigned n,x;
	scanf("%u",&n);
	n+=3;
	size_t len = ceill(log10l(tgammal(n + 1)));
	char a[len + 1];
	a[len] = 0;
	factd(a, len, n);
	x = n*n-1;
	int i=0,l=strlen(a);
	sub(a,x,l-1);
	while(a[i++]=='0');
	i--;
	for(;i<l;i++)
		printf("%c",a[i]);
	printf("\n");
}
void sub(char *a ,unsigned n,int l)
{
	char ch;
	while(n)
	{
		ch = n%10+48;
		n /=10;
		if(a[l] >= ch)
			a[l] = a[l] - ch + 48;
		else
		{
			a[l] = ((a[l] - 48) + 10) - (ch- 48) + 48;
			int x = l-1;
			while(a[x]=='0')
				a[x--] = '9';
			a[x] = a[x] - 1;
		}
		l--;
	}
}
