#include<stdio.h>
int main()
{
	int n,i,j,q,x,y,m1,m2;
	scanf("%d",&n);
	int a[n];
	char ch;
	for(i=0;i<n;i++)
		scanf("%d",&a[i]);
	scanf("%d",&q);
	while(q--)
	{
		scanf("%c%c",&ch,&ch);
		scanf("%d%d",&x,&y);
		if(ch=='U')
			a[x-1] = y;
		else if(ch=='Q')
		{
			if(a[x-1] < a[x])
				m1=a[x-1],m2=a[x];
			else
				m1=a[x],m2=a[x-1];
			for(j=x+1;j<y;j++)
			{
				if(a[j] > m2)
				{
					m1 = m2;
					m2 = a[j];
				}
				else if(a[j] > m1 && a[j] < m2)
					m1 = a[j];
			}
			printf("%d\n",m1+m2);
		}
	}
	return 0;
}
