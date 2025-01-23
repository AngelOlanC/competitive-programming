#include <bits/stdc++.h>
using namespace std;
inline int sub(int x, int y, int m) {
  int ret = x - y;
  if (ret < 0) {
    ret += m;
  }
  return ret;
}
int main() {
  cin.tie(0)->sync_with_stdio(0);
  int n;
  cin >> n;
  vector<int> g(n);
  vector<vector<int>> rg(n);
  for (int i = 0; i < n; ++i) {
    cin >> g[i];
    --g[i];
    rg[g[i]].push_back(i);
  }
  vector<bool> cycle(n);
  {
    vector<int> in_degree(n);
    for (int i = 0; i < n; ++i) {
      ++in_degree[g[i]];
    }
    queue<int> q;
    for (int i = 0; i < n; ++i) {
      if (!in_degree[i]) {
        q.push(i);
      }
    }
    while (!q.empty()) {
      int u = q.front();
      q.pop();
      --in_degree[g[u]];
      if (!in_degree[g[u]]) {
        q.push(g[u]);
      }
    }
    for (int i = 0; i < n; ++i) {
      if (in_degree[i]) {
        cycle[i] = true;
      }
    }
  }
  vector<bool> vis(n);
  vector<int> ans(n);
  for (int root = 0; root < n; ++root) {
    if (vis[root] || !cycle[root]) {
      continue;
    }
    int l = 0, u = root;
    do {
      ++l;
      u = g[u];
    } while (u != root);
    auto dfs = [&](auto &&self, int u, int dt) -> void {
      ans[u] = dt + l;
      for (auto &v : rg[u]) {
        if (!cycle[v]) { 
          self(self, v, dt + 1);
        }
      }
    };
    u = root;
    do {
      dfs(dfs, u, 0);
      u = g[u];
    } while (u != root);
    u = root;
    do {
      vis[u] = true;
      u = g[u];
    } while (u != root);
  }
  for (int x : ans) {
    cout << x << ' ';
  }
  cout << '\n';
}