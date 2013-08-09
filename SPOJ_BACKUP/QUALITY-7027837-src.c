#include<stdio.h>
int main()
{
	int t1,t2,t3,a1,a2,a3,i=1;
	while(scanf("%d%d%d%d%d%d",&t1,&t2,&t3,&a1,&a2,&a3)!=EOF)
	{
		int p_solved=0;
		long long int t_time=0;
		if(t1!=0)
		{
			p_solved++;
			t_time += t1 + (a1-1)*1200;
		}
		if(t2!=0)
		{
			p_solved++;
			t_time += t2 + (a2-1)*1200;
		}
		if(t3!=0)
		{
			p_solved++;
			t_time += t3 + (a3-1)*1200;
		}
		printf("team %d: %d, %lld\n",i++,p_solved,t_time);
	}
	return 0;
}
