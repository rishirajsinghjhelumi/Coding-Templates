#include<stdio.h>
#include<string.h>
int main()
{
	int i,test_cases;
	scanf("%d",&test_cases);
	for(i=0;i<test_cases;i++)
	{
		int n,j,k,l,count=0,x=0,y,m,p,len,match=0,h,g,c1=0,c2=0,c3=1,temp,check=0;
		scanf("%d",&n);
		char a[n][100000],c[10000],d[10000],f[10000];
		int b[n];
		for(j=0;j<n;j++)
		{
			scanf("%s",a[j]);
			b[j] = strlen(a[j]);
		}
		for(k=1;k<n;k++)
		{
			temp = b[k];
			strcpy(f,a[k]);
			j = k-1;
			while(temp < b[j]&& j>=1)
			{
				b[j+1] = b[j];
				strcpy(a[j+1],a[j]);
				j--;
			}
			b[j+1] = temp;
			strcpy(a[j+1],f);
		}
		len=b[0];
		for(y=1;y<n;y++)
		{
			c3=1;
			for(j=b[y];j>=1;j--)
			{
				if(j > len)
					continue;
				for(k=0;k<b[y];k++)
				{
					if(k+j>b[y])
						break;
					for(m=0;m<len-x+1;m++)
					{
						x=0;
						for(p=k;p<k+j;p++)
						{
							if(a[0][p] == a[y][p])
							{
								c[x++] = a[y][p];
								check=1;
							}
							else
							{
								check=0;
								break;
							}
						}
						if(check==1)
						{
							c3=0;
							strcpy(a[0],c);
							len=x;
							c1=1;
							break;
						}
					}
					if(c1==1)
						break;
				}
				if(c1==1)
				{
					c1=0;
					break;
				}
			}
			if(c3==1)
			{
				len=0;
				break;
			}
		}
		printf("%d\n",len);
	}
	return 0;
}
