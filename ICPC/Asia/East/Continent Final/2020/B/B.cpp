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

signed main() {
  cin.tie(0)->sync_with_stdio(0);

  int n, m;
  cin >> n >> m;

  ll ans = 1ll * n * (n + 1) / 2 * m * (m + 1) / 2;

  vector<vi> up(n, vi(m)), down(n, vi(m));
  FOR (i, 0, n) FOR (j, 0, m) up[i][j] = -1, down[i][j] = n;

  vector<vi> off(n, vi(m));

  FOR (k, 0, n * m) {
    int i, j;
    cin >> i >> j;
  
    --i, --j;

    for (int l = j, ul = up[i][l] + 1, dl = down[i][l] - 1; l >= 0 && !off[i][l]; --l) {
      ul = max(ul, up[i][l] + 1), dl = min(dl, down[i][l] - 1);
      for (int r = j, u = ul, d = dl; r < m && !off[i][r]; ++r) {
        u = max(u, up[i][r] + 1), d = min(d, down[i][r] - 1);
        ans -= 1ll * (i - u + 1) * (d - i + 1);
      }
    }

    off[i][j] = 1;

    cout << ans << ENDL;

    for (int ii = i + 1; ii < n && !off[ii][j]; ++ii) up[ii][j] = i;
    for (int ii = i - 1; ii >= 0 && !off[ii][j]; --ii) down[ii][j] = i;
  }

  return 0;
}