#include <iostream>
#include <vector>
using namespace std;

#define fastio()                                                               \
  ios_base::sync_with_stdio(false);                                            \
  cin.tie(NULL);                                                               \
  cout.tie(NULL)
#define MOD 1000000007
#define MOD1 998244353
#define INF 1e18
#define nline "\n"
#define pb push_back
#define ppb pop_back
#define mp make_pair
#define ff first
#define ss second
#define PI 3.141592653589793238462
#define set_bits __builtin_popcountll
#define sz(x) ((int)(x).size())
#define all(x) (x).begin(), (x).end()

typedef long long ll;
typedef unsigned long long ull;
typedef long double lld;

void solve() {
  int n;
  cin >> n;
  vector<int> vec(n);
  for (int i = 0; i < n; ++i) {
    cin >> vec[i];
  }

  for (int i = 0; i < n; ++i) {
    int iBitCount = set_bits(i + 1);
    int valBitCount = set_bits(vec[i]);
    if (iBitCount != valBitCount) {
      cout << "No" << endl;
      return;
    }
  }

  cout << "Yes" << endl;
  return;
}

int main() {
  fastio(); // To enable fast IO.

  ll t;
  cin >> t;
  while (t--) {
    solve();
  }
}
