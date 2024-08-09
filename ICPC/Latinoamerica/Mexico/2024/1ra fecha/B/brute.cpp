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

#define N 100

constexpr int MOD = 1e9+7;

signed main() {
  ios_base::sync_with_stdio(0);
  cin.tie(nullptr);

  vi dp(N, 0);
  dp[0] = 1;
  for (int i = 0; i < N; i++) {
    for (int k = 6; i + k < N && k <= 20; k += 4) {
      dp[i + k] = (dp[i + k] + 3ll * dp[i]) % MOD;
    }
    cout << i << " " << dp[i] << ENDL;
  }

  cout << ENDL;

  vi pre(N, 0);
  pre[0] = dp[0];
  FOR (i, 1, N) {
    pre[i] = (pre[i - 1] + dp[i]) % MOD;
    int ans = pre[i];
    if (i >= 20) {
      ans = (ans - pre[i - 20] + MOD) % MOD;
    }
    // cout << i << ' ' << ans << ENDL;
  }

  return 0;
}