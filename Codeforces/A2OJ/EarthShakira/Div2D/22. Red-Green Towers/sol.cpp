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

constexpr int MOD = 1e9 + 7;

signed main() {
  cin.tie(0)->sync_with_stdio(0);

  int r, g;
  cin >> r >> g;

  int h = 1;
  while (r + g >= (h + 1) * (h + 2) / 2) {
    h++;
  }

  vi dp(r + 1, 0);
  dp[0] = 1;
  FOR (i, 1, h + 1) {
    ROF (j, r + 1, i) {
      dp[j] += dp[j-i];
      dp[j] %= MOD;
    }
  }
  int ans = 0;
  FOR (i, 0, r + 1) {
    if (i + g >= h * (h + 1) / 2) {
      ans += dp[i];
      ans %= MOD;
    }
  }
  cout << ans << ENDL;

  return 0;
}