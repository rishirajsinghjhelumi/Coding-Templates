#include<stdio.h>
int main()
{
	while(1)
	{
		int begin,bet,end;
		scanf("%d%d%d",&begin,&bet,&end);
		if(begin==0 && bet==0 && end==0)
			break;
		int diff = end - begin,count = 0;
		if(diff < 0)
			diff = -1*diff;
		if(diff!=0)
		{
			count += diff/(3*bet);
			diff = diff%(bet*3);
		}
		if(diff!=0)
		{
			count += diff/(2*bet);
			diff = diff%(bet*2);
		}
		if(diff!=0)
		{
			count += diff/(bet);
			diff = diff%(bet);
		}
		if(diff!=0)
			printf("No accounting tablet\n");
		else
			printf("%d\n",count);
	}
	return 0;
}
