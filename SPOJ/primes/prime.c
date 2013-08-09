#include<stdio.h>
#define max 100000000
#define root 10001
int i,j,k=1;
char p[max];
int main()
{
	for(i=2;i<root;i++)
		if(!p[i])
			for(j=i+i;j<max;j+=i)
				p[j]='1';
	for(i=3;i<max;i+=2)
		if(!p[i])
			printf("%d\n",i);
	return 0;
}
