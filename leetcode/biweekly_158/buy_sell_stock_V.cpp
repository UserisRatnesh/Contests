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

// TC : TLE
ll helper(vector<ll> &prices, ll k, ll index, ll price, bool inProcess,
          vector<vector<vector<ll>>> &dp) {
  int n = prices.size();

  if (index >= n || k <= 0) {
    return 0LL;
  }

  if (dp[k][index][inProcess] != -1) {
    return dp[k][index][inProcess];
  }

  ll ans = 0;
  if (inProcess) {

    ll pass = helper(prices, k, index + 1, price, true, dp);
    ll buy =
        price - prices[index] + helper(prices, k - 1, index + 1, 0, false, dp);

    ll sell =
        prices[index] - price + helper(prices, k - 1, index + 1, 0, false, dp);

    ans = max({ans, pass, buy, sell});

  } else {
    ll pass = helper(prices, k, index + 1, 0, false, dp);

    ll buy = helper(prices, k - 1, index + 1, prices[index], true, dp);

    ans = max({ans, pass, buy});
  }

  dp[k][index][inProcess] = ans;

  return ans;
}

long long maximumProfit(vector<int> &prices, int k) {
  int n = prices.size();
  vector<ll> temp(n);
  for (int i = 0; i < n; i++) {
    temp[i] = prices[i];
  }

  k *= 2;
  vector<vector<vector<ll>>> dp(k + 1,
                                vector<vector<ll>>(n + 1, vector<ll>(2, -1)));
  return helper(temp, 2ll * k, 0, 0, 0, dp);
}

// NOTE:
ll solve(const vector<ll> &prices, ll k, ll index, bool bought,
         vector<vector<vector<ll>>> &dp) {
  int n = prices.size();

  // If more than k transactions then not a correct path
  if (k < 0) {
    return -1e9;
  }

  if (index == n) {
    return (k % 2 == 0) ? 0 : -1e9;
  }

  if (dp[k][index][bought] != -1) {
    return dp[k][index][bought];
  }

  ll result = solve(prices, k, index + 1, bought, dp);

  if (k % 2 == 0) {
    ll buy = -prices[index] + solve(prices, k - 1, index + 1, false, dp);
    ll sell = prices[index] + solve(prices, k - 1, index + 1, true, dp);
    result = max({result, buy, sell});

  } else if (bought) {
    ll buy = -prices[index] + solve(prices, k - 1, index + 1, false, dp);
    result = max(result, buy);
  } else {
    ll sell = prices[index] + solve(prices, k - 1, index + 1, true, dp);
    result = max(result, sell);
  }

  return dp[k][index][bought] = result;
}

long long maximumProfitAns(vector<int> &prices, int k) {
  vector<ll> temp(prices.size());
  int n = prices.size();
  for (int i = 0; i < prices.size(); i++)
    temp[i] = prices[i];
  k = k * 2;
  vector<vector<vector<ll>>> dp(k + 1,
                                vector<vector<ll>>(n + 1, vector<ll>(2, -1)));
  return solve(temp, k, 0, 0, dp);
}

int main() {
#ifndef ONLINE_JUDGE
  freopen("Error.txt", "w", stderr);
  freopen("input.txt", "r", stdin);
#endif
  fastio();
}
