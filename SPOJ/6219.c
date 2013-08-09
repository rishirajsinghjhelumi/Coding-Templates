#include<stdio.h>
#include<string.h>
int main()
{
	int test_cases;
	scanf("%d",&test_cases);
	while(test_cases--)
	{
		char a[5000],b[5000];
		int i,j,k,count = 0;
		scanf("%s%s",a,b);
		int l1 = strlen(a),l2=strlen(b),min=99999;
		if(l1 == l2)
		{
			for(i=0;i<l1;i++)
				if(a[i]!=b[i])
					count++;
			min = count;
		}
		else if(l1 < l2)
		{
			for(i=0;i<=l2-l1;i++)
			{
				count = 0;
				for(j=0;j<l1;j++)
					if(a[j]!=b[i+j])
						count++;
				if(count < min)
					min = count;
			}
			min += l2 - l1;
		}
		printf("%d\n",min);
	}
	return 0;
}
