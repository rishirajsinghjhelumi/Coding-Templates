#include<cassert>
#include<cctype>
#include<cerrno>
#include<cfloat>
#include<ciso646>
#include<climits>
#include<clocale>
#include<cmath>
#include<csetjmp>
#include<csignal>
#include<cstdarg>
#include<cstddef>
#include<cstdio>
#include<cstdlib>
#include<cstring>
#include<ctime>

#include<algorithm>
#include<bitset>
#include<complex>
#include<deque>
#include<exception>
#include<fstream>
#include<functional>
#include<iomanip>
#include<ios>
#include<iosfwd>
#include<iostream>
#include<istream>
#include<iterator>
#include<limits>
#include<list>
#include<locale>
#include<map>
#include<memory>
#include<new>
#include<numeric>
#include<ostream>
#include<queue>
#include<set>
#include<sstream>
#include<stack>
#include<stdexcept>
#include<streambuf>
#include<string>
#include<typeinfo>
#include<utility>
#include<valarray>
#include<vector>

using namespace std;
typedef unsigned long long int ULL;
typedef long long int LL;
typedef unsigned long int ULI;
typedef long int LI;
typedef long double LD;

#define MOD 1000000007
#define GC getchar_unlocked
#define SD ({int x;scanf("%d",&x);x;})
#define SC ({char x;scanf("%c",&x);x;})
#define SL ({LI x;scanf("%ld",&x);x;})
#define SUL ({ULI x;scanf("%lu",&x);x;})
#define SLL ({LL x;scanf("%lld",&x);x;})
#define SULL ({ULL x;scanf("%llu",&x);x;})
#define out(n) printf("%d ",n)
#define outln(n) printf("%d\n",n)
#define outl(n) printf("%lld ",n)
#define outlln(n) printf("%lld\n",n)
#define PI M.PI
#define E M.E
#define FORL(i,a,b,l) for(int i=(a);i<(b);i+=(l))
#define FORLD(i,a,b,l) for(int i=(a);i>(b);i-=(l))
#define FOR(i,a,b) FORL(i,a,b,1)
#define FORD(i,a,b) FORLD(i,a,b,1)
#define FIT(it,v) for (typeof(v.begin()) it = v.begin(); it != v.end(); it++)
#define FITD(it,v) for (typeof(v.rbegin()) it = v.rbegin(); it != v.rend(); it++)
#define MAX(a,b) ({a>b?a:b;})
#define MIN(a,b) ({a>b?b:a;})
#define MP make_pair
#define PB push_back
#define SORT(a) sort(a.begin(),a.end())

int input()
{
	register char c = GC();
	int x = 0;
	while( c < 48 || c > 57 )
		c = GC();
	while( c >= 48 && c <= 57 )
	{
		x = (x<<3) + (x<<1) + c - 48;
		c = GC();
	}
	return x;
}
int main()
{
	return 0;
}
