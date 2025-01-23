#include <bits/stdc++.h>
using namespace std;
using i64 = long long;
int main() {
  cin.tie(0)->sync_with_stdio(0);
  int n, m;
  cin >> n >> m;
  vector<vector<pair<int, int>>> g(n);
  for (int i = 0; i < m; ++i) {
    int u, v, w;
    cin >> u >> v >> w;
    --u;
    --v;
    g[u].push_back({v, w});
  }
  vector<i64> dist(n, 1e18);
  dist[0] = 0;
  priority_queue<pair<i64, int>> pq;
  pq.push({0, 0});
  while (!pq.empty()) {
    auto [du, u] = pq.top();
    pq.pop();
    du *= -1;
    if (du > dist[u]) {
      continue;
    }
    for (auto &[v, w] : g[u]) {
      if (du + w < dist[v]) {
        dist[v] = du + w;
        pq.push({-dist[v], v});
      }
    }
  }
  for (int i = 0; i < n; ++i) {
    cout << dist[i] << " \n"[i == n - 1];
  }
}