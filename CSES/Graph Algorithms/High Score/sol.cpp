#include <bits/stdc++.h>
using namespace std;
using i64 = long long;
i64 INF = 1e15;
int main() {
  cin.tie(0)->sync_with_stdio(0);
  int n, m;
  cin >> n >> m;
  vector<vector<int>> g(n), rg(n);
  vector<tuple<int, int, int>> e(m);
  for (auto &[u, v, w] : e) {
    cin >> u >> v >> w;
    --u;
    --v;
    w = -w;
    g[u].push_back(v);
    rg[v].push_back(u);
  }
  vector<i64> d(n, INF);
  d[0] = 0;
  for (int i = 1; i < n; ++i) {
    for (auto &[u, v, w] : e) {
      if (d[u] != INF && d[u] + w < d[v]) {
        d[v] = d[u] + w;
      }
    }
  }
  auto dfs = [](auto&& dfs, int u, vector<bool>& vis, const vector<vector<int>>& g) -> void {
    vis[u] = true;
    for (auto &v : g[u]) {
      if (!vis[v]) {
        dfs(dfs, v, vis, g);
      }
    }
  };
  vector<bool> vis_a(n), vis_b(n);
  dfs(dfs, 0, vis_a, g);
  dfs(dfs, n - 1, vis_b, rg);
  for (auto &[u, v, w] : e) {
    if (d[u] != INF && d[u] + w < d[v] && vis_a[u] && vis_b[u]) {
      cout << "-1\n";
      return 0;
    }
  }
  cout << -d.back() << '\n';
}