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
  int n;
  cin >> n;
  vector<vi> g(n);
  FOR (i, 1, n) {
    int u, v;
    cin >> u >> v;
    --u, --v;
    g[u].pb(v), g[v].pb(u);
  }
  vector<vi> d(2, vi(n));
  auto dfs = [&](auto &&self, int u, int p, int k) -> void {
    for (auto &v : g[u]) if (v != p) {
      d[k][v] = d[k][u] + 1;
      self(self, v, u, k);
    }
  };
  dfs(dfs, 0, -1, 0);
  int u = 0;
  FOR (i, 0, n) if (d[0][i] > d[0][u]) u = i;
  d[0][u] = 0;
  dfs(dfs, u, -1, 0);
  int v = 0;
  FOR (i, 0, n) if (d[0][i] > d[0][v]) v = i;
  d[1][v] = 0;
  dfs(dfs, v, -1, 1);
  FOR (i, 0, n) cout << max(d[0][i], d[1][i]) << " \n"[i == n - 1];
  return 0;
}