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

constexpr int maxn = 200 + 5;

int dp[maxn][maxn][maxn];

void solve(int test_case) {
  int n;
  cin >> n;
  vi a(n);
  FOR (i, 0, n) {
    cin >> a[i];
    --a[i];
    a[i] = i - a[i];
  }

  memset(dp, 0, sizeof dp);

  ROF (l, n, 0) {
    FOR (r, l + 1, n) {
      FOR (k, 0, l + 1) {
        dp[l][r][k] = dp[l + 1][r][k];
        if (a[l] < 0 || a[l] % 2 || a[l] / 2 > k) continue;
        for (int j = l + 1; j <= r; j += 2) {
          int len = j - l - 1; 
          if (dp[l + 1][j - 1][a[l] / 2] * 2 == len) {
            dp[l][r][k] = max(dp[l][r][k], 1 + len / 2 + dp[j + 1][r][k + len / 2 + 1]);
          }
        }
      }
    }
  }
  cout << dp[0][n - 1][0] << ENDL;
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