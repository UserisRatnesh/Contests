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

void helper(int node, vector<vector<int>> &adj, vector<bool> &alive,
            vector<bool> &vis, vector<vector<int>> &queries, vector<int> &ans) {

  // iterate over this island and push everything in map

  set<int> st;
  set<int> all;
  // BFS
  queue<int> que;
  que.push(node);
  vis[node] = true;
  st.insert(node);

  while (!que.empty()) {
    int u = que.front();
    que.pop();

    all.insert(u);

    for (auto v : adj[u]) {
      if (!vis[v]) {
        vis[v] = true;
        st.insert(v);
        que.push(v);
      }
    }
  }

  int qs = queries.size();
  for (int i = 0; i < qs; i++) {
    vector<int> query = queries[i];
    int type = query[0];
    int u = query[1];

    if (all.find(u) == all.end()) {
      continue;
    }

    // this query to be resolved in this island
    // queryDoneIndex.insert(i);
    if (type == 2) {
      st.erase(u);
      alive[u] = false;
    } else {
      if (alive[u]) {
        ans[i] = u;
      } else if (st.empty()) {
        ans[i] = -1;
      } else {
        ans[i] = (*st.begin());
      }
    }
  }
}

vector<int> processQueries(int c, vector<vector<int>> &connections,
                           vector<vector<int>> &queries) {
  vector<vector<int>> adj(c + 1);
  for (auto it : connections) {
    int u = it[0];
    int v = it[1];
    adj[u].push_back(v);
    adj[v].push_back(u);
  }

  vector<bool> alive(c + 1, true);
  vector<bool> vis(c + 1, false);
  vector<int> ans(queries.size(), -2);
  // set<int> st;

  for (int i = 1; i <= c; i++) {
    // go to each island grid
    if (!vis[i]) {
      helper(i, adj, alive, vis, queries, ans);
    }
  }

  vector<int> output;
  for (auto it : ans) {
    if (it != -2) {
      output.push_back(it);
    }
  }
  return output;
}

// TOPIC: Disjoint set data structure
class DisjointSet {
  vector<int> rank, size, parent;

public:
  DisjointSet(int n) {

    rank.resize(n + 1, 0);
    size.resize(n + 1, 1);
    parent.resize(n + 1);
    for (int i = 0; i <= n; i++) {
      parent[i] = i;
    }
  }

  // First time log n and after that constant time
  int findUParent(int u) {
    if (u == parent[u]) {
      return u;
    }
    return parent[u] = findUParent(parent[u]);
  }

  void unionByRank(int u, int v) {
    int ulp_u = findUParent(u);
    int ulp_v = findUParent(v);

    if (ulp_u == ulp_v) {
      return;
    }

    if (rank[ulp_u] < rank[ulp_v]) {
      parent[ulp_u] = ulp_v;
    } else if (rank[ulp_v] < rank[ulp_u]) {
      parent[ulp_v] = ulp_u;
    } else {
      parent[ulp_v] = ulp_u;
      rank[ulp_u]++;
    }
  }

  void unionBySize(int u, int v) {
    int ulp_u = findUParent(u);
    int ulp_v = findUParent(v);

    if (ulp_u == ulp_v) {
      return;
    }

    if (size[ulp_u] < size[ulp_v]) {
      parent[ulp_u] = ulp_v;
      size[ulp_v] += size[ulp_u];
    } else {
      parent[ulp_v] = ulp_u;
      size[ulp_u] += size[ulp_v];
    }
  }
};

vector<int> solve_power_grid(int c, vector<vector<int>> &connections,
                             vector<vector<int>> &queries) {

  DisjointSet ds(c);
  for (auto it : connections) {
    ds.unionByRank(it[0] - 1, it[1] - 1);
  }

  vector<bool> alive(c, 1);

  map<int, set<int>> miniMap;
  for (int i = 0; i < c; i++) {
    miniMap[ds.findUParent(i)].insert(i);
  }

  vector<int> ans;

  for (auto it : queries) {
    if (it[0] == 1) {
      int node = it[1] - 1;
      if (alive[node])
        ans.push_back(node + 1);
      else {
        int p = ds.findUParent(node);
        if (miniMap[p].size() == 0) {
          ans.push_back(-1);
          continue;
        }
        int num = *miniMap[p].begin();
        num++;
        ans.push_back(num);
      }
    } else {
      int node = it[1] - 1;
      alive[node] = false;
      miniMap[ds.findUParent(node)].erase(node);
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
