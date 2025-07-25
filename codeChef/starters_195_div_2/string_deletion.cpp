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

void solve() {
  ll n;
  cin >> n;
  string s;
  cin >> s;

  ll firstOne = -1;
  ll lastOne = -1;
  ll firstZero = -1;
  ll lastZero = -1;

  for (int i = 0; i < n; i++) {
    if (s[i] == '1') {
      if (firstOne == -1) {
        firstOne = i;
      }
      lastOne = i;
    } else {
      if (firstZero == -1) {
        firstZero = i;
      }
      lastZero = i;
    }
  }

  ll cntZero = 0;
  for (ll i = firstOne; i <= lastOne; i++) {
    if (s[i] == '0') {
      cntZero++;
    }
  }

  ll cntOne = 0;
  for (ll i = firstZero; i <= lastZero; i++) {
    if (s[i] == '1') {
      cntOne++;
    }
  }

  ll ans = 0;
  if (s[0] == '1' && s[n - 1] == '0') {
    ll dels = 0;
    for (ll i = firstZero; i <= lastZero; i++) {
      if (s[i] == '1') {
        dels++;
      }
    }
    dels--;
    for (ll i = firstOne; i <= lastOne; i++) {
      if (s[i] == '0') {
        dels++;
      }
    }
    ans = max(ans, dels);
  } else if (s[0] == '0' && s[n - 1] == '1') {
    ll dels = 0;
    for (ll i = firstOne; i <= lastOne; i++) {
      if (s[i] == '0') {
        dels++;
      }
    }

    dels--;
    for (ll i = firstZero; i <= lastZero; i++) {
      if (s[i] == '1') {
        dels++;
      }
    }

    ans = max(ans, dels);
  } else if (s[0] == '0' && s[n - 1] == '0') {
    ll dels = 0;
    for (ll i = firstOne; i <= lastOne; i++) {
      if (s[i] == '0') {
        dels++;
      }
    }
    for (ll i = firstZero; i <= lastZero; i++) {
      if (s[i] == '1') {
        dels++;
      }
    }

    ans = max(ans, dels);
  } else if (s[0] == '1' && s[n - 1] == '1') {
    ll dels = 0;
    for (ll i = firstOne; i <= lastOne; i++) {
      if (s[i] == '0') {
        dels++;
      }
    }
    for (ll i = firstZero; i <= lastZero; i++) {
      if (s[i] == '1') {
        dels++;
      }
    }

    ans = max(ans, dels);
  }

  cout << n - ans << nl;
}

// OPTIMAL:
void solveBetter() {
  ll n;
  cin >> n;
  string s;
  cin >> s;

  ll segments = 1;
  for (ll i = 1; i < n; i++) {
    if (s[i] != s[i - 1]) {
      segments++;
    }
  }

  ll firstSegSize = 1;
  for (ll i = 1; i < n; i++) {
    if (s[i] != s[i - 1]) {
      break;
    }
    firstSegSize++;
  }

  ll lastSegSize = 1;
  for (ll i = n - 2; i >= 0; i--) {
    if (s[i] != s[i + 1]) {
      break;
    }
    lastSegSize++;
  }

  ll ans = 0;
  if (segments < 3) {
    cout << n << nl;
    return;
  } else if (segments % 2 == 0) {
    // All segments can be removed except first and last segment And one extra
    // character
    ans = max(ans, firstSegSize + lastSegSize + 1);
  } else {
    ans = max(ans, firstSegSize + lastSegSize);
  }

  cout << ans << nl;
}

int main() {
#ifndef ONLINE_JUDGE
  freopen("Error.txt", "w", stderr);
  freopen("input.txt", "r", stdin);
#endif
  ratnesh();
  ll t;
  cin >> t;
  while (t--) {
    solveBetter();
  }
}
