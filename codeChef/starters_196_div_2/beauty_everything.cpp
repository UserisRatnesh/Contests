#ifndef ONLINE_JUDGE
#include "/usr/local/include/bits/stdc++.h"
#else
#include <bits/stdc++.h>
#endif

using namespace std;
using namespace chrono; // For time measurement

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

// Print Execution time
#ifndef ONLINE_JUDGE
void printExecutionTime(chrono::high_resolution_clock::time_point start_time) {
  auto end_time = chrono::high_resolution_clock::now();
  auto duration =
      chrono::duration_cast<chrono::milliseconds>(end_time - start_time);
  cerr << "Time taken: " << duration.count() << " ms\n";
}
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

  ll p0 = -1;
  ll p1 = -1;
  vector<ll> prev0(n + 1, -1);
  vector<ll> prev1(n + 1, -1);
  for (ll i = 0; i < n; i++) {
    if (s[i] == '0') {
      p0 = i;
    } else {
      p1 = i;
    }

    prev0[i] = p0;
    prev1[i] = p1;
  }

  if (n <= 3) {
    cout << n << nl;
    return;
  }

  ll ans = 3;
  for (ll i = 3; i < n; i++) {
    ll tempAns = i + 1;

    // 0110
    ll temp = prev0[i];
    ll cnt = 1;
    if (temp - 1 >= 0) {
      temp = prev1[temp - 1];
      cnt++;
    }
    if (temp - 1 >= 0) {
      temp = prev1[temp - 1];
      cnt++;
    }
    if (temp - 1 >= 0) {
      temp = prev0[temp - 1];
      cnt++;
    }

    if (cnt == 4) {
      tempAns = min(tempAns, i - temp);
    }

    // 0011
    temp = prev0[i];
    cnt = 1;
    if (temp - 1 >= 0) {
      temp = prev0[temp - 1];
      cnt++;
    }
    if (temp - 1 >= 0) {
      temp = prev1[temp - 1];
      cnt++;
    }
    if (temp - 1 >= 0) {
      temp = prev1[temp - 1];
      cnt++;
    }

    if (cnt == 4) {
      tempAns = min(tempAns, i - temp);
    }

    // 1100
    temp = prev1[i];
    cnt = 1;
    if (temp - 1 >= 0) {
      temp = prev1[temp - 1];
      cnt++;
    }
    if (temp - 1 >= 0) {
      temp = prev0[temp - 1];
      cnt++;
    }
    if (temp - 1 >= 0) {
      temp = prev0[temp - 1];
      cnt++;
    }

    if (cnt == 4) {
      tempAns = min(tempAns, i - temp);
    }

    // 1001
    temp = prev1[i];
    cnt = 1;
    if (temp - 1 >= 0) {
      temp = prev0[temp - 1];
      cnt++;
    }
    if (temp - 1 >= 0) {
      temp = prev0[temp - 1];
      cnt++;
    }
    if (temp - 1 >= 0) {
      temp = prev1[temp - 1];
      cnt++;
    }

    if (cnt == 4) {
      tempAns = min(tempAns, i - temp);
    }

    ans = max(ans, tempAns);
  }

  cout << ans << nl;
}

// Solve better
// OPTIMAL:
void solveBetter() {
  int t;
  cin >> t;
  while (t--) {
    int n;
    string s;
    cin >> n >> s;

    int ones = 0;
    int l = 0, r = 0;
    int ans1 = 0;
    int ans = 0;

    // Waisa segment lo jisme sirf ek hi one ho
    while (r < n) {
      if (s[r] == '1')
        ones++;
      while (ones > 1) {
        if (s[l] == '1')
          ones--;
        l++;
      }
      ans1 = max(ans1, r - l + 1);
      r++;
    }

    int zero = 0;
    l = 0, r = 0;
    int ans2 = 0;

    // Waisa segment lo jisme sirf ek hi zero ho
    while (r < n) {
      if (s[r] == '0')
        zero++;
      while (zero > 1) {
        if (s[l] == '0')
          zero--;
        l++;
      }
      ans2 = max(ans2, r - l + 1);
      r++;
    }

    ans = max(ans1, ans2); /// Take maximum of above two cases

    int ans3 = 0;
    if (ans < 4)
      for (int i = 0; i + 3 < n; i++) {
        if (s.substr(i, i + 4) == "0101" || s.substr(i, i + 4) == "1010") {
          ans3 = 4;
          break;
        }
      }

    ans = max(ans, ans3);
    cout << ans << endl;
  }
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
    solve();
  }
}
