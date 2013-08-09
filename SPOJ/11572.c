#include<stdio.h>
#include<string.h>
int main()
{
	char a[100],b[100];
	int t=1;
	while(scanf("%s%s",a,b)!=EOF)
	{
		if(strcmp(a,"A")==0)
			printf("Case %d: UNIQUE\n",t);
		else if(strcmp(a,"B")==0)
			printf("Case %d: UNIQUE\n",t);
		else if(strcmp(a,"C")==0)
			printf("Case %d: UNIQUE\n",t);
		else if(strcmp(a,"D")==0)
			printf("Case %d: UNIQUE\n",t);
		else if(strcmp(a,"E")==0)
			printf("Case %d: UNIQUE\n",t);
		else if(strcmp(a,"F")==0)
			printf("Case %d: UNIQUE\n",t);
		else if(strcmp(a,"G")==0)
			printf("Case %d: UNIQUE\n",t);
		else if(strcmp(a,"A#")==0)
			printf("Case %d: %s %s\n",t,"Bb",b);
		else if(strcmp(a,"Bb")==0)
			printf("Case %d: %s %s\n",t,"A#",b);
		else if(strcmp(a,"C#")==0)
			printf("Case %d: %s %s\n",t,"Db",b);
		else if(strcmp(a,"Db")==0)
			printf("Case %d: %s %s\n",t,"C#",b);
		else if(strcmp(a,"D#")==0)
			printf("Case %d: %s %s\n",t,"Eb",b);
		else if(strcmp(a,"Eb")==0)
			printf("Case %d: %s %s\n",t,"D#",b);
		else if(strcmp(a,"F#")==0)
			printf("Case %d: %s %s\n",t,"Gb",b);
		else if(strcmp(a,"Gb")==0)
			printf("Case %d: %s %s\n",t,"F#",b);
		else if(strcmp(a,"G#")==0)
			printf("Case %d: %s %s\n",t,"Ab",b);
		else if(strcmp(a,"Ab")==0)
			printf("Case %d: %s %s\n",t,"G#",b);
		t++;
	}
	return 0;
}
