#include <bits/stdc++.h>
using namespace std;
using i64 = long long;
i64 INF = 1e15;
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
    g[u].emplace_back(v, w);
  }
  vector<vector<i64>> d(2, vector<i64>(n, INF));
  priority_queue<tuple<i64, int, bool>> pq;
  pq.emplace(0, 0, 0);
  d[0][0] = 0;
  while (!pq.empty()) {
    auto [du, u, c] = pq.top();
    pq.pop();
    du = -du;
    if (d[c][u] < du) {
      continue;
    }
    for (auto &[v, w] : g[u]) {
      if (du + w < d[c][v]) {
        d[c][v] = du + w;
        pq.emplace(-d[c][v], v, c);
      }
      if (!c && du + w / 2 < d[1][v]) {
        d[1][v] = du + w / 2;
        pq.emplace(-d[1][v], v, 1);
      }
    }
  }
  cout << d[1][n - 1] << '\n';
}