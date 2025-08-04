#ifndef ONLINE_JUDGE
#include "/usr/local/include/bits/stdc++.h"
#else
#include <bits/stdc++.h>
#endif

using namespace std;

#define ratnesh()                                                              \
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
#define yes cout << "YES\n"
#define no cout << "NO\n"

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

long long numOfSubsequences(string s) {

  ll n = s.size();
  vector<ll> prefL(n + 1, 0);
  vector<ll> suffT(n + 1, 0);

  prefL[0] = s[0] == 'L';
  for (ll i = 1; i < n; i++) {
    if (s[i] == 'L') {
      prefL[i] = 1 + prefL[i - 1];
    } else {
      prefL[i] = prefL[i - 1];
    }
  }

  for (ll i = n - 1; i >= 0; i--) {
    if (s[i] == 'T') {
      suffT[i] = 1 + suffT[i + 1];
    } else {
      suffT[i] = suffT[i + 1];
    }
  }

  ll ansA = 0L;
  // if L is added at front
  for (ll i = 0; i < n; i++) {
    ll prevL = prefL[i] + 1;
    ll lastT = suffT[i];

    if (s[i] == 'C') {
      ansA += (prevL * lastT);
    }
  }

  ll ansB = 0L;
  // if T is added at last
  for (ll i = 0; i < n; i++) {
    ll prevL = prefL[i];
    ll lastT = suffT[i] + 1;

    if (s[i] == 'C') {
      ansB += (prevL * lastT);
    }
  }

  // If C is added at mid
  // Find max Product of prevL * lastT
  ll maxProd = 0L;
  ll ansC = 0L;
  for (ll i = 0; i < n; i++) {
    ll prevL = prefL[i];
    ll lastT = suffT[i];
    maxProd = max(maxProd, prevL * lastT);

    if (s[i] == 'C') {
      ansC += (prevL * lastT);
    }
  }

  ansC += maxProd;

  ll ans = max({ansA, ansB, ansC});

  return ans;
}

int main() {
#ifndef ONLINE_JUDGE
  // freopen("Error.txt", "w", stderr);
  freopen("input.txt", "r", stdin);
#endif
  ratnesh();
}
