#include<stdio.h>
int main (){
	int t,p,q;
	long long int i,j,m,n,ans;
	int **a = (int **)malloc(1001 * sizeof(int*));
	for(i=0;i<=1000;i++)
		a[i] = (int *)malloc(1001 * sizeof(int));
	for(i=1;i<=1000;i++){
		a[0][i] = 0;
		a[1][i] = i;
	}
	for(j=3;j<=1000;j++){
		for(i=2;i<j;i++){
			a[i][j] = (j/i)+a[j%i][i];
		}
	}

	for(j=3;j<=1000;j++){
		for(i=2;i<j;i++){
			a[i][j] += a[i-1][j];
		}
	}

	scanf("%d",&t);
	while(t--){
		scanf("%lld",&m);scanf("%lld",&n);scanf("%d",&p);scanf("%d",&q);
		ans=0;
		for(j=p;j<=q;j++){
			if(j==1)
				ans += (n*(n+1)/2)-(m*(m-1)/2);
			else
				if((m/j)==(n/j)){
					ans += (a[n%j][j]+(n-m+1)*(m/j));
					if((m%j)>0)
						ans -= a[(m%j)-1][j];
				}else{
					ans += (a[j-1][j]+(j-(m%j))*(m/j)+a[n%j][j]+((n%j)+1)*(n/j));
					if((m%j)>0)
						ans -= a[(m%j)-1][j];
					if(((n/j)-(m/j)) > 1){
						ans += a[j-1][j]*((n/j)-(m/j)-1);
						ans += j*(((n/j)*((n/j)-1)/2)-((m/j)*((m/j)+1)/2));
					}
				}
		}
		printf("%lld\n",ans);
	}
	return 0;
} 
