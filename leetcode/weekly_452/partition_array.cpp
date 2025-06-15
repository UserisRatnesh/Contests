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

class Solution {
public:
  bool helper(const vector<ll> &nums, int index, vector<ll> &sub1,
              ll remainingTarget, const ll originalTarget) {
    if (index == nums.size()) {
      if (remainingTarget != 1)
        return false;

      ll mainCopy = originalTarget;
      vector<ll> sub2;

      for (auto it : nums) {
        if (find(sub1.begin(), sub1.end(), it) == sub1.end()) {
          if (mainCopy % it != 0)
            return false;
          mainCopy /= it;
          sub2.push_back(it);
        }
      }

      return (sub2.size() > 0 && mainCopy == 1);
    }

    bool include = false;
    if (remainingTarget % nums[index] == 0) {
      sub1.push_back(nums[index]);
      include = helper(nums, index + 1, sub1, remainingTarget / nums[index],
                       originalTarget);
      sub1.pop_back();
    }

    if (include)
      return true;

    return helper(nums, index + 1, sub1, remainingTarget, originalTarget);
  }

  bool checkEqualPartitionsBetter(vector<int> &nums, long long target) {
    vector<ll> sub1;
    vector<ll> longNums(nums.begin(), nums.end());
    return helper(longNums, 0, sub1, target, target);
  }

  // NOTE: More intuitive
  bool checkEqualPartitions(vector<int> &nums, long long target) {
    return helper(0, 1, 1, nums, target);
  }

  bool helper(int index, long long first, long long second, vector<int> &nums,
              long long target) {
    int n = nums.size();

    if (first > target || second > target) {
      return false;
    }

    if (index >= n) {
      return first == target && second == target;
    }

    int ele = nums[index];
    bool pick = false;
    if (first * nums[index] <= target) {
      pick = helper(index + 1, first * ele, second, nums, target);
    }
    bool notPick = helper(index + 1, first, second * ele, nums, target);

    return pick || notPick;
  }
};
