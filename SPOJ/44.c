#include<stdio.h>
#include<string.h>
char new[1000];
int main()
{
	char s[1000],c[1000],check[1000];
	int len,i,ctr=0,j,new_len,done = 0,t=0,new_l;
	scanf("%s",s);
	strcpy(c,s);
	len = strlen(s);
	if(len==2)
		new_len = 2;
	else
	{
		while(done != 1 )
		{
			for(i=0;i<len;i++)
			{
				if((s[i] == 'a' && s[i+2] == 'a') || (s[i] == 'b' && s[i+2] == 'b'))
				{
					if(i-2 >= 0)
						new[i] = s[i-2];
					else if(i+4 < len)
						new[i] = s[i+4];
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
			new_len = strlen(new);
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
			len = new_len;
			strcpy(s,new);
			for(j=0;j<1000;j++)
				new[j] = '\0';
		}
	}
	printf("%d\n",new_len);
	return 0;
}
