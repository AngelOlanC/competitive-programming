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


int be(int a, int b, int m) {
  int res = 1;
  while (b) {
    if (b & 1) res = 1ll * res * a % m;
    a = 1ll * a * a % m;
    b >>= 1;
  }
  return res;
}

constexpr int maxk = 5e3 + 5, MOD = 1e9 + 7;

signed main() {
  cin.tie(0)->sync_with_stdio(0);

  vector<vi> c(maxk, vi(maxk));
  FOR (i, 0, maxk) {
    c[i][0] = c[i][i] = 1;
    FOR (j, 1, i) c[i][j] = (c[i - 1][j] + c[i - 1][j - 1]) % MOD;
  }

  int n, m, k;
  cin >> n >> m >> k;

  vi dp(k + 1);
  FOR (i, 1, k + 1) {
    dp[i] = be(i, n, MOD);
    FOR (j, 1, i) {
      dp[i] -= 1ll * c[i][j] * dp[j] % MOD;
      if (dp[i] < 0) dp[i] += MOD;
    }
  }

  cout << 1ll * c[m][k] * dp[k] % MOD << ENDL;

  return 0;
}