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

ll maxArea(vector<vector<int>> &coords) {

  int minX = INT_MAX, maxX = INT_MIN;
  int minY = INT_MAX, maxY = INT_MIN;

  for (auto &point : coords) {
    int x = point[0];
    int y = point[1];
    minX = min(minX, x);
    maxX = max(maxX, x);
    minY = min(minY, y);
    maxY = max(maxY, y);
  }

  unordered_map<int, pair<int, int>> vrMap;
  unordered_map<int, pair<int, int>> hrMap;

  for (auto &point : coords) {
    int x = point[0];
    int y = point[1];

    if (!vrMap.count(x))
      vrMap[x] = {y, y};
    else {
      vrMap[x].first = min(vrMap[x].first, y);
      vrMap[x].second = max(vrMap[x].second, y);
    }

    if (!hrMap.count(y))
      hrMap[y] = {x, x};
    else {
      hrMap[y].first = min(hrMap[y].first, x);
      hrMap[y].second = max(hrMap[y].second, x);
    }
  }

  ll maxArea = 0;

  for (auto &[x, yRange] : vrMap) {
    int minY = yRange.first, maxY = yRange.second;
    if (maxY > minY) {
      ll height = maxY - minY;
      maxArea = max(maxArea, height * (maxX - x));
      maxArea = max(maxArea, height * (x - minX));
    }
  }

  // Try triangles with horizontal sides (parallel to x-axis)
  for (auto &[y, xRange] : hrMap) {
    int minX = xRange.first, maxX = xRange.second;
    if (maxX > minX) {
      ll width = maxX - minX;
      maxArea = max(maxArea, width * (maxY - y));
      maxArea = max(maxArea, width * (y - minY));
    }
  }

  return maxArea > 0 ? maxArea : -1;
}

int main() {
#ifndef ONLINE_JUDGE
  freopen("Error.txt", "w", stderr);
  freopen("input.txt", "r", stdin);
#endif
  fastio();
}
