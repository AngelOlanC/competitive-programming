#include <bits/stdc++.h>
using namespace std;

int main() {
  cin.tie(0)->sync_with_stdio(0);

  int n, m;
  cin >> n >> m;

  vector<vector<int>> g(n);
  vector<int> in_degree(n);
  vector<bitset<50005>> g_bst(n);
  for (int i = 0; i < m; ++i) {
    int u, v;
    cin >> u >> v;
    --u;
    --v;
    g[u].push_back(v);
    g_bst[u].set(v);
    ++in_degree[v];
  }

  queue<int> q;
  for (int i = 0; i < n; ++i) {
    if (!in_degree[i]) {
      q.push(i);
    }
  }
  
  vector<int> order;
  while (!q.empty()) {
    int u = q.front();
    q.pop();

    order.push_back(u);
    
    for (int v : g[u]) {
      --in_degree[v];
      if (!in_degree[v]) {
        q.push(v);
      }
    }
  }

  for (int i = (int)order.size() - 1; i >= 0; --i) {
    int u = order[i];
    for (int v : g[u]) {
      g_bst[u] |= g_bst[v];
    }
  }

  for (int i = 0; i < n; ++i) {
    cout << g_bst[i].count() + 1 << " \n"[i == n - 1];
  }
}