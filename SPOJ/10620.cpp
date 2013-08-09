#include<stdio.h>
#include<iostream>
#include<set>
using namespace std;
int lis(int *a,int n)
{
	int i;
	set<int> s;
	set<int>::iterator k;
	for (i=0;i<n;i++)
	{
		if(s.insert(a[i]).second)
		{
			k = s.find(a[i]);
			k++;
			if (k!=s.end())
				s.erase(k);
		}
	}
	return s.size();
}
int main()
{
	int n,i;
	scanf("%d",&n);
	int a[n];
	for(i=0;i<n;i++)
		scanf("%d",&a[i]);
	printf("%d\n",n-lis(a,n));
	return 0;
}
