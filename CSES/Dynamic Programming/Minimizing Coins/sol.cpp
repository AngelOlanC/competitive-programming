#include <bits/stdc++.h>
using namespace std;
// Pura Gente del Coach Moy

int main() {
  cin.tie(0)->sync_with_stdio(0);

  int n, x;
  cin >> n >> x;

  vector<int> c(n);
  for (int& x : c) {
    cin >> x;
  }

  vector<int> dp(x + 1, 1e9);
  dp[0] = 0;
  for (int i = 1; i <= x; ++i) {
    for (int y : c) {
      if (y <= i) {
        dp[i] = min(dp[i], 1 + dp[i - y]);
      }
    }
  }
  if (dp[x] == 1e9) {
    dp[x] = -1;
  }
  cout << dp[x] << '\n';

  return 0;
}