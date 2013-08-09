#include<stdio.h>
#include<math.h>
#define max 100
#define root sqrt(max)+1
int i,j,k=0;
char p[max+10];
int primes[100];
int factors[max+10][5];
int powers[max+10][5];
int res_factors[max+10];
int res_powers[max+10];
int res_counter;
int counter[max+10];
void gen_prime()
{
	for(i=2;i<root;i++)
		if(!p[i])
			for(j=i*i;j<=max;j+=i+i)
				p[j]='1';
	primes[k++] = 2;
	for(i=3;i<=max;i+=2)
		if(!p[i])
			primes[k++] = i;
	for(i=2;i<=max;i++)
	{
		int n=i,s=sqrt(i),x,j=0;
		while(n!=1)
		{
			x = primes[j];
			int d = 0;
			while(!(n%x))
			{
				d++;
				n /= x;
			}
			if(d)
			{
				factors[i][counter[i]] = x;
				powers[i][counter[i]++] = d;
			}
			if(++j==k || x>=s)
				break;
		}
		if(n!=1)
		{
			factors[i][counter[i]] = n;
			powers[i][counter[i]++] = 1;
		}
	}
}
void solve(int n,int a[],int op[])
{
	res_counter = 0;
	int i,j,x,k,r,p;
	x = a[0];
	for(i=0;i<counter[x];i++)
	{
		res_factors[i] = factors[x][i];
		res_powers[i] = powers[x][i];
	}
	res_counter = counter[x];
	for(i=0;i<n-1;i++)
	{
		x = a[i+1];
		for(j=0;j<counter[x];j++)
		{
			r = factors[x][j];
			p = powers[x][j];
			int done = 0;
			for(k=0;k<res_counter;k++)
				if(r == res_factors[k])
				{
					res_powers[k] = op[i] ? ((p>res_powers[k])?p:res_powers[k]) : ((p<res_powers[k])?p:res_powers[k]);
					done = 1;
					break;
				}
			if(!done)
			{
				res_factors[res_counter] = r;
				res_powers[res_counter++] = p;
			}	
		}
	}
}
void print_result(int caseno)
{
	int i,count = 0;
	int pr[max+10];
	for(i=0;i<max;i++)
		pr[i] = 0;
	for(i=0;i<res_counter;i++)
		pr[res_factors[i]] = res_powers[i];
	printf("%d. ",caseno);
	for(i=0;i<max;i++)
	{
		if(pr[i])
		{
			count++;
			printf("%d^%d%s",i,pr[i],count==res_counter?"\n":" ");
		}
	}
}
int main()
{
	gen_prime();
	int t,a[max],oper[max],m;
	scanf("%d",&t);
	for(m=1;m<=t;m++)
	{
		int n,i;
		scanf("%d",&n);
		for(i=0;i<n;i++)
		{
			scanf("%d",&a[i]);
			if(i!=n-1)
			{
				char ch;
				scanf("%*c%c",&ch);
				oper[i] = (ch=='&')?0:1;
			}
		}
		solve(n,a,oper);
		print_result(m);
	}
	return 0;
}
