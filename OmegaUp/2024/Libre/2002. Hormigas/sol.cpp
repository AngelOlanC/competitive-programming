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

constexpr int MOD = 1 << 15;

signed main() {
  ios_base::sync_with_stdio(0);
  cin.tie(nullptr);

  int n;
  cin >> n;

  int m[n + 1][n + 1];
  FOR (i, 1, n + 1) {
    FOR (j, 1, n + 1) {
      cin >> m[i][j];
    }
  }

  int dp[n + 1][n + 1];
  memset(dp, 0, sizeof dp);
  dp[0][1] = 1;
  FOR (i, 1, n + 1) {
    FOR (j, 1, n + 1) {
      if (!m[i][j]) {
        dp[i][j] = (dp[i - 1][j] + dp[i][j - 1]) % MOD;
      }
    }
  }

  int dpr[n + 2][n + 2];
  memset(dpr, 0, sizeof dpr);
  dpr[n + 1][n] = 1;
  ROF (i, n + 1, 1) {
    ROF (j, n + 1, 1) {
      if (!m[i][j]) {
        dpr[i][j] = (dpr[i + 1][j] + dpr[i][j + 1]) % MOD;
      }
    }
  }

  int q;
  cin >> q;
  while (q--) {
    int i, j;
    cin >> i >> j;
    i++, j++;
    cout << dp[i][j] * dpr[i][j] % MOD << ENDL;
  }

  return 0;
}