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

constexpr int MOD = 1e8;

#define N 105

int n1, n2, k1, k2;
int dp[N][N][2][15];

int solve(int c1, int c2, int t, int cs) {
  if (min(c1, c2) < 0 || (!t && cs > k1) || (t && cs > k2)) {
    return 0;
  }

  if (max(c1, c2) == 0) {
    return 1;
  }

  int &ans = dp[c1][c2][t][cs];
  if (~ans) {
    return ans;
  }

  if (!t) {
    ans = solve(c1 - 1, c2, t, cs + 1);
    ans = (ans + solve(c1, c2 - 1, !t, 1)) % MOD;
    return ans;
  }
  ans = solve(c1, c2 - 1, t, cs + 1);
  return ans = (ans + solve(c1 - 1, c2, !t, 1)) % MOD;
}

signed main() {
  ios_base::sync_with_stdio(0);
  cin.tie(nullptr);

  memset(dp, -1, sizeof dp);

  cin >> n1 >> n2 >> k1 >> k2;
  
  int ans = solve(n1, n2, 0, 0);
  cout << ans << ENDL;

  return 0;
}