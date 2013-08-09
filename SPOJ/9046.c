#include<stdio.h>
int main()
{
	int a[11][2] = {{0,0},{1,6},{2,11},{3,17},{4,22},{5,28},{6,33},{7,39},{8,44},{9,50},{10,55}};
	int b[11][2] = {{12,0},{13,6},{14,11},{15,17},{16,22},{17,28},{18,33},{19,39},{20,44},{21,50},{22,55}};
	int test_cases;
	scanf("%d",&test_cases);
	while(test_cases--)
	{
		int sh,sm,eh,em,i,j,x,y,count=0;
		scanf("%d%*c%d%d%*c%d",&sh,&sm,&eh,&em);
		for(i=sh;i<=eh;i++)
		{
			x=(i==sh)?sm+1:0;
			y=(i==eh)?em:59;
			if(i==11 || i==23)
				continue;
			else if(x==0 && y==60 && i!=11 && i!=23)
				count++;
			else
			{
				if(i<12)
				{
					if(x<=a[i][1] && y>=a[i][1])
						count++;
				}
				else
				{
					if(x<=b[i-12][1] && y>=b[i-12][1])
						count++;
				}
			}
		}
		printf("%d\n",count);
	}
	return 0;
}
