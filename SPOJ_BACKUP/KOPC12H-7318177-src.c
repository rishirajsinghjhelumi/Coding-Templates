#include<stdio.h>
#define max 100000
#define max2 1000
int a[max+10];
int h[max2+10][2];
int h0[max2+10][2];
int h1[max2+10][2];
int main()
{
	int i,count=0,j,count2=0,l0=0,l1=0;
	for(i=0;i<max2;i++)
	{
		int x=i,c;
		while(x)
		{
			c=x%10;
			h[i][c%2] += c;
			x/=10;
		}
		if(h[i][0]>h[i][1])
		{
			count2++;
			h0[l0][0] = h[i][0];
			h0[l0++][1] = h[i][1];
		}
		else
		{
			h1[l1][0] = h[i][0];
			h1[l1++][1] = h[i][1];
		}
	}
	for(i=0;i<=max;i++)
	{
		int x=i,s[2]={0},c;
		while(x)
		{
			c = x%10;
			s[c%2]+=c;
			x/=10;
		}
		if(s[0]==s[1])
			count += count2;
		else if(s[0]>s[1])
		{
			for(j=0;j<l1;j++)
				if(h1[j][0] + s[0] > h1[j][1] + s[1])
					count++;
			count += count2;
		}
		else
		{
			for(j=0;j<l0;j++)
				if(h0[j][0] + s[0] > h0[j][1] + s[1])
					count++;
		}
		a[i] = count;
	}
	int t,A,B;
	scanf("%d",&t);
	while(t--)
	{
		scanf("%d%d",&A,&B);
		A--;
		int x1=A%max2,x2=B%max2;
		int c1 = A>=max2?a[A/max2-1]:0;
		int c2 = B>=max2?a[B/max2-1]:0;
		int x=A/max2,s1[2]={0},c;
		while(x)
		{
			c = x%10;
			s1[c%2]+=c;
			x/=10;
		}
		int s2[2]={0};
		x=B/max2;
		while(x)
		{
			c = x%10;
			s2[c%2]+=c;
			x/=10;
		}
		for(j=0;j<=x1;j++)
			if(h[j][0]+s1[0]>h[j][1]+s1[1])
				c1++;
		for(j=0;j<=x2;j++)
			if(h[j][0]+s2[0]>h[j][1]+s2[1])
				c2++;
		printf("%d\n",c2-c1);
	}
	return 0;
}
