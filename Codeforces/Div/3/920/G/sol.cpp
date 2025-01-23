#include <bits/stdc++.h>
using namespace std;
// Pura Gente del Coach Moy

int f(vector<vector<bool>>& a, int k) {
  int n = int(a.size()), m = int(a[0].size());

  vector<vector<int>> diag(n, vector<int>(m)), col(n, vector<int>(m));
  for (int i = 0; i < n; ++i) {
    for (int j = m - 1; j >= 0; --j) {
      diag[i][j] = col[i][j] = int(a[i][j]);
      if (i) {
        col[i][j] += col[i - 1][j];
        if (j + 1 < m) {
          diag[i][j] += diag[i - 1][j + 1];
        }
      }
    }
  }

  int ret = 0;
  vector<vector<int>> dp(n, vector<int>(m));
  for (int i = 0; i < n; ++i) {
    for (int j = 0; j < m; ++j) {
      dp[i][j] = col[i][j];
      if (i >= k) {
        dp[i][j] -= col[i - k][j];
      }
      if (j) {
        dp[i][j] += dp[i][j - 1];
      }
      if (j >= k) {
        dp[i][j] -= diag[i][j - k];
      } else {
        int x = j - k + i;
        if (x >= 0) {
          dp[i][j] -= diag[x][0];
        }
      }
      if (i >= k) {
        dp[i][j] += diag[i - k][j];
      }
      ret = max(ret, dp[i][j]);
    }
  }
  return ret;
}

void solve() {
  int n, m, k;
  cin >> n >> m >> k;

  ++k;

  vector<vector<bool>> a(n, vector<bool>(m));
  for (int i = 0; i < n; ++i) {
    for (int j = 0; j < m; ++j) {
      char c;
      cin >> c;
      a[i][j] = c == '#';
    }
  }

  int ans = 0;
  for (int rot = 0; rot < 4; ++rot) {
    ans = max(ans, f(a, k));

    vector<vector<bool>> b(m, vector<bool>(n));
    for (int i = 0; i < n; ++i) {
      for (int j = 0; j < m; ++j) {
        b[j][n - i - 1] = a[i][j];
      }
    }
    swap(n, m);
    a.swap(b);
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