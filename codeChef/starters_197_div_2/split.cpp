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

// NOTE: self
// TC: TLE
void solve() {
  ll n, k;
  cin >> n >> k;
  string s;
  cin >> s;

  vector<ll> prefZero(n + 1, 0);
  vector<ll> suffOne(n + 1, 0);

  // build prefZero array
  prefZero[0] = s[0] == '0';
  for (ll i = 1; i < n; i++) {
    if (s[i] == '0') {
      prefZero[i] = 1 + prefZero[i - 1];
    } else {
      prefZero[i] = prefZero[i - 1];
    }
  }

  // build suffone array
  suffOne[n - 1] = s[n - 1] == '1';
  for (ll i = n - 2; i >= 0; i--) {
    if (s[i] == '1') {
      suffOne[i] = 1 + suffOne[i + 1];
    } else {
      suffOne[i] = suffOne[i + 1];
    }
  }

  // lambda expression for finding f(s)
  auto fun = [&](string &s, ll start, ll end) {
    ll maxiF = LLONG_MIN;
    for (ll i = start; i <= end; i++) {
      ll zeroContri = prefZero[i] - (start == 0 ? 0 : prefZero[start - 1]);
      ll oneContri = suffOne[i] - (end == n - 1 ? 0 : suffOne[end + 1]);
      ll len = zeroContri + oneContri;
      maxiF = max(maxiF, len);
    }

    return maxiF;
  };

  // lambda expression for isPossible
  auto isPossible = [&](ll val) {
    ll segments = 0;
    ll start = 0;
    ll end = 0;
    while (end < n) {

      if (fun(s, start, end) == val) {
        // start new segment
        segments++;
        start = end + 1;
        end++;
      } else {
        end++;
      }

      if (segments >= k) {
        // already possible
        break;
      }
    }

    return segments >= k;
  };

  ll low = 1;
  ll high = n / k;
  ll ans = 1;

  while (low <= high) {
    ll mid = low + (high - low) / 2;
    if (isPossible(mid)) {
      ans = mid;
      low = mid + 1;
    } else {
      high = mid - 1;
    }
  }

  cout << ans << nl;
}

// OPTIMAL:
void solve_better() {
  ll n, k;
  cin >> n >> k;
  string s;
  cin >> s;

  // lambda expression for isPossible
  auto isPossible = [&](ll val) {
    ll segments = 0;
    ll dp0 = 0; // the req. subsequence ending with 0
    ll dp1 = 0; // the req. subsequence ending with 1

    for (int i = 0; i < n; ++i) {
      if (s[i] == '0') {
        dp0 += 1;
      } else {
        dp1 = 1 + max(dp0, dp1);
      }

      ll len = max(dp0, dp1);
      if (len == val) {
        segments++;
        dp0 = dp1 = 0;
      }
    }

    return segments >= k;
  };

  ll low = 1;
  ll high = n / k;
  ll ans = 1;

  while (low <= high) {
    ll mid = low + (high - low) / 2;
    if (isPossible(mid)) {
      ans = mid;
      low = mid + 1;
    } else {
      high = mid - 1;
    }
  }

  cout << ans << nl;
}

int main() {
#ifndef ONLINE_JUDGE
  // freopen("Error.txt", "w", stderr);
  freopen("input.txt", "r", stdin);
#endif
  ratnesh();
  ll t;
  cin >> t;
  while (t--) {
    solve_better();
  }
}
