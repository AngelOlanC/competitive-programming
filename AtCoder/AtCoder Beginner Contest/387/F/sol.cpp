#include <bits/stdc++.h>
using namespace std;
// Pura Gente del Coach Moy

vector<vector<int>> getCondensedGraph(vector<int>& g) {
  const int n = (int)g.size();

  vector<int> inDeg(n);
  for (int i = 0; i < n; ++i) {
    ++inDeg[g[i]];
  }

  queue<int> q;
  for (int i = 0; i < n; ++i) {
    if (!inDeg[i]) {
      q.push(i);
    }
  }

  vector<bool> vis(n);
  while (!q.empty()) {
    int u = q.front();
    q.pop();

    vis[u] = true;
    
    --inDeg[g[u]];
    if (!inDeg[g[u]]) {
      q.push(g[u]);
    }
  }

  vector<vector<int>> g2;
  vector<int> g2Id(n, -1);
  for (int i = 0; i < n; ++i) {
    if (vis[i] || g2Id[i] != -1) {
      continue;
    }
    int j = i, id = (int)g2.size();
    do {
      g2Id[j] = id;
      j = g[j];
    } while (j != i);
    g2.emplace_back();
  }

  for (int& id : g2Id) {
    if (id == -1) {
      id = (int)g2.size();
      g2.emplace_back();
    }
  }

  for (int i = 0; i < n; ++i) {
    int u = g2Id[g[i]], v = g2Id[i];
    if (u != v) {
      g2[u].push_back(v);
    }
  }
  return g2;
}

constexpr int MOD = 998244353;

inline int add(int x, int y) {
  return x + y < MOD ? x + y : x + y - MOD;
}

using i64 = long long;
inline int mul(int x, int y) {
  return int((i64)x * y % MOD);
}

void f(int u, vector<vector<int>>& dp, vector<vector<int>>& g) {
  const int m = (int)dp[u].size();

  for (int v : g[u]) {
    f(v, dp, g);
    for (int i = 0; i < m; ++i) {
      dp[u][i] = mul(dp[u][i], dp[v][i]);
    }
  }

  for (int i = 1; i < m; ++i) {
    dp[u][i] = add(dp[u][i], dp[u][i - 1]);
  }
}

int main() {
  cin.tie(0)->sync_with_stdio(0);

  int n, m;
  cin >> n >> m;

  vector<int> a(n);
  for (int& x : a) {
    cin >> x;
    --x;
  }

  vector<vector<int>> g = getCondensedGraph(a);
  vector<int> inDeg((int)g.size());
  for (auto& e : g) {
    for (int v : e) {
      ++inDeg[v];
    }
  }

  vector<vector<int>> dp((int)g.size(), vector<int>(m, 1));
  int ans = 1;
  for (int i = 0; i < (int)g.size(); ++i) {
    if (!inDeg[i]) {
      f(i, dp, g);
      ans = mul(ans, dp[i][m - 1]);
    }
  }
  cout << ans << '\n';

  return 0;
}