#include <bits/stdc++.h>
using namespace std;
// Pura Gente del Coach Moy
using i64 = long long;
i64 MOD = 1e9 + 7;
signed main() {
  cin.tie(0)->sync_with_stdio(0);
  int d, n;
  cin >> d >> n;
  vector<int> a(n);
  for (int i = 0; i < n; ++i) {
    cin >> a[i];
  }
  vector<vector<int>> g(n);
  for (int i = 1; i < n; ++i) {
    int u, v;
    cin >> u >> v;
    --u;
    --v;
    g[u].push_back(v);
    g[v].push_back(u);
  }
  vector<bool> vis(n);
  i64 ways = 0;
  for (int root = 0; root < n; ++root) {
    auto dfs = [&](auto self, int u, int p) -> i64 {
      if (a[u] < a[root] || a[u] - a[root] > d || (a[u] == a[root] && vis[u])) {
        return 0;
      }
      i64 w = 1;
      for (int v : g[u]) {
        if (v != p) {
          w = (w * (self(self, v, u) + 1)) % MOD;
        }
      }
      return w;
    };
    ways = (ways + dfs(dfs, root, -1)) % MOD;
    vis[root] = true;
  }
  cout << ways << '\n';
  return 0;
}