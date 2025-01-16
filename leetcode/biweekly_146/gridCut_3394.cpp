#include <iostream>
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

bool checkValidCuts(int n, vector<vector<int>> &rectangles) {
  int len = rectangles.size();
  vector<pair<int, int>> yaxis(len); // judge horizontal split
  vector<pair<int, int>> xaxis(len); // judge vertical split

  for (int i = 0; i < len; i++) {
    vector<int> vec = rectangles[i];
    int sx = vec[0];
    int sy = vec[1];
    int ex = vec[2];
    int ey = vec[3];

    yaxis[i] = {sy, ey};
    xaxis[i] = {sx, ex};
  }
  // sort the yaxis based on first element of the pair
  sort(yaxis.begin(), yaxis.end());
  sort(xaxis.begin(), xaxis.end());

  for (pair<int, int> p : yaxis) {
    cout << "This is p " << p.first << p.second << endl;
  }

  int startY = yaxis[0].first;
  int endY = yaxis[0].second;
  int hsplit = 0;
  for (int i = 1; i < yaxis.size(); i++) {
    int sy = yaxis[i].first;
    int ey = yaxis[i].second;
    if (sy >= endY) {
      // Do the needfull
      cout << "increamented by one " << i << endl;
      hsplit++;
      startY = sy;
      endY = ey;
    } else {
      endY = max(ey, endY);
    }
    if (hsplit == 2) {
      cout << "hsplit " << i << endl;
      return true;
    }
  }

  int startX = xaxis[0].first;
  int endX = xaxis[0].second;
  int vsplit = 0;
  for (int i = 1; i < xaxis.size(); i++) {
    int sx = xaxis[i].first;
    int ex = xaxis[i].second;
    if (sx >= endX) {
      // Do the needfull
      vsplit++;
      startX = sx;
      endX = ex;
    } else {
      endX = max(ex, endX);
    }
    if (vsplit == 2) {
      cout << "vsplit " << i << endl;
      return true;
    }
  }

  return false;
}
int main() {
  fastio(); // To enable fast IO.
}
