#include <bits/stdc++.h>
using namespace std;
// Pura Gente del Coach Moy

using i64 = long long;

constexpr int INF = 1e9;
constexpr i64 INF64 = 1e18;

i64 f(i64 a, i64 b, i64 d) {
  return a - b * d;
}

signed main() {
  cin.tie(0)->sync_with_stdio(0);

  int n, m;
  cin >> n >> m;
  
  vector<int> a(n), b(n);
  for (int i = 0; i < n; ++i) {
    cin >> a[i] >> b[i];
  }

  vector<vector<int>> g(n);
  for (int i = 0; i < m; ++i) {
    int u, v;
    cin >> u >> v;
    --u;
    --v;
    g[u].push_back(v);
    g[v].push_back(u);
  }

  vector<int> d(n, INF);
  vector<int> o;
  queue<int> q;
  d[0] = 0;
  q.push(0);
  while (!q.empty()) {
    int u = q.front();
    q.pop();
    o.push_back(u);
    for (int v : g[u]) {
      if (d[u] + 1 < d[v]) {
        d[v] = d[u] + 1;
        q.push(v);
      }
    }
  }

  for (int i = 0; i < n; ++i) {
    o.push_back(o[i] + n);
  }

  reverse(o.begin(), o.end());

  vector<vector<int>> g2(2 * n);
  for (int u = 1; u < n; ++u) {
    for (int v : g[u]) {
      if (d[v] == d[u] + 1) {
        g2[u].push_back(v);
        g2[u + n].push_back(v + n);
      }
      if (d[u] == d[v]) {
        g2[u].push_back(v + n);
      }
    }
  }
  
  vector<i64> ans(n);
  i64 curr = -INF64;
  for (int i = 0; i < n; ++i) {
    ans[i] = max(ans[i], curr);
    curr = max(curr, f(a[i], b[i], d[i] + 1));
  }
  curr = -INF64;
  for (int i = n - 1; i >= 0; --i) {
    ans[i] = max(ans[i], curr);
    curr = max(curr, f(a[i], b[i], d[i] + 1));
  }

  vector<i64> dp(2 * n, -INF64);
  for (int u : o) {
    i64 uf = f(a[u % n], b[u % n], d[u % n]);
    if (u < n) {
      uf += b[u];
    }
    for (int v : g2[u]) {
      dp[u] = max(dp[u], dp[v]);
    }
    if (u < n) {
      ans[u] = max(ans[u], dp[u]);
    }
    dp[u] = max(dp[u], uf);
  }

  sort(g[0].begin(), g[0].end());
  
  for (int u : g[0]) {
    cout << ans[u] << '\n';
  }

  return 0;
}