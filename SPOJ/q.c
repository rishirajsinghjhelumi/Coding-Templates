#include <vector>
#include <list>
#include <map>
#include <set>
#include <deque>
#include <queue>
#include <stack>
#include <bitset>
#include <algorithm>
#include <functional>
#include <numeric>
#include <utility>
#include <sstream>
#include <iostream>
#include <iomanip>
#include <cstdio>
#include <cmath>
#include <cstdlib>
#include <cctype>
#include <string>
#include <cstring>
#include <cstdio>
#include <cmath>
#include <cstdlib>
#include <ctime>
using namespace std;

int main()
{
	int t,a,b,c,ret,tmp,k_1,k_2,k_3,sign,cnt,f=0;
	for(scanf("%d\n",&t);t>0;t--)
	{
		string s;
		a=1,b=1,c=0,ret=0;
		getline(cin,s);
		k_1=s.find("x*x",0);
		if (k_1!=0) 
		{
			for(int i=0;i<k_1-1;i++) 
				ret=ret*10+(s[i]-'0');
			a=ret;
		}
		k_2=s.find("x",k_1+3);
		if(k_2==string::npos) 
			b=0;
		else
		{
			ret=0;
			if(s[k_1+3]=='-') 
				sign=-1;
			else 
				sign=1;
			for(int i=k_1+4;i<k_2 && (s[i]>='0' && s[i]<'9');i++) 
				ret=ret*10+(s[i]-'0');
			if(ret!=0) 
				b=ret*sign;
			else 
				b=sign;
		}

		k_3=s.find('=',0);
		ret=0;
		tmp=1;cnt=k_3-1;
		for(cnt=k_3-1;s[cnt]>='0' && s[cnt]<='9';cnt--)
		{
			ret=ret+(s[cnt]-'0')*tmp;
			tmp*=10;
		}
		if(s[cnt]=='-') 
			c=-ret;
		else  
			c=ret;
		if((b*b-4*a*c)<0) cout<<"Imaginary roots.\n";
		else if ((b*b-4*a*c)==0) cout<<"Equal roots.\n";
		else cout<<"Distinct real roots.\n";
		//cout<<a<<" "<<b<<" "<<c<<endl;

	}
}

