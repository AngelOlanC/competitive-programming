#include <bits/stdc++.h>
using namespace std;
// Pura Gente del Coach Moy

int single(int u, int p, bool b, vector<vector<int>>& g, vector<vector<int>>& memo) {
  int& ret = memo[b][u];
  if (ret != -1) {
    return ret;
  }
  ret = (int)g[u].size() - int(b);
  for (int v : g[u]) {
    if (v != p) {
      ret = max(ret, single(v, u, false, g, memo));
    }
  }
  return ret;
}

int dfs(int u, int p, vector<vector<int>>& g, vector<vector<int>>& memo) {
  int mx1 = -1, mx2 = -1, mxc = -1, ans = -1e7;
  for (int v : g[u]) {
    if (v != p) {
      ans = max(ans, dfs(v, u, g, memo));

      mxc = max(mxc, single(v, u, true, g, memo));

      int x = single(v, u, false, g, memo);
      if (x > mx1) {
        swap(mx1, mx2);
        mx1 = x;
      } else if (x > mx2) {
        mx2 = x;
      }
    }
  }
  if (mx1 >= 0 && mx2 >= 0) {
    ans = max(ans, mx1 + mx2 - 1);
  }
  if (mxc >= 0) {
    ans = max(ans, (int)g[u].size() - 1 + mxc);
  }
  return ans;
}

void solve() {
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

  vector<vector<int>> memo(2, vector<int>(n, -1));
  cout << dfs(0, -1, g, memo) << '\n';
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