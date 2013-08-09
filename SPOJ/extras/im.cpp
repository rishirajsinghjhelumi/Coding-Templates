#include<cstdio>
#include<iostream>
#include<vector>
#include<algorithm>
#include<cmath>
using namespace std;
typedef pair<int,int> PI;
vector<long long> vx,vy,ret;
int main()
{

	long long t,k;
	double sum_1,sum_2,sum;
	int n;
	while(scanf("%lld",&t) && t!=-1)
	{
		vx.clear(),vy.clear(),ret.clear();sum_1=sum_2=sum=0;
		for(int i=0;i<t;i++) 
			scanf("%lld",&k),vx.push_back(k);
		for(int i=0;i<t;i++) 
			scanf("%lld",&k),vy.push_back(k);
		vx.push_back(vx[0]);
		vx.push_back(vx[t-1]);
		sort(vx.begin(),vx.end());
		sort(vy.begin(),vy.end());
		n=t+2;
		for(int i=0;i<n;i++) 
			ret.push_back(vx[(n+i-1)%n]-vx[(i+1)%n]);
		ret.erase(ret.begin(),ret.begin()+1);
		ret.erase(ret.end()-1,ret.end());
		sort(ret.begin(),ret.end());  
		for(int i=0;i<t;i++) 
			sum_1+=ret[i]*vy[i];
		sort(ret.rbegin(),ret.rend());
		for(int i=0;i<t;i++) 
			sum_2+=ret[i]*vy[i];
		sum=max(fabs(sum_1),fabs(sum_2))*0.5;
		printf("%.1lf\n",sum);
	}
	return 0;
}


