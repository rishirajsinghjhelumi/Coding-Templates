#include<stdio.h>
#include<math.h>
#define max 5263750
#define root sqrt(max)+1 
#define range 10527451
int i,j,k=0;
char p[max];
long long int primes[365563];
char numb[range]={0};
int numbers[2000000];
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
	long long int num;
	for(i=0;i<k;i++)
	{
		for(j=i+1;j<k;j++)
		{
			num = primes[i]*primes[j];
			if(num<range)
				numb[num]='1';
			else
				break;
		}
	}
	int counter = 0;
	for(i=0;i<range;i++)
		if(numb[i])
			numbers[counter++] = i;
	int test_cases,n;
	scanf("%d",&test_cases);
	while(test_cases--)
	{
		scanf("%d",&n);
		printf("%d\n",numbers[n-1]);
	}
	return 0;
}
