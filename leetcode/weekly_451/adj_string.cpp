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

string resultingString(string s) {

  int n = s.size();
  vector<char> vec(n);
  for (int i = 0; i < n; i++) {
    vec[i] = s[i];
  }

  if (n == 1) {
    return s;
  }

  int left = 0;
  int right = 1;
  set<int> index;
  vector<bool> remove(n, false);
  while (right < n) {
    char lchar = s[left];
    char rchar = s[right];
    if (abs(lchar - rchar) == 1 || abs(lchar - rchar) == 25) {
      // remove both
      remove[left] = true;
      remove[right] = true;
      right++;
      if (index.size() > 0) {
        auto it = (--index.end());
        left = *it;
        index.erase(it);
      } else {
        left = right;
        right++;
      }
    } else {
      index.insert(left);
      left = right;
      right++;
    }
  }

  string ans = "";
  for (int i = 0; i < n; i++) {
    if (remove[i] == false) {
      ans += vec[i];
    }
  }
  return ans;
}

string better(string s) {
  stack<char> stk;
  for (auto ch : s) {
    if (stk.empty()) {
      stk.push(ch);
    } else {
      char prev = stk.top();
      if (abs(prev - ch) == 1 || abs(prev - ch) == 25) {
        // remove prev and curr
        stk.pop();
      } else {
        stk.push(ch);
      }
    }
  }

  string ans = "";
  while (!stk.empty()) {
    char ch = stk.top();
    stk.pop();
    ans += ch;
  }
  reverse(ans.begin(), ans.end());

  return ans;
}

int main() {
#ifndef ONLINE_JUDGE
  freopen("Error.txt", "w", stderr);
  freopen("input.txt", "r", stdin);
#endif
  fastio();
  resultingString("ratnesh");
}
