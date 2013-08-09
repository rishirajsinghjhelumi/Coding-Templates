#include<stdio.h>
#include<math.h>
#include<algorithm>
#define max 3248
#define root sqrt(max)+1 
#define range 10527450
int i,j,k=0;
char p[max];
int numbers[10000000],primes[max];
int main()
{
	int count = 0;
	for(i=2;i<root;i++)
		if(!p[i])
			for(j=i+i;j<max;j+=i)
				p[j]='1';
	primes[k++] = 2;
	for(i=3;i<max;i+=2)
		if(!p[i])
			primes[k++] = i;
	printf("%d\n",k);
	int n,counter=0;
	for(i=6;i<=range;i++)
	{
		int s=sqrt(i),j=0;
		int pk[40],x=0,d;
		n = i;
		while(n!=1)
		{
			while(!(n%primes[j]))
			{
				n /=primes[j];
				pk[x++] = primes[j];
			}
			if(++j==k || primes[j-1]>=s || x>2)
				break;
		}
		if(n!=1)
			pk[x++] = n;
		if((x==2)&&(pk[1]!=pk[0]))
			numbers[counter++] = i;
	}
	int test_cases;
	scanf("%d",&test_cases);
	while(test_cases--)
	{
		scanf("%d",&n);
		printf("%d\n",numbers[n-1]);
	}
	return 0;
}
