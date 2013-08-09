#include<stdio.h>
int GCD(int m,int n){
	if(n==0)
		return m;
	return GCD(n,m%n);
}
int main(){
	int t;
	scanf("%d",&t);
	int i,a,a1,a2,b,b1,b2,c;
	for(i=0;i<t;i++){
		a1=a2=b1=b2=0;
		scanf("%d%d%d",&a,&b,&c);
		int tmp,counta=0,countb=0,flag=-1;
		if(a<b){
			tmp=b;
			b=a;
			a=tmp;
		}
		if((c%GCD(a,b)!=0))
			printf("-1\n");
		else if(c>a&&c>b)
			printf("-1\n");
		else if(c==a||c==b)
			printf("1\n");
		else{
			while(1){
				if(a1==0){
					a1=a;
					counta++;
					if(a1==c){
						flag=0;
						break;
					}
				}
				if(a1>b-b1){
					a1=a1-(b-b1);
					b1=b;
					counta++;
					if(a1==c||b1==c){
						flag=0;
						break;
					}
				}
				else{
					b1+=a1;
					a1=0;
					counta++;
					if(a1==c || b1==c){
						flag=0;
						break;
					}
				}
				if(b1==b){
					b1=0;
					counta++;
				}
				if(b2==0){
					b2=b;
					countb++;
					if(b2==c){
						flag=1;
						break;
					}
				}
				if(b2+a2>a){
					b2=b2+a2-a;
					a2=a;
					countb++;
					if(a2==c||b2==c){
						flag=1;
						break;
					}
				}
				else{
					a2+=b2;
					b2=0;
					countb++;
					if(a2==c||b2==c){
						flag=1;
						break;
					}
				}
				if(a2==a){
					a2=0;
					countb++;
				}
			}
			if(flag==0)
				printf("%d\n",counta);
			else if(flag==1)
				printf("%d\n",countb);
		}
	}
	return 0;
}
