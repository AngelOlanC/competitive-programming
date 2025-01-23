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

  int n, s;
  cin >> n >> s;

  if (s % 2 != 0) {
    cout << 0 << ENDL;
    return 0;
  }

  s /= 2;
  ll dp[n + 1][s + 1];
  for (int i = 0; i <= s; i++) {
    dp[n][i] = i == s;
  }
  for (int i = n - 1; i >= 0; i--) {
    for (int j = s; j >= 0; j--) {
      dp[i][j] = 0;
      for (int k = 0; k <= 9 && j + k <= s; k++) {
        dp[i][j] += dp[i + 1][j + k];
      }
    }
  }
  cout << dp[0][0] * dp[0][0] << ENDL;

  return 0;
}