#include<stdio.h>
#include<string.h>
int sub_group_count(int [] , int , int , int , int ,int);
static int count = 0;
int main()
{
	char str[10000],check[] = "bye";
	int test = 1,test_counter = 0;
	scanf("%s",str);
	test = strcmp(check,str);
	while( test != 0 )
	{
		test_counter++;
		int i,j,k,len,sum = 0,ans= 0;
		len = strlen(str);
		int a[len];
		for(i=0;i<len;i++)
		{
			a[i] = str[i] - 48;
			sum += a[i];
		}
		ans = sub_group_count(a,len,len-1,sum,0,0);
		printf("%d. %d\n",test_counter,ans);
		count = 0;
		scanf("%s",str);
		test = strcmp(check,str);
	}
}
int sub_group_count(int a[] , int len , int loc , int sum  , int x, int y)
{
	int i,s=0;
	if( x != len)
	{
		for(i=len-1;i>=x;i--)
		{
			s = s + a[i];
			if( i != x&& sum - s <= s  && sum - s >= y)
			{
				count++;
				sub_group_count(a,len,loc-1,s,i,sum-s);
			}
			if( i==0 )
				count++;
		}
	}
	return (count);
}
