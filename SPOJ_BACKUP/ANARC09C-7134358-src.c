#include<stdio.h>
#include<math.h>
#define max 1001
#define root sqrt(max) + 1
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
	int a,b,cases=1;
	while(scanf("%d%d",&a,&b) && (a|b))
	{
		int n,p1[100],p2[100],x1[100],x2[100],j=0,s=sqrt(a),x=0,d,l1,l2,arr[1000],y=0,t;
		int distance = 0,count=0,l;
		n = a;
		while(n!=1)
		{
			d=0;
			while(!(n%primes[j]))
			{
				n /=primes[j];
				d++;
			}
			if(d)
			{
				p1[x] = primes[j];
				x1[x++] = d;
			}
			if(++j==k || primes[j-1]>=s)
				break;
		}
		if(n!=1)
		{
			p1[x] = n;
			x1[x++] = 1;
		}
		l1 = x;
		n = b;
		s = sqrt(b);
		x = j = 0;
		count = l1;
		while(n!=1)
		{
			d=0;
			while(!(n%primes[j]))
			{
				n /=primes[j];
				d++;
			}
			if(d)
			{
				p2[x] = primes[j];
				x2[x++] = d;
				for(l=0;l<l1;l++)
					if(p2[x-1]==p1[l])
					{
						distance += abs(x2[x-1] - x1[l]);
						p2[x-1] = -1;
						p1[l] = -1;
						break;
					}
			}
			if(++j==k || primes[j-1]>=s)
				break;
		}
		if(n!=1)
		{
			p2[x] = n;
			x2[x++] = 1;
			for(l=0;l<l1;l++)
				if(p2[x-1]==p1[l])
				{
					distance += abs(x2[x-1] - x1[l]);
					p2[x-1] = -1;
					p1[l] = -1;
					break;
				}
		}
		l2 = x;
		for(i=0;i<l1;i++)
			if(p1[i]!=-1)
				distance+=x1[i];
		for(i=0;i<l2;i++)
			if(p2[i]!=-1)
			{
				count++;
				distance+=x2[i];
			}
		printf("%d. %d:%d\n",cases++,count,distance);
	}
	return 0;
}
