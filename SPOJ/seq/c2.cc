#include <iostream>
#include <map>
using namespace std;
int T, N, x;
map<long long,int> bolo;

int main() {
  cin >> T;

  while (T--) {
    cin >> N;
    bolo.clear();

    long long res = 0, sum = 0;
    bolo[0] = 1;

    while (N--) {
      cin >> x;
      sum += x;
      res += bolo[ sum-47 ];
      bolo[sum]++;
    }
    cout << res << endl;
  }
}
