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

int minMoves(vector<string> &classroom, int energy) {

  int rows = classroom.size();
  int cols = classroom[0].size();

  pair<int, int> start;
  vector<pair<int, int>> litter;
  map<pair<int, int>, int> lit_id;
  int l = 0;

  for (int i = 0; i < rows; i++) {
    for (int j = 0; j < cols; j++) {
      if (classroom[i][j] == 'S') {
        start = {i, j};
      }
      if (classroom[i][j] == 'L') {
        litter.push_back({i, j});
        lit_id[{i, j}] = l;
        l++;
      }
    }
  }

  // Maintaining the states
  bool vis[20][20][1 << 10][51];
  memset(vis, false, sizeof(vis));

  struct State {
    int x, y, mask, e, d;
  };

  queue<State> que;
  que.push({start.first, start.second, 0, energy, 0});
  vector<vector<int>> dirs = {{1, 0}, {-1, 0}, {0, 1}, {0, -1}};
  vis[start.first][start.second][0][energy] = true;

  while (!que.empty()) {
    State s = que.front();
    que.pop();

    // all litter collected
    if (s.mask == (1 << l) - 1) {
      return s.d;
    }

    // if out of energy
    if (s.e == 0) {
      continue;
    }

    for (auto &dir : dirs) {
      int newX = s.x + dir[0];
      int newY = s.y + dir[1];

      if (newX < 0 || newX >= rows || newY < 0 || newY >= cols ||
          classroom[newX][newY] == 'X') {
        continue;
      }

      int newE = s.e - 1;

      if (classroom[newX][newY] == 'R') {
        newE = energy;
      }

      int newMask = s.mask;

      if (classroom[newX][newY] == 'L') {
        newMask |= (1 << lit_id[{newX, newY}]);
      }

      if (!vis[newX][newY][newMask][newE]) {
        vis[newX][newY][newMask][newE] = true;
        que.push({newX, newY, newMask, newE, s.d + 1});
      }
    }
  }

  return -1;
}

int main() {
#ifndef ONLINE_JUDGE
  freopen("Error.txt", "w", stderr);
  freopen("input.txt", "r", stdin);
#endif
  fastio();
}
