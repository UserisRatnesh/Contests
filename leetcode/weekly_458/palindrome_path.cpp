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

bool isPalindrome(string &str) {
  int l = 0;
  int r = str.size() - 1;
  while (l <= r) {
    if (str[l] != str[r]) {
      return false;
    }
    l++;
    r--;
  }

  return true;
}

void dfs(int node, vector<vector<int>> &adj, string &path, string &label,
         vector<bool> &vis, int &maxLen) {

  if (node == adj.size()) {
    return;
  }

  vis[node] = true;
  path.push_back(label[node]);

  // check and update maxLen
  if (isPalindrome(path)) {
    maxLen = max(maxLen, sz(path));
  }

  for (auto child : adj[node]) {
    if (!vis[child]) {
      dfs(child, adj, path, label, vis, maxLen);
    }
  }

  vis[node] = false;
  path.pop_back();
}

// TC : TLE
int maxLen(int n, vector<vector<int>> &edges, string label) {

  vector<vector<int>> adj(n, vector<int>());
  for (auto edge : edges) {
    int u = edge[0];
    int v = edge[1];
    adj[u].push_back(v);
    adj[v].push_back(u);
  }

  int maxLen = 1;
  vector<bool> vis(n, false);
  string path = "";

  for (int i = 0; i < n; i++) {
    if (!vis[i]) {
      dfs(i, adj, path, label, vis, maxLen);
    }
  }

  return maxLen;
}

// NOTE :optimal

int maxLen_optimal(int n, vector<vector<int>> &edges, string label) {
  vector<vector<int>> adj(n);
  for (auto &e : edges) {
    int u = e[0];
    int v = e[1];
    adj[u].push_back(v);
    adj[v].push_back(u);
  }

  // HACK : dp[mask][i][j] => Ye represent kar rha hai ki I se J jaane me kaun
  // kaun sa bit set hai in mask,jo bit set hai wo represent kar rha hai ki ye
  // ye node liya gya hai
  // dp[mask][i][j] = 1 => Means ye sab leke jo path ban rha hai I to J wo ek
  // valid palindrome hai
  int dp[(1 << n)][n][n];

  // To set the value at dp to zero, initially some garbage value
  memset(dp, 0, sizeof(dp));

  for (int i = 0; i < n; i++) {
    dp[(1 << i)][i][i] = 1;
  }

  for (int i = 0; i < n; i++) {
    for (auto &j : adj[i]) {
      if (label[i] != label[j]) {
        continue;
      }
      dp[((1 << i) | (1 << j))][i][j] = 1;
    }
  }

  int ans = 1;
  for (int mask = 1; mask < (1 << n); mask++) {
    for (int i = 0; i < n; i++) {

      // Agar ith node nahi hai path me to ignore this
      if (!(mask & (1 << i))) {
        continue;
      }
      for (int j = 0; j < n; j++) {

        // Agar jth node nahi hai path me to ignore this
        if (!(mask & (1 << j))) {
          continue;
        }

        // Agar ye valid palindrome nahi bana rha hai to ignore it
        if (!dp[mask][i][j]) {
          continue;
        }

        // Maintain maxLength of valid palindrome by counting how many nodes are
        // there in it's path
        ans = max(ans, __builtin_popcount(mask));

        // Choose those ii and jj who are not in mask
        // And have equal labels then can create valid palindrome
        for (auto &ii : adj[i]) {
          if (mask & (1 << ii)) {
            continue;
          }
          for (auto &jj : adj[j]) {
            if (mask & (1 << jj)) {
              continue;
            }
            if (ii == jj) {
              continue;
            }
            if (label[ii] != label[jj]) {
              continue;
            }

            dp[(mask | (1 << ii) | (1 << jj))][ii][jj] = 1;
          }
        }
      }
    }
  }

  return ans;
}

int main() {
#ifndef ONLINE_JUDGE
  freopen("Error.txt", "w", stderr);
  freopen("input.txt", "r", stdin);
#endif
  ratnesh();
}
