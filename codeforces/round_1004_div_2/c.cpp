#ifndef ONLINE_JUDGE
#include "/usr/local/include/bits/stdc++.h"
#else
#include <bits/stdc++.h>
#endif

using namespace std;

#define fastio()                    \
  ios_base::sync_with_stdio(false); \
  cin.tie(NULL);                    \
  cout.tie(NULL)
#define MOD 1000000007
#define MOD1 998244353
#define INF 1e18
#define nline "\n"
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
#define debug(x)     \
  cerr << #x << " "; \
  _print(x);         \
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

// NOTE: Brute force kind of approach
bool helper(ll sum) {
  while (sum) {
    if (sum % 10 == 7) {
      return true;
    }
    sum = sum / 10;
  }
  return false;
}

void solve() {
  ll n;
  cin >> n;

  ll ans = 10;
  for (ll i = 9; i <= 10e9; i = i * 10 + 9) {
    ll sum = n;

    ll count = 0;

    // Keep adding i till it does not have 7 as one of the digit
    while (!helper(sum)) {
      sum += i;
      count++;
    }

    ans = min(ans, count);
  }

  cout << ans << nline;
}

// NOTE: Mathematical deduction approach
void solveBetter() {
  ll n;
  cin >> n;

  // If already has a seven as digit
  ll tempN = n;
  while (tempN) {
    if (tempN % 10 == 7) {
      cout << 0 << endl;
      return;
    }
    tempN /= 10;
  }

  ll ans = 9;
  // Maximum possible ans can be 9
  for (ll k = 1; k <= 9; k++) {
    ll num = n - k;

    ll tempAns = 7;
    while (num) {
      ll digit = num % 10;
      tempAns = min(tempAns, (7 - digit + 10) % 10);
      num /= 10;
    }
    if (tempAns <= k) {
      ans = min(ans, k);
    }
  }

  cout << ans << endl;
}

int main() {
#ifndef ONLINE_JUDGE
  freopen("Error.txt", "w", stderr);
  freopen("input.txt", "r", stdin);
  freopen("output.txt", "w", stdout);
#endif
  fastio();
  ll t;
  cin >> t;
  while (t--) {
    solveBetter();
  }
}