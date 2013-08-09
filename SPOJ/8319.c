#include<stdio.h>
int main()
{
	int count = 0,x,i;
	scanf("%d",&x);
	count +=x;
	for(i=0;i<9;i++)
	{
		scanf("%d",&x);
		if(count+x<100)
			count +=x;
		else if(count+x>100)
		{
			if(abs(100-count)>=abs(100-count-x))
				count += x;
			break;
		}
		else if(count+x==100)
		{
			count = 100;
			break;
		}
	}
	printf("%d\n",count);
	return 0;
}
