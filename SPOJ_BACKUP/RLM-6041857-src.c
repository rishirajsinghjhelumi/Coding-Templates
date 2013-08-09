#include<stdio.h>
int main()
{
	char str[10000],operator,str1[10000];
	while(scanf("%s %c %s",str,&operator,str1)!=EOF)
	{
		int i,j,k,l = 0,len,len1 = 0,len2 = 0,factor,a[10000],b[10000],count = 0;
		long long int num1 = 0,num2 = 0,result;
		char s[10000],f[10000],sr[10000];
		for(i=0;str[i]!='\0';i=i+2)
		{
			factor = str[i] - 48;
			for(j=len1;j<factor+len1;j++)
				a[j] = str[i+1] - 48;
			len1 = len1 + factor;
		}
		for(k=0;str1[k]!='\0';k=k+2)
		{
			factor = str1[k] - 48;
			for(j=len2;j<factor+len2;j++)
				b[j] = str1[k+1] - 48;
			len2 = len2 + factor;
		}
		for(j=0;j<len1;j++)
			num1 = num1 * 10 + a[j];
		for(j=0;j<len2;j++)
			num2 = num2 * 10 + b[j];
		if(operator == '+')
			result = num1 + num2;
		else if(operator == '-')
			result = num1 - num2;
		else if(operator == '*')
			result = num1 * num2;
		else if(operator == '/')
			result = num1 / num2;
		do
		{
			s[l++] = (result % 10) + 48;
			result = result / 10;
		}
		while(result!=0);
		for(j=l-1;j>=0;j--)
			sr[l-1-j] = s[j];
		k=0;
		sr[l]='*';
		for(j=0;j<l;j++)
		{
			if(sr[j] == sr[j+1])
			{
				count++;
				if(count == 8)
				{
					f[k++] = (count + 1) + 48;
					f[k++] = sr[j];
					count = 0;
					j+=1;
				}
				continue;
			}
			else
			{
				f[k++] = (count + 1) + 48;
				f[k++] = sr[j];
				count = 0;
			}
		}
		printf("%s %c %s = ",str,operator,str1);
		for(j=0;j<k;j++)
			printf("%c",f[j]);
		printf("\n");
	}
	return 0;
}
