#include<stdio.h>
#include<string.h>
int main()
{
	char a[100];
	scanf("%s",a);
	while(strcmp(a,"BYE")!=0)
	{
		int len = strlen(a),i,num[2],k=0,x[20];
		num[0] = num[1] = 0;
		for(i=0;i<len;i++)
		{
			if(a[i]  >=48 && a[i] <=57)
			{
				if(a[i] == '0' && a[i+1] == '6' && a[i+2] == '3')
					num[k] = num[k] * 10 + 0;
				else if(a[i] == '0' && a[i+1] == '1' && a[i+2] == '0')
					num[k] = num[k] * 10 + 1;
				else if(a[i] == '0' && a[i+1] == '9' && a[i+2] == '3')
					num[k] = num[k] * 10 + 2;
				else if(a[i] == '0' && a[i+1] == '7' && a[i+2] == '9')
					num[k] = num[k] * 10 + 3;
				else if(a[i] == '1' && a[i+1] == '0' && a[i+2] == '6')
					num[k] = num[k] * 10 + 4;
				else if(a[i] == '1' && a[i+1] == '0' && a[i+2] == '3')
					num[k] = num[k] * 10 + 5;
				else if(a[i] == '1' && a[i+1] == '1' && a[i+2] == '9')
					num[k] = num[k] * 10 + 6;
				else if(a[i] == '0' && a[i+1] == '1' && a[i+2] == '1')
					num[k] = num[k] * 10 + 7;
				else if(a[i] == '1' && a[i+1] == '2' && a[i+2] == '7')
					num[k] = num[k] * 10 + 8;
				else if(a[i] == '1' && a[i+1] == '0' && a[i+2] == '7')
					num[k] = num[k] * 10 + 9;
				i=i+2;
			}
			else if(a[i]=='+')
				k++;
		}
		int res = num[0] + num[1],j=0;
		while(res!=0)
		{
			x[j++] = res % 10;
			res = res / 10;
		}
		printf("%s",a);
		for(i=j-1;i>=0;i--)
		{
			if(x[i] == 0)
				printf("063");
			else if(x[i] == 1)
				printf("010");
			else if(x[i] == 2)
				printf("093");
			else if(x[i] == 3)
				printf("079");
			else if(x[i] == 4)
				printf("106");
			else if(x[i] == 5)
				printf("103");
			else if(x[i] == 6)
				printf("119");
			else if(x[i] == 7)
				printf("011");
			else if(x[i] == 8)
				printf("127");
			else if(x[i] == 9)
				printf("107");
		}
		printf("\n");
		scanf("%s",a);
	}
	return 0;
}
