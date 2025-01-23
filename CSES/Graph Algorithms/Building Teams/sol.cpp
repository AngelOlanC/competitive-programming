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
  vector<int> color(n, -1);
  auto dfs = [&](auto &&self, int u) -> bool {
    for (auto &v : g[u]) {
      if (color[u] == color[v]) {
        return false;
      }
      if (color[v] == -1) {
        color[v] = color[u] ^ 1;
        if (!self(self, v)) {
          return false;
        }
      }
    }
    return true;
  };
  for (int i = 0; i < n; ++i) {
    if (color[i] == -1) {
      color[i] = 0;
      if (!dfs(dfs, i)) {
        cout << "IMPOSSIBLE\n";
        return 0;
      }
    }
  }
  for (int i = 0; i < n; ++i) {
    cout << color[i] + 1 << " \n"[i == n - 1];
  }
}