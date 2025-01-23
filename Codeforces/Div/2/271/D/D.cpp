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

#define N 100010

constexpr int MOD = 1e9 + 7;

signed main() {
  ios_base::sync_with_stdio(0);
  cin.tie(nullptr);

  int q, k;
  cin >> q >> k;

  int dp[N];
  dp[0] = 1;
  for (int i = 1; i < N; i++) {
    dp[i] = dp[i - 1];
    if (i - k >= 0) {
      dp[i] = (dp[i] + dp[i - k]) % MOD;
    }
  }

  int p[N];
  p[0] = 1;
  FOR (i, 1, N) {
    p[i] = (p[i - 1] + dp[i]) % MOD;
  }

  while (q--) {
    int a, b;
    cin >> a >> b;
    cout << (p[b] - p[a - 1] + MOD) % MOD << ENDL; 
  }

  return 0;
}