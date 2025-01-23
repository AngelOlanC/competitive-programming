#include <bits/stdc++.h>
using namespace std;
// Pura gente del coach moy
using i64 = long long;
int main() {
  cin.tie(0)->sync_with_stdio(0);
  int n;
  cin >> n;
  vector<vector<int>> g(n);
  for (int i = 1; i < n; ++i) {
    int u, v;
    cin >> u >> v;
    --u;
    --v;
    g[u].push_back(v);
    g[v].push_back(u);
  }
  vector<i64> a(n);
  for (int i = 0; i < n; ++i) {
    cin >> a[i];
  }
  vector<i64> neg(n), pos(n);
  auto solve = [&a, &neg, &pos, &g](auto &&self, int u, int p) -> void {
    for (int v : g[u]) {
      if (v != p) {
        self(self, v, u);
      }
    }
    a[u] += pos[u] - neg[u];
    if (a[u] > 0) {
      neg[u] += a[u];
    } else if (a[u] < 0) {
      pos[u] += -a[u];
    }
    if (u) {
      neg[p] = max(neg[p], neg[u]);
      pos[p] = max(pos[p], pos[u]);
    }
  };
  solve(solve, 0, -1);
  cout << neg[0] + pos[0] << '\n';
}