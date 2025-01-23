#include <bits/stdc++.h>
using namespace std;

using i64 = long long;

constexpr int MOD = 1e9 + 7;

inline int add(int x, int y) {
  int ret = x + y;
  if (ret >= MOD) {
    ret -= MOD;
  }
  return ret;
}

inline int sub(int x, int y) {
  int ret = x - y;
  if (ret < 0) {
    ret += MOD;
  }
  return ret;
}

inline int mul(int x, int y) {
  return (i64) x * y % MOD;
}

void dfs(int u, vector<vector<int>>& g, vector<int>& par, vector<int>& depth) {
  for (int v : g[u]) {
    if (v != par[u]) {
      depth[v] = depth[u] + 1;
      par[v] = u;
      dfs(v, g, par, depth);
    }
  }
}

void solve() {
  int n, q;
  cin >> n >> q;
  vector<vector<int>> g(n);
  for (int i = 1; i < n; ++i) {
    int u, v;
    cin >> u >> v;
    --u;
    --v;
    g[u].push_back(v);
    g[v].push_back(u);
  }
  vector<int> par(n), depth(n);
  dfs(0, g, par, depth);
  while (q--) {
    int v, p;
    cin >> v >> p;
    --v;
    vector<int> szs;
    int ev = depth[v];
    {
      int u = v;
      bool zero = false;
      while (u) {
        if (zero) {
          szs.push_back(g[u].size());
        }
        zero = !zero;
        u = par[u];
      }
    }
    sort(szs.rbegin(), szs.rend());
    for (int i = p; i < szs.size(); ++i) {
      ev = add(ev, sub(mul(2, szs[i]), 2));
    }
    cout << ev << '\n';
  }
}

int main() {
  cin.tie(0)->sync_with_stdio(0);
  int t;
  cin >> t;
  while (t--) {
    solve();
  }
}