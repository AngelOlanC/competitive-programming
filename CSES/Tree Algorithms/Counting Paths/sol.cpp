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
  int n, p;
  cin >> n >> p;
  vector<vi> g(n);
  FOR (i, 1, n) {
    int u, v;
    cin >> u >> v;
    --u, --v;
    g[u].pb(v), g[v].pb(u);
  }
  vi d(n), par(n);
  vector<vi> jmp(n, vi(25));
  auto dfs_jmp = [&](auto &&self, int u, int p) -> void {
    jmp[u][0] = par[u] = p;
    for (int i = 1; i < 25; ++i) jmp[u][i] = jmp[jmp[u][i-1]][i-1];
    for (auto &v : g[u]) if (v != p) d[v] = d[u] + 1, self(self, v, u);
  };
  dfs_jmp(dfs_jmp, 0, 0);
  auto lca = [&](int u, int v) -> int {
    if (d[u] < d[v]) swap(u, v);
    int df = d[u] - d[v];
    for (int i = 0; i < 25; ++i) if ((df >> i) & 1) u = jmp[u][i];
    if (u == v) return u;
    for (int i = 24; i >= 0; --i) if (jmp[u][i] != jmp[v][i]) u = jmp[u][i], v = jmp[v][i];
    return jmp[u][0];
  };
  vi ans(n);
  FOR (i, 0, p) {
    int u, v;
    cin >> u >> v;
    --u, --v;
    int l = lca(u, v);
    ans[u]++, ans[v]++, ans[l]--;
    if (l) ans[par[l]]--;
  }
  auto dfs_ans = [&](auto &&self, int u, int p) -> void {
    for (auto &v : g[u]) if (v != p) self(self, v, u), ans[u] += ans[v];
  };
  dfs_ans(dfs_ans, 0, -1);
  FOR (i, 0, n) cout << ans[i] << " \n"[i == n - 1];
  return 0;
}