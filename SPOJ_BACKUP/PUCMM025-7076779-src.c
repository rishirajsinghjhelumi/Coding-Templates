#include<stdio.h>
#include<string.h>
int seven_check(char a[],int len);
int main()
{
	char a[300];
	while(scanf("%s",a)!=EOF)
	{
		int count = 0,c[10]={0},len = strlen(a),sum = 0,div2=0,div3=0,i;
		for(i=0;i<len;i++)
		{
			sum += a[i] - 48;
			c[a[i]-48]++;
		}
		// COUNT 1
		count+=c[1];
		// COUNT 2
		if((a[len-1]-48)%2==0)
		{
			count += c[2];
			div2 = 1;
		}
		// COUNT 3
		if(sum%3==0)
		{
			count += c[3];
			div3 = 1;
		}
		// COUNT 4
		if(len>=2)
		{
			if(((10*(a[len-2]-48))+a[len-1]-48)%4==0)
				count += c[4];
		}
		else
		{
			if((a[len-1]-48)%4==0)
				count += c[4];
		}
		// COUNT 5
		if( a[len-1]=='0' || a[len-1] == '5')
			count += c[5];
		// COUNT 6
		if(div2==1 && div3==1)
			count += c[6];
		// COUNT 8
		if(len>=3)
		{
			if( (100*(a[len-3]-48) + 10*(a[len-2]-48) + a[len-1]-48)%8==0 )
				count += c[8];
		}
		else if(len==2)
		{
			if( (10*(a[len-2]-48) + a[len-1]-48)%8==0)
				count += c[8];
		}
		else
		{
			if(a[len-1] == '8')
				count +=c[8];
		}
		// COUNT 9
		if(sum%9==0)
			count += c[9];
		// COUNT 7
		if(seven_check(a,len)==1)
			count += c[7];
		printf("%d\n",count);
	}
	return 0;
}
int seven_check(char a[],int len)
{
	int i,j,sum=0;
	for(i=0;i<len;i++)
		sum = (sum*10 + a[i] -48)%7;
	return (sum==0)?1:0;
}
