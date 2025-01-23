#include <bits/stdc++.h>
using namespace std;
using i64 = long long;
constexpr i64 INF = 1e16;
int main() {
  cin.tie(0)->sync_with_stdio(0);
  int n, m, q;
  cin >> n >> m >> q;
  vector<vector<i64>> dist(n, vector<i64>(n, INF));
  for (int i = 0; i < n; ++i) {
    dist[i][i] = 0;
  }
  for (int i = 0; i < m; ++i) {
    int u, v, w;
    cin >> u >> v >> w;
    --u;
    --v;
    dist[u][v] = dist[v][u] = min(dist[u][v], (i64)w);
  }
  for (int k = 0; k < n; ++k) {
    for (int i = 0; i < n; ++i) {
      for (int j = 0; j < n; ++j) {
        dist[i][j] = min(dist[i][j], dist[i][k] + dist[k][j]);
      }
    }
  }
  for (int i = 0; i < n; ++i) {
    for (int j = 0; j < n; ++j) {
      if (dist[i][j] == INF) {
        dist[i][j] = -1;
      }
    }
  }
  for (int i = 0; i < q; ++i) {
    int u, v;
    cin >> u >> v;
    --u;
    --v;
    cout << dist[u][v] << '\n';
  }
}