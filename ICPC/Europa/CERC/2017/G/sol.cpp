#include <bits/stdc++.h>
using namespace std;
// Pura Gente del Coach Moy

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

  vector<int> a(n);
  vector<double> s(n), ev(n, 1e9);
  ev[n - 1] = 0;

  set<pair<double, int>> st;
  for (int i = 0; i < n; ++i) {
    s[i] = g[i].size();
    st.emplace(ev[i], i);
  }

  vector<bool> vis(n);
  while (!st.empty()) {
    auto [ e, u ] = *st.begin();
    st.erase(st.begin());
    vis[u] = true;

    for (int v : g[u]) {
      if (!vis[v]) {
        st.erase(st.find(make_pair(ev[v], v)));
        ++a[v];
        s[v] += e;
        ev[v] = (double)s[v] / a[v];
        st.emplace(ev[v], v);
      }
    }
  }

  cout << setprecision(9) << fixed << ev[0] << '\n';

  return 0;
}