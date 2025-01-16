#include <algorithm>
#include <iostream>
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
  int n, k;
  cin >> n >> k;
  vector<int> freq(21, 0);
  vector<int> vec(n);
  for (int i = 0; i < n; i++) {
    cin >> vec[i];
    freq[vec[i]]++;
  }

  auto maxPtr = max_element(freq.begin(), freq.end());
  if (*maxPtr == freq[k]) {
    cout << 0 << endl;
    return;
  }

  vector<int> prefix(freq);
  // try to remove prefix

  // this does not result in (N*N) because prefix has fixed size of 21
  for (int i = 0; i < n; i++) {

    // last tak remove karte chale jao
    int maxFreq = *max_element(prefix.begin(), prefix.end());
    if (maxFreq == prefix[k]) {
      cout << 1 << endl;
      return;
    }
    prefix[vec[i]]--;
  }

  vector<int> suffix(freq);
  // try to remove suffix
  for (int i = n - 1; i >= 0; i--) {

    int maxFreq = *max_element(suffix.begin(), suffix.end());
    if (maxFreq == suffix[k]) {
      cout << 1 << endl;
      return;
    }
    suffix[vec[i]]--;
  }

  cout << 2 << endl;
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
