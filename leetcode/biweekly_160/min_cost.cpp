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

void helper(int x, int y, int m, int n, int time, long long currCost,
            long long &minCost, vector<vector<int>> &waitCost,
            vector<vector<bool>> &vis) {
  if (x == m - 1 && y == n - 1) {

    minCost = min(minCost, currCost);
    return;
  }

  if (x >= m || x < 0 || y >= n || y < 0) {
    return;
  }

  vis[x][y] = true;
  if (time % 2 != 0) {

    // down
    helper(x + 1, y, m, n, time + 1, currCost + ((x + 1) * (y + 1)), minCost,
           waitCost, vis);

    // right
    helper(x, y + 1, m, n, time + 1, currCost + ((x + 1) * (y + 1)), minCost,
           waitCost, vis);
  } else {

    helper(x, y, m, n, time + 1, currCost + waitCost[x][y], minCost, waitCost,
           vis);
  }

  vis[x][y] = false;
}

long long minCost_rec(int m, int n, vector<vector<int>> &waitCost) {

  vector<vector<bool>> vis(m, vector<bool>(n, false));
  long long minCost = LLONG_MAX;
  helper(0, 0, m, n, 1, 1, minCost, waitCost, vis);

  return minCost;
}

#define pp pair<ll, ll>

ll minCost(int m, int n, vector<vector<int>> &waitCost) {

  priority_queue<pp, vector<pp>, greater<pp>> pq;
  pq.push({1, 0});

  vector<ll> dis(n * m + 1, LLONG_MAX);

  while (!pq.empty()) {

    ll cost = pq.top().first;
    ll idx = pq.top().second;
    pq.pop();

    ll x = idx / n;
    ll y = idx % n;

    if (x == m - 1 && y == n - 1) {
      return cost - waitCost[m - 1][n - 1];
    }

    // right, down
    int dx[2] = {0, 1};
    int dy[2] = {1, 0};

    for (int dir = 0; dir < 2; ++dir) {
      ll newX = x + dx[dir];
      ll newY = y + dy[dir];

      if (newX < m && newY < n) {
        ll newCost = cost + (newX + 1) * (newY + 1) + waitCost[newX][newY];
        ll newIdx = newX * n + newY;

        if (newCost < dis[newIdx]) {
          pq.push({newCost, newIdx});
          dis[newIdx] = newCost;
        }
      }
    }
  }
  return 0;
}

int main() {
#ifndef ONLINE_JUDGE
  freopen("Error.txt", "w", stderr);
  freopen("input.txt", "r", stdin);
#endif
  ratnesh();
}
