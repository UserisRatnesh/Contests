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

int maxFreeTime(int eventTime, vector<int> &startTime, vector<int> &endTime) {
  ll n = startTime.size();

  vector<ll> gaps;
  gaps.pb(startTime[0]);

  for (ll i = 1; i < n; i++) {
    ll gap = startTime[i] - endTime[i - 1];
    gaps.pb(gap);
  }
  gaps.pb(eventTime - endTime[n - 1]);

  vector<ll> prefMax(n + 1);
  vector<ll> suffMax(n + 1);

  prefMax[0] = gaps[0];
  for (int i = 1; i <= n; i++) {
    prefMax[i] = max(prefMax[i - 1], gaps[i]);
  }

  suffMax[n] = gaps[n];
  for (int i = n - 1; i >= 0; i--) {
    suffMax[i] = max(suffMax[i + 1], gaps[i]);
  }

  ll ans = LLONG_MIN;

  // Go to each meeting and find what if this one is rescheduled
  for (ll i = 0; i < n; i++) {
    ll meetingLen = endTime[i] - startTime[i];
    ll maxGap = gaps[i] + gaps[i + 1];
    if ((i - 1 >= 0 && prefMax[i - 1] >= meetingLen) ||
        (i + 2 <= n && suffMax[i + 2] >= meetingLen)) {
      maxGap += meetingLen;
    }

    ans = max(ans, maxGap);
  }

  return ans;
}

int main() {
#ifndef ONLINE_JUDGE
  freopen("Error.txt", "w", stderr);
#endif
  fastio();
}
