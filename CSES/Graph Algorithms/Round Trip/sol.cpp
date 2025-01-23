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
  vector<int> ans;
  auto dfs = [&](auto &&dfs, int u, int p) -> int {
    vis[u] = true;
    for (auto &v : g[u]) {
      if (v == p) {
        continue;
      }
      if (vis[v]) {
        ans.push_back(v);
        ans.push_back(u);
        return 1;
      }
      int x = dfs(dfs, v, u); 
      if (x == 1) {
        ans.push_back(u);
        return u != ans[0];
      }
      if (x == 0) {
        return 0;
      }
    }
    return -1;
  };
  for (int i = 0; i < n; ++i) {
    if (!vis[i] && dfs(dfs, i, -1) != -1) {
      break;
    }
  }
  if (ans.empty()) {
    cout << "IMPOSSIBLE\n";
    return 0;
  }
  cout << (int)ans.size() << '\n';
  for (int x : ans) {
    cout << x + 1 << ' ';
  }
  cout << '\n';
}