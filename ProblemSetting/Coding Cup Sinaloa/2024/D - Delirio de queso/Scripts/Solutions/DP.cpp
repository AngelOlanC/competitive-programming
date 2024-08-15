#include <bits/stdc++.h>
using namespace std;

const int MOD = 1e9 + 7;

int binaryExponenciation(int x, long long k) {
  if (k == 0) {
    return 1;
  }
  int y = binaryExponenciation(x, k / 2);
  y = (long long)y * y % MOD;
  if (k % 2 == 1) {
    y = (long long)y * x % MOD;
  }
  return y;
}

signed main() {
  cin.tie(0)->sync_with_stdio(0);

  int n, m, a, b;
  long long k;
  cin >> n >> m >> k >> a >> b;
  vector<vector<int>> dp(n, vector<int>(m));
  dp[0][0] = 1;
  for (int i = 0; i < n; ++i) {
    for (int j = 0; j < m; ++j) {
      if (i != 0) {
        dp[i][j] += dp[i - 1][j];
      }
      if (j != 0) {
        dp[i][j] += dp[i][j - 1];
      }
      dp[i][j] %= MOD;
    }
  }
  int answer = (long long)dp[a - 1][b - 1] * dp[n - a][m - b] % MOD;
  answer = binaryExponenciation(answer, k);
  cout << answer << '\n';

  return 0;
}