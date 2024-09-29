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

signed main() {
  cin.tie(0)->sync_with_stdio(0);
  int n, a, b;
  cin >> n  >> a >> b;
  vector<vector<long double>> dp(n + 1, vector<long double>(6 * (n + 1) + 1));
  dp[0][0] = 1;
  for (int i = 1; i <= n; ++i) for (int j = 1; j <= 6 * (i + 1); ++j) for (int k = 1; k <= min(j, 6); ++k) dp[i][j] += dp[i - 1][j - k];
  long double ans = accumulate(dp[n].begin() + a, dp[n].begin() + b + 1, 0.0);
  while (n--) ans /= 6.0;
  cout << setprecision(6) << fixed << ans << ENDL;
  return 0;
}