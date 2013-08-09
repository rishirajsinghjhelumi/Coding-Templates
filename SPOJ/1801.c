#include<stdio.h>
int main()
{
	long double mw,mi,tw,ti,rw,rt,ri,em=335,ci=2.09,cw=4.19,amt;
	while(scanf("%Lf%Lf%Lf%Lf",&mw,&mi,&tw,&ti))
	{
		if(mi==0 && mw==0 && ti==0 && tw==0)
			break;
		ti = -1*ti;
		if(mw*tw*cw > mi*ti*ci)
		{
			if(mw*tw*cw > mi*ti*ci + em*mi)
			{
				ri = 0;
				rw = mw + mi;
				rt = (mw*cw*tw - mi*ti*ci - mi*em)/((mw+mi)*cw);
			}
			else
			{
				rt = 0;
				ri = mi - (mw*tw*cw - mi*ci*ti)/em;
				rw = mw + (mw*tw*cw - mi*ci*ti)/em;
			}
		}
		else
		{
			if(mi*ti*ci > mw*tw*cw+em*mw)
			{
				ri = mw+mi;
				rw = 0;
				rt = -1*(mi*ti*ci - mw*tw*cw - em*mw)/((mw+mi)*ci);
			}
			else
			{
				rt = 0;
				ri = mi + (mi*ti*ci - mw*cw*tw)/em;
				rw = mw - (mi*ti*ci - mw*cw*tw)/em;
			}
		}
		printf("%.1Lf g of ice and %.1Lf g of water at %.1Lf C\n",ri,rw,rt);
	}
	return 0;
}
