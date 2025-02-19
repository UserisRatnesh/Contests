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

// TC: O(n^2)
// NOTE: Giving TLE
void find_beauty(vector<ll> &vec) {

  ll ans = vec[0];
  ll n = vec.size();
  bool isAnd = true;
  for (ll i = 1; i < n; i++) {
    if (isAnd) {
      ans &= vec[i];
    } else {
      ans |= vec[i];
    }
    isAnd = !isAnd;
  }

  cout << ans << endl;
}

void solve() {
  ll n;
  cin >> n;
  vector<ll> vec(n);
  for (auto &it : vec) {
    cin >> it;
  }
  ll q;
  cin >> q;
  vector<pair<ll, ll>> query(q);
  for (auto &it : query) {
    ll first, second;
    cin >> first >> second;
    it = mp(first, second);
  }

  for (int i = 0; i < q; i++) {

    pair<ll, ll> p = query[i];

    ll index = p.first - 1;
    vec[index] = p.second;
    find_beauty(vec);
  }
}

// NOTE: optimized
// TC: O(n + q*log(mapsize))
void solveBetter() {
  ll n;
  cin >> n;
  // NOTE: GoodIndex is that index that affects the and
  // like and waala jab zero rhega then result -> 0 for sure
  // or waala one rhega then result -> 1 for sure

  // (index, value)
  map<ll, ll> goodIndex;
  for (ll i = 1; i <= n; i++) {
    ll val;
    cin >> val;

    if (i % 2 == val) {
      goodIndex[i] = val;
    }
  }

  ll q;
  cin >> q;

  ll ans = 0;
  while (q--) {
    ll index, value;
    cin >> index >> value;

    if (goodIndex.find(index) != goodIndex.end() && index % 2 != value) {
      // if present in goodindex but after qry not a goodindex anymore then
      // update the goodindex
      goodIndex.erase(index);
    }

    // if good index then add to goodindex
    if (index % 2 == value) {
      goodIndex[index] = value;
    }

    if (!goodIndex.empty()) {
      auto last = prev(goodIndex.end());
      ans = last->second;
      cout << ans << endl;
    } else {
      cout << 0 << endl;
    }
  }
}

int main() {
#ifndef ONLINE_JUDGE
  freopen("Error.txt", "w", stderr);
#endif
  fastio();
  ll t;
  cin >> t;
  while (t--) {
    solveBetter();
  }
}
