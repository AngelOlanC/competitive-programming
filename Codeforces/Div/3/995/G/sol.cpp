#include <bits/stdc++.h>
using namespace std;
// Pura Gente del Coach Moy

constexpr int INF = 1e9;

int main() {
  cin.tie(0)->sync_with_stdio(0);

  int n, q;
  cin >> n >> q;

  vector<vector<int>> min_separation(n, vector<int>(n, 1));
  vector<int> inc(n), dec(n);
  while (q--) {
    int i;
    char op;
    cin >> i >> op;
    --i;
    if (op == '-') {
      ++dec[i];
      continue;
    }
    ++inc[i];
    for (int j = 0; j < n; ++j) {
      min_separation[i][j] = max(min_separation[i][j], 1 + inc[i] - dec[j]);
    }
  }

  vector<vector<int>> dp(n, vector<int>(1 << n, INF));
  for (int i = 0; i < n; ++i) {
    dp[i].back() = inc[i];
  }
  for (int mask = (1 << n) - 2; mask; --mask) {
    for (int prefix_mask = mask; prefix_mask; prefix_mask &= prefix_mask - 1) {
      int i = __builtin_ctz(prefix_mask);
      for (int prefix_free = (1 << n) - 1 - mask; prefix_free; prefix_free &= prefix_free - 1) {
        int j = __builtin_ctz(prefix_free);
        dp[i][mask] = min(dp[i][mask], min_separation[i][j] + dp[j][mask | (1 << j)]);
      }
    }
  }

  int ans = INF;
  for (int i = 0; i < n; ++i) {
    ans = min(ans, dp[i][1 << i]);
  }
  cout << ans + 1 << '\n';

  return 0;
}