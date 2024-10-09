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
  int n, m, k;
  cin >> n >> m >> k;
  vi c(n);
  FOR (i, 0, n) cin >> c[i];
  vector<vi> g(n);
  while (m--) {
    int u, v;
    cin >> u >> v;
    --u, --v;
    g[u].pb(v), g[v].pb(u);
  }
  vector<vector<vi>> d(2, vector<vi>(n, vi(n, 1e9)));
  FOR (i, 0, n) {
    queue<pi> q;
    d[0][i][i] = 0;
    q.push({i, 0});
    while (!q.empty()) {
      auto [u, p] = q.front();
      q.pop();
      for (auto &v : g[u]) {
        int pp = p ^ (c[u] != c[v]);
        if (d[p][i][u] + 1 < d[pp][i][v]) {
          d[pp][i][v] = d[p][i][u] + 1;
          q.push({v, pp});
        }
      }
    }
  }
  int ans = 0;
  FOR (u, 0, n) FOR (v, u, n) FOR (x, 0, k + 1) ans = max(ans, min(d[0][u][v] + x, d[1][u][v] + k - x));
  cout << ans << ENDL;
  return 0;
}