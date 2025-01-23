#include <bits/stdc++.h>
using namespace std;
// Pura Gente del Coach Moy

constexpr int MOD = 998244353;

inline int add(int x, int y) {
  return x + y < MOD ? x + y : x + y - MOD;
}

void solve() {
  int n, k;
  cin >> n >> k;

  vector<vector<int>> dp(n + 1, vector<int>(n + 1));
  for (int i = 0; i <= n; ++i) {
    dp[0][i] = 1;
  }
  for (int i = 1; i <= n; ++i) {
    for (int j = 0; j <= n; ++j) {
      for (int z = 0; j + z + 1 <= k && (j + 1) * (z + 1) <= i; ++z) {
        dp[i][j] = add(dp[i][j], dp[i - (j + 1) * (z + 1)][z]);
      }
    }
  }

  int ans = 0;
  for (int i = 0; i <= n; ++i) {
    ans = add(ans, dp[n][i]);
  }
  cout << ans << '\n';
}

int main() {
  cin.tie(0)->sync_with_stdio(0);

  int t;
  cin >> t;
  while (t--) {
    solve();
  }

  return 0;
}