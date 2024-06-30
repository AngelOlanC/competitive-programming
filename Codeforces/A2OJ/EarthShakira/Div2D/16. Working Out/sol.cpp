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

#define N 1010

ll dp[N][N][4], a[N][N];

signed main() {
  ios_base::sync_with_stdio(0);
  cin.tie(nullptr);

  int n, m;
  cin >> n >> m;

  FOR (i, 1, n + 1) {
    FOR (j, 1, m + 1) {
      cin >> a[i][j];
    }
  }

  FOR (i, 1, n + 1) {
    FOR (j, 1, m + 1) {
      dp[i][j][0] = a[i][j] + max(dp[i - 1][j][0], dp[i][j - 1][0]);
    }
  }

  FOR (i, 1, n + 1) {
    ROF (j, m + 1, 1) {
      dp[i][j][1] = a[i][j] + max(dp[i - 1][j][1], dp[i][j + 1][1]);
    }
  } 

  ROF (i, n + 1, 1) {
    FOR (j, 1, m + 1) {
      dp[i][j][2] = a[i][j] + max(dp[i + 1][j][2], dp[i][j - 1][2]);
    }
  } 

  ROF (i, n + 1, 1) {
    ROF (j, m + 1, 1) {
      dp[i][j][3] = a[i][j] + max(dp[i + 1][j][3], dp[i][j + 1][3]);
    }
  } 

  ll ans = 0;
  FOR (i, 2, n) {
    FOR (j, 2, m) {
      ll aa = dp[i-1][j][0] + dp[i][j+1][1] + dp[i+1][j][3] + dp[i][j-1][2];
      ll bb = dp[i-1][j][1] + dp[i][j+1][3] + dp[i+1][j][2] + dp[i][j-1][0];
      ans = max({ans, aa, bb});    
    }
  }
  cout << ans << ENDL;

  return 0;
}