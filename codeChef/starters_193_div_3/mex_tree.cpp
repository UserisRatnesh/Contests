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

void bfs_distance(ll start, vector<vector<ll>> &adjList,
                  vector<ll> &distances) {
  int n = adjList.size();

  distances.assign(n, -1);

  deque<int> dq;
  distances[start] = 0;
  dq.push_back(start);

  while (!dq.empty()) {
    int current = dq.front();
    dq.pop_front();

    for (int neighbor : adjList[current]) {
      if (distances[neighbor] == -1) {
        distances[neighbor] = distances[current] + 1;
        dq.push_back(neighbor);
      }
    }
  }
}

void solve() {
  ll n;
  cin >> n;

  vector<vector<ll>> tree(n);

  for (ll i = 0; i < n - 1; ++i) {
    ll u, v;
    cin >> u >> v;

    u--;
    v--;
    tree[u].push_back(v);
    tree[v].push_back(u);
  }

  vector<ll> distance;

  bfs_distance(0, tree, distance);

  ll farthestNode =
      max_element(distance.begin(), distance.end()) - distance.begin();

  bfs_distance(farthestNode, tree, distance);
  ll diameter = *max_element(distance.begin(), distance.end());

  ll result;
  if (diameter + 1 == n) {
    result = 2LL * n - 1;
  } else {
    result = n + 1;
  }

  cout << result << nl;
}

// Upsolve better

ll get_leaf_count(vector<vector<ll>> &adj) {

  ll n = adj.size();
  ll cnt = 0;
  for (ll i = 1; i <= n; i++) {
    if (adj[i].size() == 1) {
      cnt++;
    }
  }

  return cnt;
}

void solve_simple() {
  ll n;
  cin >> n;
  vector<vector<ll>> adj(n + 1, vector<ll>());

  for (ll i = 0; i < n - 1; i++) {
    ll u, v;
    cin >> u >> v;
    adj[u].pb(v);
    adj[v].pb(u);
  }

  ll ans = 0;

  // find number of leaves
  ll leaf_cnt = get_leaf_count(adj);

  if (leaf_cnt > 2) {
    ans = (n - 1) + 2;
  } else {
    ans = (n - 1) + n;
  }

  cout << ans << nl;
}

int main() {
#ifndef ONLINE_JUDGE
  // freopen("Error.txt", "w", stderr);
  freopen("input.txt", "r", stdin);
#endif
  fastio();
  ll t;
  cin >> t;
  while (t--) {
    solve_simple();
  }
}
