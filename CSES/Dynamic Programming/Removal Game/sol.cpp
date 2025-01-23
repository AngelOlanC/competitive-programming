#include <bits/stdc++.h>
using namespace std;
// Pura Gente del Coach Moy

using i64 = long long;

int a[5000];
i64 dp[5000][5000];

int main() {
  cin.tie(0)->sync_with_stdio(0);

  int n;
  cin >> n;

  for (int i = 0; i < n; ++i) {
    cin >> a[i];
  }

  bool myTurn = n & 1;
  if (myTurn) {
    for (int i = 0; i < n; ++i) {
      dp[i][i] = a[i];
    }
  }
  myTurn = !myTurn;
  for (int len = 2; len <= n; ++len) {
    for (int i = 0; i + len - 1 < n; ++i) {
      if (myTurn) {
        dp[i][i + len - 1] = max(a[i] + dp[i + 1][i + len - 1], a[i + len - 1] + dp[i][i + len - 2]);
      } else {
        dp[i][i + len - 1] = min(dp[i + 1][i + len - 1], dp[i][i + len - 2]);
      }
    }
    myTurn = !myTurn;
  }
  cout << dp[0][n - 1] << '\n';

  return 0;
}