#include <bits/stdc++.h>
using namespace std;
// Pura Gente del Coach Moy

constexpr int MOD = 1e9 + 7;

inline int add(int x, int y) {
  return x + y < MOD ? x + y : x + y - MOD;
}

int main() {
  cin.tie(0)->sync_with_stdio(0);

  int n, x;
  cin >> n >> x;

  vector<int> c(n);
  for (int& x : c) {
    cin >> x;
  }

  vector<vector<int>> dp(n, vector<int>(x + 1));
  for (int i = 0; i < n; ++i) {
    dp[i][0] = 1;
  }
  for (int i = 1; i <= x; ++i) {
    for (int j = 0; j < n; ++j) {
      if (c[j] <= i) {
        dp[j][i] = dp[j][i - c[j]];
      }
      if (j) {
        dp[j][i] = add(dp[j][i], dp[j - 1][i]);
      }
    }
  }
  cout << dp[n - 1][x] << '\n';

  return 0;
}