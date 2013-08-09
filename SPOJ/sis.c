#include<stdio.h>
long long int count = 0;
int n = 0;
int a[1000];
void counter(int len,int index,int start)
{
	if(index>=n)
		return;
	int i;
	for(i=start;i<index;i++)
		if(a[i]==a[index])
			return;
	if(len>=2)
		count++;
	for(i=index+1;i<n;i++)
		if(a[i] > a[index])
			counter(len+1,i,index);
}
int main()
{
	int x;
	while(scanf("%d",&x)!=-1)
		a[n++] = x;
	int i;
	for(i=0;i<n;i++)
		counter(1,i,0);
	printf("%lld\n",count);
	return 0;
}
