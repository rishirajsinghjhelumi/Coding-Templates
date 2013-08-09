#include<stdio.h>
#include<string.h>
char new[10000][1000];
int main()
{
	char s[1000],c[1000];
	int len,i,j,new_len,done = 0,t=0;
	scanf("%s",s);
	len = strlen(s);
	while(done != 1 )
	{
		for(i=0;i<len;i++)
		{
			if((s[i] == 'a' && s[i+2] == 'a') || (s[i] == 'b' && s[i+2] == 'b'))
			{
				if(i+4 < len)
					new[t][i] = s[i+4];
				else if(i-2 >= 0)
					new[t][i] = s[i-2];
				else
				{
					if(i+3 < len)
						new[t][i] = s[i+3];
					else if(i-1 >= 0)
						new[t][i] = s[i-1];
					else 
						new[t][i] = s[i];
				}
				for(j=i+3;j<len;j++)
					new[t][j-2] = s[j];
				break;
			}
			else
				new[t][i] = s[i];
		}
		new_len = strlen(new[t]);
		done = check_string(new_len,t);
		len = new_len;
		strcpy(s,new[t]);
		t++;
	}
	printf("%d\n",new_len);
	return 0;
}
int check_string(int new_len,int t)
{
	char check[1000],i,j,ctr = 0,done = 0;
	if(new[t][0] == 'a')
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
	for(i=0;i<new_len;i++)
	{
		if(new[t][i] == check[i])
			done = 1;
		else
		{
			done = 0;
			break;
		}
	}
	return done;
}
