#include<stdio.h>
#include<math.h>
#define max 10000000
#define root (int)sqrt(max)
int a[max+10];
int ans[max+10];
int main()
{
	int i,j,x=0;
	for(i=2;i<=root;i++)
	{
		a[i*i] += i;
		for(j=i*i+i;j<=max;j+=i)
			a[j] = a[j] + i + j/i;
	}
	a[1] = 1;
	if(a[1]<=max && !ans[a[1]])
		ans[a[1]] = i;
	for(i=2;i<=max;i++)
	{
		a[i] = a[i] + 1 + i;
		if(a[i]<=max && !ans[a[i]])
			ans[a[i]] = i;
	}
	int t,n;
	scanf("%d",&t);
	while(t--)
	{
		scanf("%d",&n);
		printf("%d\n",ans[n]?ans[n]:-1);
	}
	return 0;
}
