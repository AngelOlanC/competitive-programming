#include <bits/stdc++.h>
using namespace std;
// Pura Gente del Coach Moy
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
  return (i64)x * y % MOD;
}
vector<int> toposort(vector<vector<int>>& g) {
  int n = (int)g.size();
  vector<int> in_degree(n);
  for (int u = 0; u < n; ++u) {
    for (int v : g[u]) {
      ++in_degree[v];
    }
  }
  queue<int> q;
  for (int u = 0; u < n; ++u) {
    if (!in_degree[u]) {
      q.push(u);
    }
  }
  vector<int> topo;
  while (!q.empty()) {
    int u = q.front();
    q.pop();
    topo.push_back(u);
    for (int v : g[u]) {
      --in_degree[v];
      if (!in_degree[v]) {
        q.push(v);
      }
    }
  }
  assert((int)topo.size() == n);
  return topo;
}
vector<vector<int>> calc_ways(vector<vector<int>>& g, vector<int>& rev_topo) {
  int n = (int)g.size();
  vector<vector<int>> ways(n, vector<int>(n, 0));
  for (int u = 0; u < n; ++u) {
    ++ways[u][u];
  }
  for (int u : rev_topo) {
    for (int dest = 0; dest < n; ++dest) {
      if (dest == u) {
        continue;
      }
      for (int v : g[u]) {
        ways[u][dest] = add(ways[u][dest], ways[v][dest]);
      }
    }
  }
  return ways;
}
void calc_t(vector<vector<int>>& g, vector<int>& t, vector<int>& b, vector<int>& rev_topo) {
  for (int u : rev_topo) {
    t[u] = b[u];
    for (int v : g[u]) {
      t[u] = add(t[u], t[v]);
    }
  }
}
int main() {
  cin.tie(0)->sync_with_stdio(0);
  int n;
  cin >> n;
  vector<int> b(n);
  for (int i = 0; i < n; ++i) {
    cin >> b[i];
  }
  vector<vector<int>> g(n);
  int m;
  cin >> m;
  while (m--) {
    int u, v;
    cin >> u >> v;
    --u;
    --v;
    g[u].push_back(v);
  }
  vector<int> rev_topo = toposort(g);
  reverse(rev_topo.begin(), rev_topo.end());
  vector<vector<int>> ways = calc_ways(g, rev_topo);
  vector<int> t(n);
  int e;
  cin >> e;
  int ans = 0, k = 1;
  vector<pair<int, int>> in_batch;
  for (int z = 0; z < e; ++z) {
    if (z % 1000 == 0) {
      in_batch.clear();
      calc_t(g, t, b, rev_topo);
    }
    char op;
    cin >> op;
    if (op == 'Q') {
      int j;
      cin >> j;
      --j;
      int curr = t[j];
      for (auto [v, delta] : in_batch) {
        curr = add(curr, mul(delta, ways[j][v]));
      }
      ans = add(ans, mul(k, curr));
      ++k;
      continue;
    }
    int i, v;
    cin >> i >> v;
    --i;
    in_batch.push_back({i, sub(v, b[i])});
    b[i] = v;
  }
  cout << ans << '\n';
  return 0;
}