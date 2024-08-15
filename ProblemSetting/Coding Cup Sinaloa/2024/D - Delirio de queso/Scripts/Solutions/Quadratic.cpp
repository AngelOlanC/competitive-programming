#include <bits/stdc++.h>
using namespace std;

const int MOD = 1e9 + 7;

int binaryExponenciation(int x, long long k) {
  if (k == 0) {
    return 1;
  }
  int y = binaryExponenciation(x, k / 2);
  y = (long long)y * y % MOD;
  if (k % 2 == 1) {
    y = (long long)y * x % MOD;
  }
  return y;
}

signed main() {
  cin.tie(0)->sync_with_stdio(0);

  int n, m, a, b;
  long long k;
  cin >> n >> m >> k >> a >> b;

  vector<vector<int>> combinations(n + m + 1, vector<int>(n + 1));
  for (int i = 0; i <= n + m; i++) {
    combinations[i][0] = 1;
    if (i <= n) {
      combinations[i][i] = 1;
    }
    for (int j = 1; j < min(i, n); j++) {
      combinations[i][j] = (combinations[i - 1][j] + combinations[i - 1][j - 1]) % MOD;
    }
  }

  int startToCheese = combinations[a + b - 2][a - 1];
  int cheeseToEnd = combinations[n - a + m - b][n - a];
  int answerSingleCase = (long long)startToCheese * cheeseToEnd % MOD;
  int answer = binaryExponenciation(answerSingleCase, k);

  cout << answer << '\n';

  return 0;
}