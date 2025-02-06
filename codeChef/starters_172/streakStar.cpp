#ifndef ONLINE_JUDGE
#include "/usr/local/include/bits/stdc++.h"
#else
#include <bits/stdc++.h>
#endif

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

#ifndef ONLINE_JUDGE
#define debug(x)                                                               \
  cerr << #x << " ";                                                           \
  _print(x);                                                                   \
  cerr << endl;
#else
#define debug(x)
#endif

void _print(ll t) { cerr << t; }
void _print(int t) { cerr << t; }
void _print(string t) { cerr << t; }
void _print(char t) { cerr << t; }
void _print(lld t) { cerr << t; }
void _print(double t) { cerr << t; }
void _print(ull t) { cerr << t; }

ll helper(vector<int> &vec) {
  ll n = vec.size();
  ll ans = 0;
  int left = 0;
  int right = 1;

  ll currLen = 1;
  while (right < n) {
    if (vec[right] >= vec[left]) {
      currLen++;
    } else {
      currLen = 1;
    }

    ans = max(ans, currLen);
    left++;
    right++;
  }

  return ans;
}

void solve() {
  ll n, x;
  cin >> n >> x;
  vector<int> vec(n);
  for (auto &it : vec) {
    cin >> it;
  }

  ll ans = 0;
  for (int i = 0; i < n; i++) {
    vec[i] = vec[i] * x;

    ans = max(ans, helper(vec));
    vec[i] = vec[i] / x;
  }

  cout << ans << endl;
}

int main() {
#ifndef ONLINE_JUDGE
  freopen("Error.txt", "w", stderr);
#endif
  fastio();
  ll t;
  cin >> t;
  while (t--) {
    solve();
  }
}
