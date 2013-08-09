#include<stdio.h>
int calc_value(float arr[] , char ch1[] , int l2);
int main()
{
	int i,test_cases;
	scanf("%d",&test_cases);
	for(i=0;i<test_cases;i++)
	{
		int j,b=0,k=0,l=0,ans,res,l1,l2,x=0,l3,y,t1=0,t2=0,count=0;
		char ch1[10000],op,ch='$',d[10000];
		float arr[10000];
		for(j=0;j<10000;j++)
		{
			arr[j] = 0;
			d[j] = '$';
			ch1[j] = '$';
		}
		for(j=0;ch!='\n';j++)
		{
			if(j % 2 == 0)
				scanf("%f",&arr[k++]);
			else
				scanf("%c",&ch1[l++]);
			scanf("%c",&ch);
		}
		l1 = k,l2 = l;
		for(j=0;j<l2;j++)
		{
			if(ch1[j] == '+' || ch1[j] == '-')
			{
				if(d[b-1]=='I'|| d[b-1]==')')
				{
					d[b++] = ch1[j];
					d[b++] = 'I';
				}
				else
				{
					d[b++] = 'I';
					d[b++] = ch1[j];
					d[b++] = 'I';
				}
			}
			else if(ch1[j] == '*' || ch1[j] == '/')
			{
				if(d[b-1] == ')')
				{
					for(l=b;l>=0;l--)
					{
						if(d[l] == '(')
							break;
						d[l] = d[l-1];
					}
					d[l] = '(';
					b++;
					d[b++] = ch1[j];
					d[b++] = 'I';
					d[b++] = ')';
				}
				else
				{
					if(b-1>=0)
						d[b-1] = '(';
					else
						d[b++] = '(';
					d[b++] = 'I';
					d[b++] = ch1[j];
					d[b++] = 'I';
					d[b++] = ')';
				}
			}
		}
		l3 = b;
		int i1=0,i2=0;
		for(j=0;j<l2;j++)
			if(ch1[j] == '+' || ch1[j] == '-')
				count++;
		for(l=0;l<count;l++)
			printf("( ");
		i1=count;
		for(j=0;j<l3;j++)
		{
			if(d[j]=='(')
				i1++;
			else if(d[j] == ')')
				i2++;
			if(d[j]=='+' || d[j] == '-')
			{
				if(t1!=0)
				{
					printf(") ");
					i2++;
				}
				else
					t1++;
			}
			if(d[j]=='I')
				printf("%.0f ",arr[x++]);
			else
				printf("%c ",d[j]);
		}
		if(i1!=i2)
			printf(")\n");
		else
			printf("\n");
		printf("%d\n",calc_value(arr,ch1,l2));
	}
	return 0;
}
int calc_value(float arr[] , char ch1[] , int l2)
{
	int j=0,k;
	while(j!=l2)
	{
		if(ch1[j] == '*')
			arr[j] = arr[j] * arr[j+1];
		else if(ch1[j] == '/')
			arr[j] = arr[j] / arr[j+1];
		else
		{
			j++;
			continue;
		}
		for(k=j+1;k<l2;k++)
			arr[k] = arr[k+1];
		for(k=j;k<l2-1;k++)
			ch1[k] = ch1[k+1];
		l2 = l2 - 1;
		j = 0;
	}
	float sum = arr[0];
	for(j=0;j<l2;j++)
	{
		if(ch1[j] == '+')
			sum = sum + arr[j+1];
		else if(ch1[j] == '-')
			sum = sum - arr[j+1];
	}
	return sum;
}
