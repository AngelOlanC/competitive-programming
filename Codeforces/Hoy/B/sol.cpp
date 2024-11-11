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

constexpr ll INF = 4e18;

void solve(int test_case) {
  int n;
  cin >> n;
  vector<ll> a(n);
  FOR (i, 0, n) {
    cin >> a[i];
  }
  vector<vector<ll>> dp(2, vector<ll>(n + 1, INF));
  dp[0][n] = dp[1][n] = 0;
  dp[1][n - 1] = 1;
  for (int i = n - 2; i >= 0; i--) {
    dp[0][i] = max(a[i + 1] - a[i], dp[0][i + 2]);
    dp[1][i] = max(a[i + 1] - a[i], dp[1][i + 2]);
    int j = i + 1;
    while (j < n && a[j] == a[i] + j - i) {
      ++j;
    }
    if (j < n) {
      dp[1][i] = min(dp[1][i], max(j - a[i], dp[0][i + 1]));
    }
    j = i - 1;
    while (j >= 0 && a[j] == a[i] + i - j) {
      --j;
    }
    if (j >= 0) {
     dp[1][i] = min(dp[1][i], max(a[i] - j, dp[0][i + 1]));
    }
  }
  cout << dp[1][0] << ENDL;
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