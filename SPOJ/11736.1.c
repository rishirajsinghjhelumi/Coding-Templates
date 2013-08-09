#include<stdio.h>
#include<math.h>
#define max 10010
int p[max]={0},k=0,i,j,p_k,m;
int primes[100]={2,3,5,7,11,13,17,19,23,29,31,37,41,43,47,53,59,61,67,71,73,79,83,89,97,101};
int fact[10010][20],len[10010];
int pri[1300];
int count[10010]={0};
int main()
{
	for(i=2;i<=101;i++)
		if(!p[i])
		{
			for(j=2*i;j<max;j=j+i)
				p[j]=1;
		}
	pri[k++] = 2;
	for(i=3;i<max;i+=2)
		if(!p[i])
			pri[k++]=i;
	p_k = k;
	k = 26;
	int n,x;
	for(x=2;x<=10000;x++)
	{
		n = x;
		int i=0,j=0,s=sqrt(n),l=0;
		if(p[x])
		{
			while(n!=1)
			{
				while(!(n%primes[j]))
				{
					n /= primes[j];
					//fact[x][l++] = primes[j];
					count[primes[j]]++;
				}
				if(++j==k || primes[j-1]>=s)
					break;
			}
		}
		if(n!=1)
		{
			//fact[x][l++] = n;
			count[n]++;
		}
		len[x] = l;
		int m;
		for(m=0;pri[m]<=x;m++)
		{
			if(count[pri[m]]!=0)
				printf("%d,%d ",pri[m],count[pri[m]]);
		}
		printf("\n");
	}
	/*for(x=2;x<=max;x++)
	{
		for(i=0;i<len[x];i++)
			printf("%d ",fact[x][i]);
		printf("\n");
	}
	printf("%d\n",p_k);*/
	return 0;
}
