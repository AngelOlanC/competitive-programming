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

signed main() {
  ios_base::sync_with_stdio(0);
  cin.tie(nullptr);

  int n;
  cin >> n;

  int a[n];
  FOR (i, 0, n) {
    cin >> a[i];
  }

  int dp[n][n];
  ROF (i, n, 0) {
    dp[i][i] = 1e9;
    FOR (j, i + 1, n) {
      dp[i][j] = min({dp[i][j - 1], dp[i + 1][j], abs(a[i] - a[j])});
    }
  }

  int q;
  cin >> q;
  while (q--) {
    int l, r;
    cin >> l >> r;
    cout << dp[l - 1][r - 1] << ENDL;
  }

  return 0;
}