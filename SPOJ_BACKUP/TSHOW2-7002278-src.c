#include<stdio.h>
int main()
{
	int test_cases;
	scanf("%d",&test_cases);
	while(test_cases--)
	{
		long long int n;
		scanf("%lld",&n);
		int x,ans;
		x=n%60;
		if(x==1)
			ans=0;
		else if(x==2)
			ans=1;
		else if(x==3)
			ans=1;
		else if(x==4)
			ans=2;
		else if(x==5)
			ans=3;
		else if(x==6)
			ans=5;
		else if(x==7)
			ans=8;
		else if(x==8)
			ans=3;
		else if(x==9)
			ans=1;
		else if(x==10)
			ans=4;
		else if(x==11)
			ans=5;
		else if(x==12)
			ans=9;
		else if(x==13)
			ans=4;
		else if(x==14)
			ans=3;
		else if(x==15)
			ans=7;
		else if(x==16)
			ans=0;
		else if(x==17)
			ans=7;
		else if(x==18)
			ans=7;
		else if(x==19)
			ans=4;
		else if(x==20)
			ans=1;
		else if(x==21)
			ans=5;
		else if(x==22)
			ans=6;
		else if(x==23)
			ans=1;
		else if(x==24)
			ans=7;
		else if(x==25)
			ans=8;
		else if(x==26)
			ans=5;
		else if(x==27)
			ans=3;
		else if(x==28)
			ans=8;
		else if(x==29)
			ans=1;
		else if(x==30)
			ans=9;
		else if(x==31)
			ans=0;
		else if(x==32)
			ans=9;
		else if(x==33)
			ans=9;
		else if(x==34)
			ans=8;
		else if(x==35)
			ans=7;
		else if(x==36)
			ans=5;
		else if(x==37)
			ans=2;
		else if(x==38)
			ans=7;
		else if(x==39)
			ans=9;
		else if(x==40)
			ans=6;
		else if(x==41)
			ans=5;
		else if(x==42)
			ans=1;
		else if(x==43)
			ans=6;
		else if(x==44)
			ans=7;
		else if(x==45)
			ans=3;
		else if(x==46)
			ans=0;
		else if(x==47)
			ans=3;
		else if(x==48)
			ans=3;
		else if(x==49)
			ans=6;
		else if(x==50)
			ans=9;
		else if(x==51)
			ans=5;
		else if(x==52)
			ans=4;
		else if(x==53)
			ans=9;
		else if(x==54)
			ans=3;
		else if(x==55)
			ans=2;
		else if(x==56)
			ans=5;
		else if(x==57)
			ans=7;
		else if(x==58)
			ans=2;
		else if(x==59)
			ans=9;
		else if(x==0)
			ans=1;
		printf("%d\n",ans);
	}
	return 0;
}
