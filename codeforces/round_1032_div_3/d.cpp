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

void solve() {
  ll n;
  cin >> n;
  vector<ll> A(n), B(n);
  for (auto &it : A) {
    cin >> it;
  }

  for (auto &it : B) {
    cin >> it;
  }

  vector<pair<ll, ll>> ops;

  // NOTE: This algorith is based on Bubble sort technique
  // Ek iteration me sabse bada element filter hoke sabse last me chala jata hai
  // Therefore N iteration me N elements sort ho jayega
  //
  // HACK: Aur after calculated observation, Most distorted arrays bhi n^2
  // operations me solve ho jayega ( n = 40, n^2 = 1600 < 1709).

  for (ll pass = 0; pass < n; pass++) {
    for (ll i = 0; i < n - 1; i++) {
      if (A[i] > A[i + 1]) {
        swap(A[i], A[i + 1]);
        ops.pb({1, i + 1});
      }
    }
  }

  for (ll pass = 0; pass < n; pass++) {
    for (ll i = 0; i < n - 1; i++) {
      if (B[i] > B[i + 1]) {
        swap(B[i], B[i + 1]);
        ops.pb({2, i + 1});
      }
    }
  }

  for (ll i = 0; i < n; i++) {
    if (A[i] > B[i]) {
      swap(A[i], B[i]);
      ops.pb({3, i + 1});
    }
  }

  cout << ops.size() << nl;

  for (auto p : ops) {
    cout << p.ff << " " << p.ss << nl;
  }
}

int main() {
#ifndef ONLINE_JUDGE
  freopen("Error.txt", "w", stderr);
  freopen("input.txt", "r", stdin);
#endif
  fastio();
  ll t;
  cin >> t;
  while (t--) {
    solve();
  }
}
