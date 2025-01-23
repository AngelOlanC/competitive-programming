#include <bits/stdc++.h>
using namespace std;
// Pura Gente del Coach Moy

int main() {
  cin.tie(0)->sync_with_stdio(0);

  int n;
  cin >> n;

  string s;
  for (int i = 0; i < n; ++i) {
    char c;
    cin >> c;
    if (s.empty() || c != s.back()) {
      s += c;
    }
  }
  n = (int)s.size();

  vector<vector<int>> dp(n + 1, vector<int>(n + 1));
  for (int len = 1; len <= n; ++len) {
    for (int i = 0, j = len - 1; j < n; ++i, ++j) {
      dp[i][j] = 1 + dp[i + 1][j];
      for (int k = i + 1; k <= j; ++k) {
        if (s[i] == s[k]) {
          dp[i][j] = min(dp[i][j], dp[i + 1][k - 1] + dp[k][j]);
        }
      }
    }
  }
  cout << dp[0][n - 1] << '\n';

  return 0;
}