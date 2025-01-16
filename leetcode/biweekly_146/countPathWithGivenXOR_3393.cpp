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

int countPathsWithXorValue(vector<vector<int>> &grid, int k) {

  int rows = grid.size();
  int cols = grid[0].size();

  int dp[300][300][16] = {0};
  dp[0][0][grid[0][0]] = 1;

  for (int i = 0; i < rows; i++) {
    for (int j = 0; j < cols; j++) {
      if (i == 0 && j == 0) {
        continue; // Start
      }
      for (int x = 0; x < 16; x++) {
        if (i != 0) {
          // can add values from upper cell
          dp[i][j][grid[i][j] ^ x] += dp[i - 1][j][x];
        }

        if (j != 0) {
          // can add values from left
          dp[i][j][grid[i][j] ^ x] += dp[i][j - 1][x];
        }

        dp[i][j][grid[i][j] ^ x] %= MOD;
      }
    }
  }

  return dp[rows - 1][cols - 1][k];
}

int main() {
  fastio(); // To enable fast IO.
}
