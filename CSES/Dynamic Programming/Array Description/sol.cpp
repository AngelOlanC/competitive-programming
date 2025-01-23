#include <bits/stdc++.h>
using namespace std;
// Pura Gente del Coach Moy

constexpr int MOD = 1e9 + 7;

inline int add(int x, int y) {
  return x + y < MOD ? x + y : x + y - MOD;
}

int dp[102][100000];
int x[100000];

int main() {
  cin.tie(0)->sync_with_stdio(0);

  int n, m;
  cin >> n >> m;
  
  for (int i = 0; i < n; ++i) {
    cin >> x[i];
  }

  if (x[0]) {
    dp[x[0]][0] = 1;
  } else {
    for (int i = 1; i <= m; ++i) {
      dp[i][0] = 1;
    }
  }

  for (int i = 1; i < n; ++i) {
    if (x[i]) {
      dp[x[i]][i] = add(dp[x[i]][i - 1], add(dp[x[i] - 1][i - 1], dp[x[i] + 1][i - 1]));
      continue;
    }
    for (int j = 1; j <= m; ++j) {
      dp[j][i] = add(dp[j][i - 1], add(dp[j - 1][i - 1], dp[j + 1][i - 1]));
    }
  }
  
  int ans = 0;
  for (int i = 1; i <= m; ++i) {
    ans = add(ans, dp[i][n - 1]);
  }
  cout << ans << '\n';

  return 0;
}