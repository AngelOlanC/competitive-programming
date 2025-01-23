#include <bits/stdc++.h>
using namespace std;
int main() {
  cin.tie(0)->sync_with_stdio(0);
  int n, m;
  cin >> n >> m;
  vector<vector<int>> g(n);
  for (int i = 0; i < m; ++i) {
    int u, v;
    cin >> u >> v;
    --u;
    --v;
    g[u].push_back(v);
    g[v].push_back(u);
  }
  vector<int> dist(n, 1e9), prev(n);
  queue<int> q;
  q.push(0);
  dist[0] = 0;
  while (!q.empty()) {
    int u = q.front();
    q.pop();
    for (auto &v : g[u]) {
      if (dist[u] + 1 < dist[v]) {
        dist[v] = dist[u] + 1;
        prev[v] = u;
        q.push(v);
      }
    }
  }
  if (dist.back() == 1e9) {
    cout << "IMPOSSIBLE\n";
    return 0;
  }
  stack<int> st;
  {
    int u = n - 1;
    while (u) {
      st.push(u);
      u = prev[u];
    }
    st.push(0);
  }
  cout << (int)st.size() << '\n';
  while (!st.empty()) {
    cout << st.top() + 1 << ' ';
    st.pop();
  }
  cout << '\n';
}