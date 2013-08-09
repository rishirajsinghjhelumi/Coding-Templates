#include<stdio.h>
#include<math.h>	
#define max 100000
typedef long long int ull;
ull primes[66]={2, 3, 5, 7, 11, 13, 17, 19, 23, 29, 31, 37, 41, 43, 47, 53, 59, 61, 67, 71, 73, 79, 83, 89, 97, 101, 103, 107, 109, 113, 127, 131, 137, 139, 149, 151, 157, 163, 167, 173, 179, 181, 191, 193, 197, 199, 211, 223, 227, 229, 233, 239, 241, 251, 257, 263, 269, 271, 277, 281, 283, 293, 307, 311, 313, 317};
ull num[665][24000];
ull ind[665];
int main()
{
	ull i,j,k=66;
	num[0][ind[0]++]=1;
	ull m=0;
	for(i=2;i<=max;i++)
	{
		ull s=sqrt(i),d,n=i,j=0,x,ans=1;
		while(n!=1)
		{
			d=0;
			x = primes[j];
			while(!(n%x))
			{
				d++;
				n/=x;
			}
			if(d)
				ans = ans * ((d<<1)+1);
			if(++j==k || x>=s)
				break;
		}
		if(n!=1)
			ans *=3;
		ans = (ans-1)>>1;
		num[ans][ind[ans]++] = i*i;
	}
	ull t,K,A,B,ans;
	scanf("%lld",&t);
	while(t--)
	{
		scanf("%lld%lld%lld",&K,&A,&B);
		if(K>1323)
			printf("0\n");
		else
		{
			K = (K-1)>>1;
			if(ind[K]==0)
			{
				printf("0\n");
				continue;
			}
			ull f1=0,f2=0,mid,c1,c2,low=0,high=ind[K];
			while(low <= high)
			{   
				mid = (low + high) / 2;
				if(num[K][mid] == A)  
					f1 = 1;
				if(num[K][mid] > A)
					high = mid - 1;  
				else 
					low = mid + 1;
			}   
			c1 = high + 1;
			low = 0;  
			high = ind[K];
			while(low <= high)
			{   
				mid = (low + high) / 2;
				if(num[K][mid] == B)  
					f2 = 1;
				if(num[K][mid] > B)
					high = mid - 1;
				else 
					low = mid + 1;
			}   
			c2 = high + 1;
			printf("%d\n",f1?abs(c2-c1)+1:abs(c2-c1));
		}
	}
	return 0;
}
