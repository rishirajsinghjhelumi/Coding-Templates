#include<stdio.h>
int done = 0;
long long int xd,yd;
int checkit(long long int xs,long long int ys,int path);
int main()
{
	int test_cases;
	scanf("%d",&test_cases);
	while(test_cases--)
	{
		long long int xs,ys;
		scanf("%lld%lld%lld%lld",&xs,&ys,&xd,&yd);
		checkit(xs,ys,0);
		printf("%s\n",(done==1)?"YES":"NO");
		done = 0;
	}
	return 0;
}
int checkit(long long int xs,long long int ys,int path)
{
	printf("%lld %lld\n",xs,ys);
	if(done==1)
		return;
	if(xs==xd && ys==yd)
	{
		done = 1;
		return;
	}
	if(xs==xd && -1*ys==yd)
	{
		done = 1;
		return;
	}
	if(ys!=xs && path!=1)
		checkit(ys,xs,1);
	if(xs + ys != xs)
		checkit(xs+ys,ys,3);
	if(2*xs != xs)
		checkit(2*xs,ys,4);
	return;
}
