#include<stdio.h>
#define max 100000000
int i,j,k=1;
char p[max];
int main()
{
	for(i=2;i<10001;i++)
		if(!p[i])
			for(j=i+i;j<max;j+=i)
				p[j]='1';
	for(i=2;i<max;i++)
		if(!p[i])
			printf("%d\n",i);
	return 0;
}
