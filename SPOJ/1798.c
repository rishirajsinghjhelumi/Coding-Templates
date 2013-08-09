#include<stdio.h>
#include<math.h>
#define max 50000
#define root sqrt(max)+1
int i,j,k=1,s=0;
char p[max];
int numbers[10000];
int main()
{
	for(i=2;i<max;i++)
		if(!p[i])
		{
			numbers[k++] = i;
			for(j=i+i;j<max;j+=i+s)
				p[j]='1';
		}
	for(i=3;i<max;i+=2)
		if(!p[i])
	while(1)
	{
		scanf("%d",&i);
		if(i==0)
			break;
		printf("%d\n",numbers[i]);
	}
	return 0;
}
