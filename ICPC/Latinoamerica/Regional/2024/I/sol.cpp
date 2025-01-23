#include <bits/stdc++.h>
using namespace std;
// Pura Gente del Coach Moy
using i64 = long long;
using i128 = __int128_t;
int main() {
  cin.tie(0)->sync_with_stdio(0);
  int n;
  i64 k;
  cin >> n >> k;
  vector<vector<i128>> dp(n + 1, vector<i128>(200));
  for (int i = 0; i < n; ++i) {
    dp[i][0] = 1;
  }
  i128 acum = 1;
  int j = 1;
  while (acum < k) {
    for (int i = 1; i <= n; ++i) {
      for (int p = 1; p <= min(i, j + 1); ++p) {
        dp[i][j] += dp[i - 1][j - p + 1];
      }
    }
    acum += dp[n][j];
    ++j;
  }
  --j;
  set<int> nums;
  for (int i = 1; i <= n; ++i) {
    nums.insert(i);
  }
  i128 cnt = acum - dp[n][j];
  for (int i = n; i >= 1; --i) {
    auto it = nums.begin();
    for (int p = 1; p <= min(i, j + 1); ++p, ++it) {
      if (cnt + dp[i - 1][j - p + 1] < k) {
        cnt += dp[i - 1][j - p + 1];
        continue;
      }
      cout << *it << ' ';
      nums.erase(it);
      j -= p - 1;
      break;
    }
  }
  cout << '\n';
}