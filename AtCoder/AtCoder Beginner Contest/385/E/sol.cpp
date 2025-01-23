#include <bits/stdc++.h>
using namespace std;
// Pura Gente del Coach Moy

int dfs(int u, int p, vector<vector<int>>& g) {
  vector<int> y;
  int ans = 0;
  for (int v : g[u]) {
    if (v != p) {
      ans = max(ans, dfs(v, u, g));
    }
    if ((int)g[v].size() != 1) {
      y.push_back(((int)g[v].size() - 1));
    }
  }

  if (y.empty()) {
    return ans;
  }

  sort(y.rbegin(), y.rend());

  for (int i = 0; i < (int)y.size(); ++i) {
    int x = i + 1;
    ans = max(ans, 1 + x * (1 + y[i]));
  }

  return ans;
}

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

  cout << n - dfs(0, -1, g) << '\n';

  return 0;
}