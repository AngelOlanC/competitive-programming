#include <bits/stdc++.h>
using namespace std;
// Pura Gente del Coach Moy
using ll = long long;
using pi = pair<int, int>;
using vi = vector<int>;

#define pb push_back
#define SZ(x) ((int)(x).size())
#define ALL(x) begin(x), end(x)
#define FOR(i, a, b) for (int i = (int)a; i < (int)b; ++i)
#define ROF(i, a, b) for (int i = (int)a - 1; i >= (int)b; --i)
#define ENDL '\n'
using i64 = long long;
constexpr i64 INF = 1e12;
signed main() {
  cin.tie(0)->sync_with_stdio(0);
  int t;
  cin >> t;
  while (t--) {
    int n;
    cin >> n;
    vector<vector<int>> a(2, vector<int>(n));
    for (int i = 0; i < 2; ++i) {
      for (int j = 0; j < n; ++j) {
        cin >> a[i][j];
      }
    }
    vector<vector<i64>> dp(2, vector<i64>(n + 1));
    dp[0][n] = -INF;
    dp[1][n] = 0;
    for (int i = n - 1; i >= 0; --i) {
      int mx = max(a[0][i], a[1][i]);
      dp[0][i] = max(dp[0][i + 1] + mx, dp[1][i + 1] + a[0][i] + a[1][i]);
      dp[1][i] = dp[1][i + 1] + mx;
    }
    cout << dp[0][0] << '\n';
  }
  return 0;
}