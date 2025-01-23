#include <bits/stdc++.h>
using namespace std;

signed main() {
  cin.tie(0)->sync_with_stdio(0);

  int n;
  cin >> n;
  vector<vector<int>> bosses_g(n);
  for (int i = 0; i < n; ++i) {
    int k;
    cin >> k;
    while (k--) {
      int u;
      cin >> u;
      bosses_g[u - 1].push_back(i);
    }
  }

  int ans = 1e9;
  for (int root = 0; root < n; ++root) {
    vector<int> d(n, -1);
    queue<int> q;
    d[root] = 1;
    q.push(root);
    while (!q.empty()) {
      int u = q.front();
      q.pop();
      for (auto &v : bosses_g[u]) {
        if (d[v] == -1) {
          d[v] = d[u] + 1;
          q.push(v);
        }
      }
    }
    int sum = 0;
    for (int i = 0; i < n; ++i) {
      if (d[i] == -1) {
        sum = -1;
        break;
      }
      sum += d[i];
    }
    if (sum != -1) {
      ans = min(ans, sum);
    }
  }
  cout << ans << '\n';

  return 0;
}