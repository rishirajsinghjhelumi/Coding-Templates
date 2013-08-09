#include <stdio.h>  
#include <algorithm>  
using namespace std;  
long long a[100005];  
int main()  
{  
	long long ans,k,num,i,j,n,m,s;  
	while(scanf("%lld%lld",&m,&n)!=EOF)  
	{  
		s=0;  
		for (i=0;i<n;i++)  
		{  
			scanf("%lld",&a[i]);  
			s+=a[i];  
		}  
		num=s-m;  
		sort(a,a+n);  
		ans=0;  
		for (i=0;i<n;i++)  
		{  
			k=num/(n-i);  
			if (a[i]>=k)  
			{  
				ans+=k*k;  
				num-=k;            
			}      
			else  
			{  
				ans+=a[i]*a[i];  
				num-=a[i];       
			}  
		}  
		printf("%lld\n",ans);  
	}  
	return 0;  
} 
