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

char processStr(string s, long long k) {

  vector<long long> lengths(s.size());
  long long currLen = 0;

  // Forward pass
  for (int i = 0; i < s.size(); ++i) {
    char ch = s[i];
    if ('a' <= ch && ch <= 'z') {
      if (currLen < 1e15) {
        currLen++;
      }
    } else if (ch == '*') {
      if (currLen > 0) {
        currLen--;
      }
    } else if (ch == '#') {
      if (currLen <= 1e15 / 2) {
        currLen *= 2;
      } else {
        currLen = 1e15 + 1;
      }
    }
    lengths[i] = currLen;
  }

  if (k >= currLen)
    return '.';

  // Reverse pass
  for (int i = s.size() - 1; i >= 0; --i) {
    char ch = s[i];
    currLen = lengths[i];

    if ('a' <= ch && ch <= 'z') {
      currLen--;
      if (k == currLen) {
        return ch;
      }
    } else if (ch == '*') {
      if (currLen < lengths[i]) {
        currLen++;
      }
    } else if (ch == '#') {
      long long half = lengths[i] / 2;
      if (k >= half) {
        k -= half;
      }
      currLen = half;
    } else if (ch == '%') {
      k = currLen - 1 - k;
    }
  }

  return '.';
}

// NOTE:

char processStr_optimal(string s, long long k) {

  long long n = 0;
  for (auto it : s) {
    if (it == '*') {
      n = max(0LL, n - 1);
    } else if (it == '#') {
      n *= 2;
    } else if (it == '%') {
      // reverse
      continue;
    } else {
      n++;
    }
  }

  if (k >= n) {
    return '.';
  }

  reverse(s.begin(), s.end());

  // reverse the operations
  for (auto it : s) {
    if (it == '*') {
      n++;
    } else if (it == '%') {
      k = n - k - 1;
    } else if (it == '#') {

      long long half = n / 2;
      if (k >= half) {
        k -= half;
      }
      n -= half;
    } else {
      n--;
      if (k <= n) {
        return it;
      }
    }
  }

  return '.';
}

int main() {
#ifndef ONLINE_JUDGE
  freopen("Error.txt", "w", stderr);
  freopen("input.txt", "r", stdin);
#endif
  ratnesh();

  char ans = processStr("%lnwu*swza", 0);
  cout << ans << nl;
}
