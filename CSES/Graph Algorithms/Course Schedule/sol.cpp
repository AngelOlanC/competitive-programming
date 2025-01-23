#include <bits/stdc++.h>
using namespace std;
int main() {
  cin.tie(0)->sync_with_stdio(0);
  int n, m;
  cin >> n >> m;
  vector<vector<int>> g(n);
  vector<int> in_degree(n);
  for (int i = 0; i < m; ++i) {
    int u, v;
    cin >> u >> v;
    --u;
    --v;
    g[u].push_back(v);
    ++in_degree[v];
  }
  queue<int> q;
  for (int i = 0; i < n; ++i) {
    if (!in_degree[i]) {
      q.push(i);
    }
  }
  vector<int> topo;
  while (!q.empty()) {
    int u = q.front();
    q.pop();
    topo.push_back(u);
    for (auto &v : g[u]) {
      --in_degree[v];
      if (!in_degree[v]) {
        q.push(v);
      }
    }
  }
  if (topo.size() != n) {
    cout << "IMPOSSIBLE\n";
    return 0;
  }
  for (int u : topo) {
    cout << u + 1 << ' '; 
  }
  cout << '\n';
}