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
  int n, q;
  cin >> n >> q;
  vector<int> g(n);
  vector<vector<int>> rg(n);
  for (int i = 0; i < n; ++i) {
    cin >> g[i];
    --g[i];
    rg[g[i]].push_back(i);
  }
  vector<vector<pair<int, int>>> Q(n);
  for (int i = 0; i < q; ++i) {
    int u, v;
    cin >> u >> v;
    --u;
    --v;
    Q[u].push_back({v, i});
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
  vector<int> dc(n, -1), dt(n, -1), ans(q);
  for (int root = 0; root < n; ++root) {
    if (vis[root] || !cycle[root]) {
      continue;
    }
    int l = 0, u = root;
    do {
      dc[u] = l;
      ++l;
      u = g[u];
    } while (u != root);
    int c = 0;
    auto dfs = [&](auto &&self, int u) -> void {
      for (auto &[v, i] : Q[u]) {
        if (dc[v] == -1 && dt[v] == -1) {
          ans[i] = -1;
          continue;
        }
        if (cycle[v]) {
          ans[i] = dt[u] + sub(dc[v], c, l);
        } else {
          ans[i] = dt[u] - dt[v];
        }
      }
      for (auto &v : rg[u]) {
        if (!cycle[v]) {
          dt[v] = dt[u] + 1;
          self(self, v);
        }
      }
      dt[u] = -1;
    };
    u = root;
    do {
      dt[u] = 0;
      dfs(dfs, u);
      u = g[u];
      ++c;
    } while (u != root);
    u = root;
    do {
      dc[u] = -1;
      vis[u] = true;
      u = g[u];
    } while (u != root);
  }
  for (int x : ans) {
    cout << x << '\n';
  }
}