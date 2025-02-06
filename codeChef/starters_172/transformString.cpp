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

void solve() {
  string a, b;
  cin >> a >> b;
  ll lenA = sz(a);
  ll lenB = sz(b);
  vector<bool> remove(lenA, false);

  ll ai = lenA - 1;
  ll bi = lenB - 1;
  while (ai >= 0 && bi >= 0) {
    if (a[ai] == b[bi]) {
      ai--;
      bi--;
    } else {
      remove[ai] = true;
      ai--;
    }
  }

  if (bi >= 0) {
    cout << -1 << endl;
    return;
  }

  while (ai >= 0) {
    remove[ai] = true;
    ai--;
  }

  ll removeCount = 0;
  ll ans = 0;
  for (int i = 0; i < lenA; i++) {
    if (remove[i]) {
      ans += (i + 1 - removeCount);
      removeCount++;
    }
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
