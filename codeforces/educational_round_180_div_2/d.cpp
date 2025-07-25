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

void dfs(ll u, ll parent, vector<vector<ll>> &adj, bool out,
         vector<pair<ll, ll>> &ans) {

  for (auto child : adj[u]) {
    if (child == parent) {
      continue;
    }
    if (out) {
      ans.pb({u, child});
    } else {
      ans.pb({child, u});
    }

    dfs(child, u, adj, !out, ans);
  }
}

void solve() {
  ll n;
  cin >> n;
  vector<vector<ll>> adj(n + 1, vector<ll>());
  vector<ll> deg(n + 1, 0);

  for (ll i = 1; i < n; i++) {
    ll u, v;
    cin >> u >> v;
    deg[u]++;
    deg[v]++;
    adj[u].pb(v);
    adj[v].pb(u);
  }

  ll d2 = -1;
  for (ll i = 1; i <= n; i++) {
    if (deg[i] == 2) {
      d2 = i;
      break;
    }
  }

  if (d2 == -1) {
    no;
    return;
  }

  vector<pair<ll, ll>> ans;
  ans.pb({d2, adj[d2][0]});
  ans.pb({adj[d2][1], d2});
  dfs(adj[d2][0], d2, adj, false, ans);
  dfs(adj[d2][1], d2, adj, true, ans);

  yes;
  for (auto it : ans) {
    cout << it.ff << " " << it.ss << nl;
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
