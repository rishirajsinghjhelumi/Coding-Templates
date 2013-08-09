#include<stdio.h>
#include<math.h>
int main()
{
	int test_cases;
	scanf("%d",&test_cases);
	while(test_cases--)
	{
		long long int x,y,z,done=0,c,b,ans,root,d,a1,a2,ans1,ans2;
		scanf("%lld%lld%lld",&x,&y,&z);
		d = x*x+y*y+2*y*z;
		root = sqrtl(d);
		a1 = x + root;
		a2 = x - root;
		c=y+2*z;
		ans1 = (a1*z)/c;
		ans2 = (a2*z)/c;
		if(root*root == d && (a1*z)%c==0)
			printf("%lld\n",ans1);
		else if(root*root == d && (a2*z)%c==0)
			printf("%lld\n",ans2);
		else
			printf("Not this time.\n");
	}
	return 0;
}
