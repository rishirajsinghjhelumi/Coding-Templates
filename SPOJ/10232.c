#include<stdio.h>
#include<math.h>
#define max 3200
int p[3200]={0},primes[1000],k=0,i,j;
int main()
{
	for(i=2;i<=57;i++)
		if(!p[i])
		{
			for(j=2*i;j<max;j=j+i)
				p[j]=1;
		}
	for(i=2;i<max;i++)
		if(!p[i])
			primes[k++]=i;
	int n,count=0,numbers[1500],y;
	for(y=2;y<=2664;y++)
	{
		int i=0,j=0,s=sqrt(y);
		int pk[40],x=0,d;
		n = y;
		while(n!=1)
		{
			d=0;
			while(!(n%primes[j]))
			{
				n /=primes[j];
				d=1;
			}
			if(d)
				pk[x++] = primes[j];
			if(++j==k || primes[j-1]>=s)
				break;
		}
		if(n!=1)
			pk[x++] = n;
		if(x>=3)
			numbers[count++] = y;
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
