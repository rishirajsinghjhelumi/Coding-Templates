#include<stdio.h>
int main()
{
	int n;
	while(1)
	{
		scanf("%d",&n);
		if(!n)
			break;
		long double x,y,i,ansx,ansy,minx,miny,maxx,maxy;
		scanf("%Lf%Lf",&x,&y);
		minx = maxx = x;
		miny = maxy = y;
		for(i=1;i<n;i++)
		{
			scanf("%Lf%Lf",&x,&y);
			if(x > maxx)
				maxx = x;
			if(x < minx)
				minx = x;
			if(y > maxy)
				maxy = y;
			if(y < miny)
				miny = y;
		}
		ansx = (minx+maxx)/2.0;
		ansy = (miny+maxy)/2.0;
		printf("%.4Lf, %.4Lf\n",ansx,ansy);
	}
	return 0;
}
