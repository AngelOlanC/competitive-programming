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

using ld = long double;

signed main() {
  cin.tie(0)->sync_with_stdio(0);

  int n, m, h;
  cin >> n >> m >> h;
  h--;
  int p = 0;
  vi s(m);
  FOR (i, 0, m) {
    cin >> s[i];
    p += s[i];
  }

  if (p < n) {
    cout << -1 << ENDL;
    return 0;
  }

  vector<vector<ld>> c(100005, vector<ld>(105));
  c[0][0] = 1;
  FOR (i, 1, 100005) {
    c[i][0] = 1;
    if (i < 105) c[i][i] = 1;
    FOR (j, 1, min(105, i)) c[i][j] = c[i - 1][j] + c[i - 1][j - 1];
  }

  ld up = 0, down = c[p - 1][n - 1];
  FOR (i, 1, min(s[h], n)) {
    // cout << "with " << i << ' ' << c[s[h] - 1][i] * c[p - s[h]][n - i - 1] << ENDL;
    up += c[s[h] - 1][i] * c[p - s[h]][n - i - 1];
  }
  ld res = up / down;
  cout << setprecision(12) << fixed << res << ENDL;

  return 0;
}