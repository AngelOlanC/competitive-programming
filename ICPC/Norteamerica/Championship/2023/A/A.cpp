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
constexpr int maxs = 5e6 + 5;
signed main() {
  cin.tie(0)->sync_with_stdio(0);
  int n;
  cin >> n;
  vi a(n), b(n);
  FOR (i, 0, n) cin >> a[i] >> b[i];
  vi dp(maxs, 1e9);
  dp[0] = 0;
  FOR (i, 0, n) {
    ROF (j, maxs, 0) {
      int add = j - a[i] >= 0 ? dp[j - a[i]] : 1e9;
      dp[j] = min(add, b[i] + dp[j]);
    }
  }
  int ans = 1e9;
  FOR (i, 0, maxs) ans = min(ans, max(i, dp[i]));
  cout << ans << ENDL;
  return 0;
}