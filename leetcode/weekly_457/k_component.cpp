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

// TOPIC: Disjoint set data structure
class DisjointSet {
  vector<int> rank, size, parent;

public:
  int components;
  DisjointSet(int n) {

    components = n;
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
    components--;
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
    components--;
  }
};

// NOTE: Instead of removing the edges try to reverse the operation say - add
// the edges
// Approach =>Pahle sort karlo on incresing order of time.
// Hum last se ith edge tak remove karenge. Agar components >= k yaani chances
// hai ki aur LESS remove kar sakte hai to aise hi aage badhte rhenge.
// Agar aisa aata hai ki jth remove karne ke baad components < k to ye obvious
// hai ki last se leke (j+1) tak hi remove karneg to ans aayega
// Aur (j+1)th waala time Ans ho jayega
// Special =>
// Aur agar aisa hota hai ki koi remove nahi karte uske baad bhi components >= k
// aata hai to Ans = 0 ho jayega.

int minTime_II(int n, vector<vector<int>> &edges, int k) {

  sort(edges.begin(), edges.end(),
       [](const vector<int> &e1, const vector<int> &e2) {
         return e1[2] > e2[2];
       });

  // Now keep adding the edges having larger time untill components >= k
  // And as soon as components < k then return that time

  DisjointSet ds(n);
  int time = -1;

  for (int i = 0; i < edges.size(); i++) {

    int u = edges[i][0];
    int v = edges[i][1];
    int t = edges[i][2];

    int components = ds.components;
    if (components >= k) {
      time = t;
    } else {
      break;
    }
    ds.unionBySize(u, v);
  }

  if (ds.components >= k) {
    return 0;
  }
  return time;
}

int main() {
#ifndef ONLINE_JUDGE
  freopen("Error.txt", "w", stderr);
  freopen("input.txt", "r", stdin);
#endif
  ratnesh();
}
