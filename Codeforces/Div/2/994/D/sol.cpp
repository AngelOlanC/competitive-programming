#include <bits/stdc++.h>
using namespace std;
// Pura Gente del Coach Moy

using i64 = long long;

constexpr i64 INF = 1e18;

void solve() {
  int n, m, k;
  cin >> n >> m >> k;

  vector<vector<int>> a(n, vector<int>(m));
  for (int i = 0; i < n; ++i) {
    for (int j = 0; j < m; ++j) {
      cin >> a[i][j];
    }
  }

  auto shifted = [&a, m](int i, int j, int r) -> int {
    return a[i][(j + r) % m];
  };

  vector<vector<i64>> dp(m, vector<i64>(m));
  vector<i64> mn(m, INF);
  mn[m - 1] = 0;
  for (int i = n - 1; i >= 0; --i) {
    vector<i64> mn2(m, INF);
    vector<vector<i64>> dp2(m, vector<i64>(m, INF));
    for (int j = m - 1; j >= 0; j--) {
      for (int r = 0; r < m; ++r) {
        i64 aux = mn[j];
        if (j != m - 1) {
          aux = min(aux, dp2[j + 1][r]);
        }
        dp2[j][r] = shifted(i, j, r) + aux;
        mn2[j] = min(mn2[j], (i64)r * k + dp2[j][r]);
      }
    }
    dp.swap(dp2);
    mn.swap(mn2);
  }
  cout << mn[0] << '\n';
}

signed main() {
  cin.tie(0)->sync_with_stdio(0);

  int t;
  cin >> t;
  while (t--) {
    solve();
  }

  return 0;
}