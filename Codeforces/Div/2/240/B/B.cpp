#include <bits/stdc++.h>
using namespace std;
// Pura Gente del Coach Moy
using ll = long long;
using pi = pair<int, int>;
using vi = vector<int>;

#define fi first
#define se second
#define pb push_back
#define SZ(x) ((int)(x).size())
#define ALL(x) begin(x), end(x)
#define FOR(i, a, b) for (int i = (int)a; i < (int)b; ++i)
#define ROF(i, a, b) for (int i = (int)a - 1; i >= (int)b; --i)
#define ENDL '\n'

constexpr int MOD = 1e9 + 7;

signed main() {
  ios_base::sync_with_stdio(0);
  cin.tie(nullptr);

  int n, m;
  cin >> n >> m;

  int dp[n + 1][m];
  FOR(i, 1, n + 1) {
    dp[i][m - 1] = 1;
  }
  ROF (i, m - 1, 0) {
    FOR (j, 1, n + 1) {
      dp[j][i] = 0;
      for (int k = j; k <= n; k += j) {
        dp[j][i] = (dp[j][i] + dp[k][i + 1]) % MOD;
      }
    }
  }

  int ans = 0;
  FOR (i, 1, n + 1) {
    ans = (ans + dp[i][0]) % MOD;
  }

  cout << ans << ENDL;

  return 0;
}