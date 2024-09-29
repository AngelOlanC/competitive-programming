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
  vector<vi> g(n);
  vector<array<int, 3>> e(m);
  FOR (i, 0, m) {
    auto &[u, v, w] = e[i];
    cin >> u >> v >> w;
    --u, --v;
    if (i < n - 1) g[u].pb(i), g[v].pb(i);
  }

  auto maximize = [&](int i, int j) -> int {
    if (i == -1) return j;
    if (j == -1) return i;
    return e[i][2] > e[j][2] ? i : j;
  };

  auto dfs = [&](auto&& self, int u, int p, int V) -> int {
    int mxe = -1;
    for (auto &i : g[u]) {
      int v = e[i][0] != u ? e[i][0] : e[i][1];
      if (v == p) continue;
      if (v == V) {
        mxe = maximize(mxe, i);
        continue;
      }
      int mxv = self(self, v, u, V);
      if (mxv != -1) mxe = maximize(i, mxv);
    }
    return mxe;
  };

  vi p(m);
  iota(ALL(p), 0);
  sort(ALL(p), [&](int i, int j) { return e[i][2] < e[j][2]; });

  vector<pi> ans;
  FOR (k, 0, m) if (p[k] >= n - 1) {
    auto [u, v, w] = e[p[k]];
    int mxe = dfs(dfs, u, -1, v);
    auto [u2, v2, w2] = e[mxe];
    if (w < w2) {
      g[u2].erase(find(ALL(g[u2]), mxe)), g[v2].erase(find(ALL(g[v2]), mxe));
      g[u].pb(p[k]), g[v].pb(p[k]);
      ans.pb({mxe, p[k]});
    }
  }

  cout << SZ(ans) << ENDL;
  for (auto &[x, y] : ans) cout << x + 1 << ' ' << y + 1 << ENDL;

  return 0;
}