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

// Get all prime factors
set<int> getPrimeFact(int n) {

  set<int> st;
  while (n % 2 == 0) {
    st.insert(2);
    n = n / 2;
  }

  for (int i = 3; i * i <= n; i = i + 2) {

    while (n % i == 0) {
      st.insert(i);
      n = n / i;
    }
  }

  if (n > 2) {
    st.insert(n);
  }

  return st;
}

int minJumps(vector<int> &nums) {

  int n = nums.size();
  if (n == 1) {
    return 0;
  }
  if (n == 2) {
    return 1;
  }

  map<int, set<int>> indexMap;
  map<int, set<int>> primeFact;
  for (int i = 0; i < n; i++) {
    indexMap[nums[i]].insert(i);
    primeFact[nums[i]] = getPrimeFact(nums[i]);
  }

  if (primeFact[nums[n - 1]].find(nums[0]) != primeFact[nums[n - 1]].end()) {
    return 1;
  }

  int maxi = *max_element(nums.begin(), nums.end());

  vector<set<int>> adj(n + 1, set<int>());
  vector<bool> isPresent(maxi + 1, false);

  for (auto it : nums) {
    isPresent[it] = true;
  }

  for (int i = 0; i < n; i++) {

    int curr = nums[i];

    if (i == 0) {
      adj[i].insert(i + 1);
      adj[i + 1].insert(i);
    } else if (i == n - 1) {
      adj[i].insert(i - 1);
      adj[i - 1].insert(i);
    } else {
      adj[i].insert(i + 1);
      adj[i].insert(i - 1);
      adj[i - 1].insert(i);
      adj[i + 1].insert(i);
    }

    // find all prime factors of u
    set<int> st = primeFact[curr];
    for (auto it : st) {
      if (isPresent[it]) {
        for (auto index : indexMap[it]) {
          adj[index].insert(i);
        }
      }
    }
  }

  // Now just do simple BFS to reach from nums[0] to nums[n-1]
  vector<bool> vis(n + 1, false);
  queue<pair<int, int>> que;
  que.push({0, 0});
  vis[0] = true;

  while (!que.empty()) {
    int nodeIndex = que.front().first;
    int steps = que.front().second;
    que.pop();

    if (nodeIndex == n - 1) {
      return steps;
    }

    for (auto it = adj[nodeIndex].rbegin(); it != adj[nodeIndex].rend(); ++it) {
      int childIndex = *it;
      if (!vis[childIndex]) {
        vis[childIndex] = true;
        que.push({childIndex, steps + 1});
      }
    }
  }

  return 0;
}

// HACK: Working -> Alok
void seive(vector<int> &nums, vector<int> &primeInfo,
           map<int, vector<int>> &mp) {

  int maxi = *max_element(nums.begin(), nums.end());
  primeInfo.resize(maxi + 1, 0);
  for (int i = 2; i <= maxi; i++) {
    if (primeInfo[i] == 0)
      for (int j = i; j <= maxi; j += i) {
        primeInfo[j] = i;
      }
  }

  primeInfo[1] = -1;
  for (int i = 0; i < nums.size(); i++) {
    int num = nums[i];
    while (num > 1) {
      int primeNum = primeInfo[num];
      mp[primeNum].push_back(i);
      while (num % primeNum == 0) {
        num /= primeNum;
      }
    }
  }
  return;
}

int minJumps_working(vector<int> &nums) {

  map<int, vector<int>> mp;
  vector<int> primeInfo;
  seive(nums, primeInfo, mp);

  int n = nums.size();
  if (primeInfo[nums[0]] == primeInfo[nums[n - 1]] &&
      primeInfo[nums[0]] == nums[0]) {
    return 1;
  }

  cout << n;
  vector<int> dist(n, -1);
  queue<int> que;
  que.push(0);
  dist[0] = 0;
  vector<int> dir = {-1, 1};
  while (!que.empty()) {
    int ind = que.front();
    if (ind == n - 1)
      return dist[n - 1];
    que.pop();
    for (auto it : dir) {
      int newi = ind + it;
      if (newi >= 0 && newi < n && dist[newi] == -1) {
        dist[newi] = 1 + dist[ind];
        que.push(newi);
      }
    }
    int num = nums[ind];
    if (primeInfo[num] == num) {
      vector<int> arr = mp[num];

      for (int i = 0; i < arr.size(); i++) {
        // if( i == ind) continue;
        int newi = arr[i];
        if (dist[newi] == -1) {
          dist[newi] = 1 + dist[ind];
          que.push(newi);
        }
      }
    }
  }
  return dist[n - 1];
}

int main() {
#ifndef ONLINE_JUDGE
  // freopen("Error.txt", "w", stderr);
  freopen("input.txt", "r", stdin);
#endif
  ratnesh();

  vector<int> nums = {7, 5, 7};
  int ans = minJumps(nums);
  cout << ans << nl;
}
