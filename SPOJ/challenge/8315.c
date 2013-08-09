#include<stdio.h>
#include<string.h>
int main()
{
	char a[21][20]={"zero","one","two","three","four","five","six","seven","eight","nine","ten",
		"eleven","twelve","thirteen","fourteen","fifteen","sixteen","seventeen","eighteen","nineteen","twenty"},
	     b[8][20]={"twenty","thirty","forty","fifty","sixty","seventy","eighty","ninety"};
	int t;
	scanf("%d",&t);
	while(t--)
	{
		int n,th,h,te,u,te2,i=0,j,x,s;
		char w[80][20];
		scanf("%d",&n);
		th=n/1000;
		n=n-1000*th;
		h=n/100;
		x=n=n-100*h;
		te=n/10;
		u=n-te*10;
		if(th!=0)
		{
			if(th<=20)
				strcpy(w[i++],a[th]);
			else
			{
				te2=th/10;
				strcpy(w[i++],b[te2-2]);
				s=th-te2*10;
				if(th!=0)
					strcpy(w[i++],a[s]);
			}
			strcpy(w[i++],"thousand");
		}
		if(h!=0)
		{
			strcpy(w[i++],a[h]);
			strcpy(w[i++],"hundred");
		}
		if(x<=20 && te!=0)
			strcpy(w[i++],a[x]);
		else
		{
			if(te!=0)
			{
				strcpy(w[i++],b[te-2]);
			}
			if(u!=0||(th==0&&te==0&&h==0&&u==0))
				strcpy(w[i++],a[u]);
		}
		for(j=0;j<i-1;j++)
			printf("%s ",w[j]);
		printf("%s\n",w[i-1]);
	}
	return 0;
}
