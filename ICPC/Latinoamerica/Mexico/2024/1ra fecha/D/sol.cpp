#include <bits/stdc++.h>
using namespace std;
constexpr int MOD = 1e9 + 7;
inline int add(int x, int y) {
  int ret = x + y;
  if (ret >= MOD) {
    ret -= MOD;
  }
  return ret;
}
inline int sub(int x, int y) {
  int ret = x - y;
  if (ret < 0) {
    ret += MOD;
  }
  return ret;
}
int main() {
  cin.tie(0)->sync_with_stdio(0);

  int n;
  cin >> n;

  vector<vector<int>> dp(4, vector<int>(n + 1));
  for (int j = 0; j <= n; ++j) {
    dp[0][j] = 1;
  }
  for (int i = 1; i <= 3; ++i) {
    for (int j = 0; j <= n; ++j) {
      dp[i][j] = add(dp[i][j], dp[i - 1][j]);
      if (j >= i) {
        dp[i][j] = add(dp[i][j], dp[i][j - i]);
      }
    }
  }
  int ans = dp[3][n];
  for (int c = 0; c <= n; ++c) {
    ans = sub(ans, dp[2][min(c, n - c)]);
  }
  cout << ans << '\n';
}