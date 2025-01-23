#include <bits/stdc++.h>
using namespace std;
// Pura Gente del Coach Moy

using i64 = long long;

i64 dfs(vector<vector<int>>& g, vector<int>& c, vector<vector<int>>& last, vector<bool>& hasAnc, vector<int>& children, int u, int p) {
  i64 ret = 0;

  if (!last[c[u]].empty()) {
    hasAnc[u] = true;
    ++children[last[c[u]].back()];
    ++ret;
  }

  last[c[u]].push_back(u);
  for (int v : g[u]) {
    if (v != p) {
      int prevChildren = children[u];
      ret += dfs(g, c, last, hasAnc, children, v, u);
      if (children[u] != prevChildren) {
        int d = children[u] - prevChildren;
        ret += (i64)d * (d - 1) >> 1;
      }
    }
  }
  last[c[u]].pop_back();
  return ret;
}

void solve() {
  int n;
  cin >> n;

  vector<int> c(n);
  for (int& x : c) {
    cin >> x;
    --x;
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

  vector<bool> hasAnc(n);
  vector<int> children(n);
  vector<vector<int>> last(n);
  i64 ans = dfs(g, c, last, hasAnc, children, 0, -1);

  vector<int> left(n);
  for (int i = 0; i < n; ++i) {
    if (!hasAnc[i]) {
      ++left[c[i]];
    }
  }
  for (int i = 0; i < n; ++i) {
    if (left[i]) {
      ans += (i64)left[i] * (left[i] - 1) >> 1;
    }
  }

  cout << ans << '\n';
}

int main() {
  cin.tie(0)->sync_with_stdio(0);

  int t;
  cin >> t;
  while (t--) {
    solve();
  }

  return 0;
}