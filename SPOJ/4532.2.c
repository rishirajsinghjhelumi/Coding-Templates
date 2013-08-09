#include<stdio.h>
#include<string.h>
int main()
{
	char s[1000],new[1000],c[1000];
	int len,i,j,new_len,done = 0;
	scanf("%s",s);
	len = strlen(s);
	while(done != 1 )
	{
		minimise(s,new,len);
		new_len = strlen(new);
		done = check_string(new,new_len);
		len = new_len;
		strcpy(s,new);
		printf("len==%d\n",len);
		printf("%s\nn==%s\n",s,new);
	}
	printf("%d\n",new_len);
	return 0;
}
int check_string(char new[],int new_len)
{
	char check[1000],i,j,ctr = 0,done = 0;
	if(new[0] == 'a')
		for(i=0;i<new_len;i=i+2)
		{
			if(ctr == 0)
			{
				check[i] = 'a';
				check[i+1] = 'a';
				ctr = 1;
			}
			else
			{
				check[i] = 'b';
				check[i+1] = 'b';
				ctr = 0;
			}
		}
	else
		for(i=0;i<new_len;i=i+2)
		{
			if(ctr == 0)
			{
				check[i] = 'b';
				check[i+1] = 'b';
				ctr = 1;
			}
			else
			{
				check[i] = 'a';
				check[i+1] = 'a';
				ctr = 0;
			}
		}
	printf("check==%s\n",check);
	for(i=0;i<new_len;i++)
	{
		if(new[i] == check[i])
			done = 1;
		else
		{
			done = 0;
			break;
		}
	}
	return done;
}
int minimise(char s[],char new[],int len)
{
	int i,j;
	for(i=0;i<len;i++)
	{
		if((s[i] == 'a' && s[i+2] == 'a') || (s[i] == 'b' && s[i+2] == 'b'))
		{
			if(i+4 < len)
				new[i] = s[i+4];
			else if(i-2 >= 0)
				new[i] = s[i-2];
			else
			{
				if(i+3 < len)
					new[i] = s[i+3];
				else if(i-1 >= 0)
					new[i] = s[i-1];
				else 
					new[i] = s[i];
			}
			for(j=i+3;j<len;j++)
				new[j-2] = s[j];
			break;
		}
		else
			new[i] = s[i];
	}
}
