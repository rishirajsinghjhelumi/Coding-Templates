#include <cstdio>
#include <algorithm>
using namespace std;
#define INFTY 2000000000
#define S(i) a[i].first
#define I(i) a[i].second

int main() {
  long n, c, x, TC;
  pair<long,long> a[1000010];

  scanf("%ld", &TC);
  for (long t=0; t<TC; ++t) {
    scanf("%ld", &n);
    c = 0; S(0)=0; I(0)=0;
    for (long i=1; i<=n; ++i) { 
      scanf ("%ld", &x); S(i) = S(i-1)+x; I(i) = i; 
    }
    S(n+1) = INFTY;
    
    sort (a, a+n+1);
    
    long i = 0, j = 0;
    while (j<=n) {
      if (S(j)-S(i)<47) j++;
      else if (S(j)-S(i)>47) i++;
      else {
        int ie, je;
        for (ie=i; S(ie+1)==S(ie); ++ie); ++ie;
        for (je=j; S(je+1)==S(je); ++je); ++je;
        while (i<ie && j<je)
          if (I(i)>I(j)) j++; else { c += (je-j); i++; }
        i = ie; j = je;
      }
    }
    printf ("%ld\n", c);
  }
  return 0;
}
