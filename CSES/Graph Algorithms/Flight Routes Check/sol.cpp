#include <bits/stdc++.h>
using namespace std;
int main() {
  cin.tie(0)->sync_with_stdio(0);
  int n, m;
  cin >> n >> m;
  vector<vector<int>> g(n), rg(n);
  for (int i = 0; i < m; ++i) {
    int u, v;
    cin >> u >> v;
    --u;
    --v;
    g[u].push_back(v);
    rg[v].push_back(u);
  }
  vector<bool> vis(n);
  vector<int> lo(n, 1e9);
  auto dfs = [&](auto &&self, int u, int d) -> void {
    vis[u] = true;
    lo[u] = d;
    for (auto &v : g[u]) {
      if (!vis[u]) {
        self(self, v, d + 1);
      }
      lo[u] = min(lo[u], lo[v]);
    }
    for (auto &v : rg[u]) {
      lo[v] = min(lo[u], lo[v]);
    }
  };
  dfs(dfs, 0, 0);
  for (int i = 0; i < n; ++i) {
    vis[i] = false;
  }
  auto dfs2 = [&](auto &&self, int u) -> int {
    vis[u] = true;
    for (auto &v : g[u]) {
      if (!vis[v]) {
        lo[u] = min(lo[u], self(self, v));
      }
    }
    return lo[u];
  };
  dfs2(dfs2, 0);
  for (int i = 0; i < n; ++i) {
    if (lo[i]) {
      cout << "NO\n";
      cout << i + 1 << ' ' << 1 << '\n';
      return 0;
    }
  }
  cout << "YES" << '\n';
}