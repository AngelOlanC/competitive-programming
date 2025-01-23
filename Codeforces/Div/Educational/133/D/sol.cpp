#include <bits/stdc++.h>
using namespace std;
// Pura Gente del Coach Moy

constexpr int MOD = 998244353;

inline int add(int x, int y) {
  return x + y < MOD ? x + y : x + y - MOD;
}

int main() {
  cin.tie(0)->sync_with_stdio(0);

  int n, k;
  cin >> n >> k;

  vector<int> dp(n + 1);
  dp[0] = 1;
  for (int i = k; i <= n; ++i) {
    dp[i] = dp[i - k];
  }
  dp[0] = 0;

  vector<int> prev(dp.begin(), dp.end()), ans(dp.begin(), dp.end());
  for (int i = 1; i < 1000; ++i) {
    for (int j = 0; j < k + i && j <= n; ++j) {
      dp[j] = 0;
    }
    for (int j = k + i; j <= n; ++j) {
      dp[j] = add(prev[j - (k + i)], dp[j - (k + i)]);
    }
    for (int j = 1; j <= n; ++j) {
      ans[j] = add(ans[j], dp[j]);
      prev[j] = dp[j];
    }
  }

  for (int i = 1; i <= n; ++i) {
    cout << ans[i] << " \n"[i == n];
  }

  return 0;
}