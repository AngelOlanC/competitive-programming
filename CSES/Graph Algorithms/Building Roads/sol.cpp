#include <bits/stdc++.h>
using namespace std;
int main() {
  cin.tie(0)->sync_with_stdio(0);
  int n, m;
  cin >> n >> m;
  vector<vector<int>> g(n);
  for (int i = 0; i < m; ++i) {
    int u, v;
    cin >> u >> v;
    --u;
    --v;
    g[u].push_back(v);
    g[v].push_back(u);
  }
  vector<bool> vis(n);
  auto dfs = [&](auto &&self, int u) -> void {
    vis[u] = true;
    for (auto &v : g[u]) {
      if (!vis[v]) {
        self(self, v);
      }
    }
  };
  vector<int> heads;
  for (int i = 0; i < n; ++i) {
    if (!vis[i]) {
      heads.push_back(i);
      dfs(dfs, i);
    }
  }
  cout << (int)heads.size() - 1 << '\n';
  for (int i = 0; i < (int)heads.size() - 1; ++i) {
    cout << heads[i] + 1 << ' ' << heads[i + 1] + 1 << '\n';
  }
}