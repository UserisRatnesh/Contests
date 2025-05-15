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

  vector<ll> ratings(5);
  ll sum = 0;
  for (ll i = 0; i < 5; i++) {
    cin >> ratings[i];
    sum += ratings[i];
  }

  sort(all(ratings));

  if (sum / 5 >= 7) {
    cout << 0 << nl;
  } else if ((sum - ratings[0] + 10) / 5 >= 7) {
    cout << 100 << nl;
  } else if ((sum - ratings[0] - ratings[1] + 20) / 5 >= 7) {
    cout << 200 << nl;
  } else if ((sum - ratings[0] - ratings[1] - ratings[2] + 30) / 5 >= 7) {
    cout << 300 << nl;
  } else if ((sum - ratings[0] - ratings[1] - ratings[2] - ratings[3] + 40) /
                 5 >=
             7) {
    cout << 400 << nl;
  } else {
    cout << 500 << nl;
  }
}

void solveBetter() {

  vector<ll> ratings(5);
  ll sum = 0;
  for (ll i = 0; i < 5; i++) {
    cin >> ratings[i];
    sum += ratings[i];
  }

  sort(all(ratings));

  ll ans = 0;
  for (auto it : ratings) {
    if (sum >= 35) {
      cout << ans << nl;
      return;
    }

    sum = sum - it + 10;
    ans += 100;
  }

  cout << ans << nl;
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
    solveBetter();
  }
}
