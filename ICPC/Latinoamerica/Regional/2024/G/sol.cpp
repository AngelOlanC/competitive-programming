#include <bits/stdc++.h>
using namespace std;
// Pura Gente del Coach Moy
signed main() {
  cin.tie(0)->sync_with_stdio(0);

  int n;
  cin >> n;
  vector<vector<pair<int, int>>> g(n);
  for (int i = 1; i < n; ++i) {
    int u, v, w;
    cin >> u >> v >> w;
    --u;
    --v;
    g[u].push_back({v, w});
    g[v].push_back({u, w});
  }

  vector<vector<pair<int, int>>> Q(n);
  int q;
  cin >> q;
  for (int i = 0; i < q; ++i) {
    int s, t;
    cin >> s >> t;
    --s;
    --t;
    Q[t].push_back({s, i});
  }

  vector<pair<int, int>> dp(n, {1e9, 1e9});
  auto dfsdp = [&](auto self, int u, int p, int pw) -> void {
    for (auto &[v, w] : g[u]) {
      if (v == p) {
        continue;
      }
      self(self, v, u, w);
    }
    if (g[u].size() == 1) {
      dp[u] = {0, u};
    }
    if (u) {
      dp[p] = min(dp[p], make_pair(dp[u].first + pw, dp[u].second));
    }
  };
  dfsdp(dfsdp, 0, -1, -1);

  vector<int> curr(n);
  for (int i = 0; i < n; ++i) {
    ++curr[dp[i].second];
  }

  vector<int> ans(q);
  auto reroot = [&](auto self, int u, int p) -> void {
    for (auto &[x, i] : Q[u]) {
      ans[i] = curr[x];
    }
    pair<int, int> alternative = {1e9, 1e9};
    if (g[u].size() == 1) {
      alternative = {0, u};
    } else {
      for (auto &[v, w] : g[u]) {
        if (dp[v].second != dp[u].second) {
          alternative = min(alternative, make_pair(dp[v].first + w, dp[v].second));
        } 
      }
    }
    for (auto &[v, w] : g[u]) {
      if (v == p) {
        continue;
      }
      --curr[dp[u].second];
      --curr[dp[v].second];
      pair<int, int> oldDpu = dp[u], oldDpv = dp[v];
      if (dp[v].second == dp[u].second) {
        dp[u] = alternative;
      }
      dp[v] = min(dp[v], make_pair(dp[u].first + w, dp[u].second));
      ++curr[dp[u].second];
      ++curr[dp[v].second];
      self(self, v, u);
      --curr[dp[u].second];
      --curr[dp[v].second];
      dp[u] = oldDpu;
      dp[v] = oldDpv;   
      ++curr[dp[u].second];
      ++curr[dp[v].second]; 
    }
  };
  reroot(reroot, 0, -1);

  for (int i = 0; i < q; ++i) {
    cout << ans[i] << '\n';
  }

  return 0;
}