#include<stdio.h>
#include<string.h>
char a[11];
int mcxi_to_int(char []);
void int_to_mcxi(int n);
int main()
{
	int test_cases;
	scanf("%d",&test_cases);
	while(test_cases--)
	{
		scanf("%s",a);
		int x=mcxi_to_int(a);
		scanf("%s",a);
		int y=mcxi_to_int(a);
		int res = x + y;
		int_to_mcxi(res);
		printf("%s\n",a);
	}
	return 0;
}
int mcxi_to_int(char a[])
{
	int i,num=0,x=0;
	for(i=0;i<strlen(a);i++)
	{
		if(a[i] >=50 && a[i] <=57)
			x=a[i] - 48;
		else
		{
			if(a[i] == 'm')
			{
				if(x!=0)
				{
					num+=1000*x;
					x = 0;
				}
				else
					num+=1000;
			}
			else if(a[i] == 'c')
			{
				if(x!=0)
				{
					num+=100*x;
					x = 0;
				}
				else
					num+=100;
			}
			else if(a[i] == 'x')
			{
				if(x!=0)
				{
					num+=10*x;
					x = 0;
				}
				else
					num+=10;
			}
			else if(a[i] == 'i')
			{
				if(x!=0)
				{
					num+=x;
					x = 0;
				}
				else
					num+=1;
			}
		}
	}
	return num;
}
void int_to_mcxi(int n)
{
	int th,h,t,o,i=0;
	th = n/1000;
	n = n - th*1000;
	h = n/100;
	n = n - h*100;
	t = n / 10;
	o = n = n - t*10;
	if(th!=0)
	{
		if(th!=1)
			a[i++] = th + 48;
		a[i++] = 'm';
	}
	if(h!=0)
	{
		if(h!=1)
			a[i++] = h + 48;
		a[i++] = 'c';
	}
	if(t!=0)
	{
		if(t!=1)
			a[i++] = t + 48;
		a[i++] = 'x';
	}
	if(o!=0)
	{
		if(o!=1)
			a[i++] = o + 48;
		a[i++] = 'i';
	}
	a[i] = '\0';
}
