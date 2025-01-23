#include <bits/stdc++.h>
using namespace std;

using ll = long long;
using pi = pair<int, int>;
using vi = vector<int>;

#define pb push_back
#define SZ(x) ((int)(x).size())
#define ALL(x) begin(x), end(x)
#define FOR(i, a, b) for (int i = (int)a; i < (int)b; ++i)
#define ROF(i, a, b) for (int i = (int)a - 1; i >= (int)b; --i)
#define ENDL '\n'

void solve(int test_case) {
  int n;
  cin >> n;
  vi cnt(n, 0);
  FOR (i, 0, n) {
    int ai;
    cin >> ai;
    cnt[ai - 1]++;
  }
  int ap = 0;
  FOR (i, 0, n) {
    ap += !!cnt[i];
  }
  vector<vi> dp(n + 1, vi(n, 0));
  ROF (i, n, 0) {
    FOR (j, 0, n) {
      if (i + 1 < n) {
        dp[i][j] = dp[i + 1][j];
      }
      if (!cnt[i]) {
        continue;
      }
      if (j + 1 < n) {
        dp[i][j] = max(dp[i][j], dp[i + 1][j + 1]);
      }
      if (j - cnt[i] >= 0) {
        dp[i][j] = max(dp[i][j], 1 + dp[i + 1][j - cnt[i]]);
      }
    }
  }
  cout << ap - dp[0][0] << ENDL;
}

signed main() {
  cin.tie(0)->sync_with_stdio(0);

  int tc;
  cin >> tc;
  FOR (test_case, 0, tc) {
    solve(test_case + 1);
  }

  return 0;
}