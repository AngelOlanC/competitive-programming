#include <bits/stdc++.h>
using namespace std;
// Pura Gente del Coach Moy

int dp[1000][100001];
int h[1000];
int s[1000];

int main() {
  cin.tie(0)->sync_with_stdio(0);

  int n, x;
  cin >> n >> x;
  
  for (int i = 0; i < n; ++i) {
    cin >> h[i];
  }
  for (int i = 0; i < n; ++i) {
    cin >> s[i];
  }

  if (h[0] <= x) {
    dp[0][h[0]] = s[0];
  }

  for (int i = 1; i < n; ++i) {
    for (int j = 0; j < h[i]; ++j) {
      dp[i][j] = dp[i - 1][j];
    }
    for (int j = h[i]; j <= x; ++j) {
      dp[i][j] = max(dp[i - 1][j], dp[i - 1][j - h[i]] + s[i]);
    }
  }

  int ans = 0;
  for (int i = 0; i <= x; ++i) {
    ans = max(ans, dp[n - 1][i]);
  }
  cout << ans << '\n';

  return 0;
}