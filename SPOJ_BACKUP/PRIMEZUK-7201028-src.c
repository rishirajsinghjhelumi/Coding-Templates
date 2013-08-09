#include<stdio.h>
#include<math.h>
#define max 1<<16
#define root sqrt(max)+1
int i,j,k=0;
char p[max];
int primes[max];
int main()
{
	for(i=2;i<root;i++)
		if(!p[i])
			for(j=i+i;j<max;j+=i)
				p[j]='1';
	primes[k++] = 2;
	for(i=3;i<max;i+=2)
		if(!p[i])
			primes[k++] = i;
	int test_cases,t=1;
	scanf("%d",&test_cases);
	while(test_cases--)
	{
		int n;
		scanf("%d",&n);
		int i=0,j=0,m=1,x,ans;
		for(i=0;i<n;i++)
		{
			scanf("%d",&x);
			m *=x;
		}
		n = m + 1;
		int s = sqrt(n);
		while(n!=1)
		{
			while(!(n%primes[j]))
			{
				n /=primes[j];
				ans = primes[j];
			}
			if(++j==k || primes[j-1]>=s)
				break;
		}
		if(n!=1)
			ans = n;
		printf("Case #%d: %d\n",t++,ans);
	}
	return 0;
}
