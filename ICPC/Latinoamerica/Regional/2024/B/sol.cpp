#include <bits/stdc++.h>
using namespace std;

void dfs(int u, vector<vector<pair<int, int>>>& g, vector<int>& depth, vector<pair<int, int>>& par) {
  for (auto &[v, k]: g[u]) {
    if (depth[v] == -1) {
      depth[v] = depth[u] + 1;
      par[v] = {u, k};
      dfs(v, g, depth, par);
    }
  }
}

int f(int u, int v, vector<int>& depth) {
  return min(depth[u], depth[v]);
}

int main() {
  cin.tie(0)->sync_with_stdio(0);
  
  int n, m;
  cin >> n >> m;
  vector<vector<pair<int, int>>> g(n);
  for (int i = 1; i <= m; ++i) {
    int u, v;
    cin >> u >> v;
    --u;
    --v;
    g[u].emplace_back(v, i);
    g[v].emplace_back(u, i);
  }

  vector<int> depth(n, -1);
  depth[0] = 0;
  vector<pair<int, int>> par(n);
  dfs(0, g, depth, par);

  tuple<int, int, int> mx_be = {0, 0, 0};
  for (int u = 0; u < n; ++u) {
    for (auto [v, k] : g[u]) {
      auto [a, b, i] = mx_be;
      if (par[u].first != v && par[v].first != u && f(u, v, depth) > f(a, b, depth)) {
        mx_be = {u, v, k};
      }
    }
  }

  auto [s, e, k] = mx_be;
  if (depth[s] < depth[e]) {
    swap(s, e);
  }
  vector<int> ans;
  while (s != e) {
    ans.push_back(par[s].second);
    s = par[s].first;
  }
  ans.push_back(k);
  
  cout << (int)ans.size() << '\n';
  for (int x : ans) {
    cout << x << ' ';
  }
  cout << '\n';
}