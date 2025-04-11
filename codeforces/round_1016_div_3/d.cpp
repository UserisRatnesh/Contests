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
#define nl "\n"
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

template <class T, class V> void _print(pair<T, V> p);
template <class T> void _print(vector<T> v);
template <class T> void _print(set<T> v);
template <class T, class V> void _print(map<T, V> v);
template <class T> void _print(multiset<T> v);
template <class T, class V> void _print(pair<T, V> p) {
  cerr << "{";
  _print(p.ff);
  cerr << ",";
  _print(p.ss);
  cerr << "}";
}
template <class T> void _print(vector<T> v) {
  cerr << "[ ";
  for (T i : v) {
    _print(i);
    cerr << " ";
  }
  cerr << "]";
}
template <class T> void _print(set<T> v) {
  cerr << "[ ";
  for (T i : v) {
    _print(i);
    cerr << " ";
  }
  cerr << "]";
}
template <class T> void _print(multiset<T> v) {
  cerr << "[ ";
  for (T i : v) {
    _print(i);
    cerr << " ";
  }
  cerr << "]";
}
template <class T, class V> void _print(map<T, V> v) {
  cerr << "[ ";
  for (auto i : v) {
    _print(i);
    cerr << " ";
  }
  cerr << "]";
}

/*
   _____          _        ____       _
  / ____|        | |      |  _ \     | |
 | |     ___   __| | ___  | |_) | ___| | _____      __
 | |    / _ \ / _` |/ _ \ |  _ < / _ \ |/ _ \ \ /\ / /
 | |___| (_) | (_| |  __/ | |_) |  __/ | (_) \ V  V /
  \_____\___/ \__,_|\___| |____/ \___|_|\___/ \_/\_/

*/

string findVal(ll n, ll x, ll y) {
  if (n == 0) {
    return "";
  }
  ll border = pow(2, n - 1);
  if (x <= border && y <= border) {
    return "00" + findVal(n - 1, x, y);
  } else if (x > border && y > border) {
    return "01" + findVal(n - 1, x - border, y - border);
  } else if (x > border && y <= border) {
    return "10" + findVal(n - 1, x - border, y);
  } else {
    return "11" + findVal(n - 1, x, y - border);
  }
}

pair<ll, ll> findPos(ll n, ll val) {
  ll N = 2 * n;
  string str = bitset<64>(val).to_string();
  str = str.substr(64 - N);
  ll x = 0, y = 0;
  ll len = str.length();
  ll i = 0;
  while (i < len) {
    string sub = str.substr(i, 2);
    ll border = pow(2, n - 1);
    if (sub == "10") {
      x += border;
    } else if (sub == "01") {
      x += border;
      y += border;
    } else if (sub == "11") {
      y += border;
    }
    i += 2;
    n--;
  }

  return {x, y};
}

void solve() {
  ll n, q;
  cin >> n >> q;
  for (ll i = 0; i < q; i++) {
    string str;
    cin >> str;
    if (str == "->") {
      ll x, y;
      cin >> x >> y;
      string str = findVal(n, x, y);
      ll val = stoll(str, nullptr, 2);
      cout << val + 1 << nl;
    } else {
      ll val;
      cin >> val;
      pair<ll, ll> pos = findPos(n, val - 1);
      cout << pos.first + 1 << " " << pos.second + 1 << nl;
    }
  }
}

int main() {
#ifndef ONLINE_JUDGE
  // freopen("Error.txt", "w", stderr);
  freopen("input.txt", "r", stdin);
#endif
  fastio();
  ll t;
  cin >> t;
  while (t--) {
    solve();
  }
}
