#include <bits/stdc++.h>
using namespace std;
using i64 = long long;
constexpr i64 INF = 1e18;
int main() {
  cin.tie(0)->sync_with_stdio(0);
  int n, m;
  cin >> n >> m;
  vector<tuple<int, int, int>> e(m);
  for (auto &[u, v, w] : e) {
    cin >> u >> v >> w;
    --u;
    --v;
  }
  vector<i64> d(n);
  vector<int> p(n);
  for (int i = 0; i < n; ++i) {
    for (auto &[u, v, w] : e) {
      if (d[u] != INF && d[u] + w < d[v]) {
        d[v] = d[u] + w;
        p[v] = u;
      }
    }
  }
  for (int i = 0; i < n; ++i) {
    int start = -1;
    for (auto &[u, v, w] : e) {
      if (d[u] != INF && d[u] + w < d[v]) {
        start = u;
        break;
      }
    }
    if (start != -1) {
      int u = start;
      for (int j = 0; j < n; ++j) {
        u = p[u];
      }
      vector<int> cycle;
      start = u;
      do {
        cycle.push_back(u);
        u = p[u];
      } while (u != start);
      cycle.push_back(u);
      reverse(cycle.begin(), cycle.end());
      cout << "YES\n";
      for (int u : cycle) {
        cout << u + 1 << ' ';
      }
      cout << '\n';
      return 0;
    }
  }
  cout << "NO\n";
}