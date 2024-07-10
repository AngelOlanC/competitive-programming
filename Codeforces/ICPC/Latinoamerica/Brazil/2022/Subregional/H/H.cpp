#include <bits/stdc++.h>
using namespace std;
// Pura Gente del Coach Moy
using ll = long long;
using pi = pair<int, int>;
using vi = vector<int>;

#define pb push_back
#define SZ(x) ((int)(x).size())
#define ALL(x) begin(x), end(x)
#define FOR(i, a, b) for (int i = (int)a; i < (int)b; ++i)
#define ROF(i, a, b) for (int i = (int)a - 1; i >= (int)b; --i)
#define ENDL '\n'

vector<vi> tarjan(vector<vi>& g) {
  int n = SZ(g), timer = 0;
  vector<vi> scc;
  vi tin(n, -1), low(n, 0), vis(n, 0);
  stack<int> st;
  auto dfs = [&](auto self, int u) -> void {
    tin[u] = low[u] = timer++;
    st.push(u);
    vis[u] = 1;
    for (int v : g[u]) {
      if (tin[v] == -1) self(self, v);
      if (vis[v]) low[u] = min(low[u], low[v]);
    }
    if (low[u] == tin[u]) {
      scc.pb({});
      while (1) {
        int v = st.top();
        st.pop();
        vis[v] = 0;
        scc.back().pb(v);
        if (u == v) break;
      }
    }
  };
  FOR (i, 0, n) if (tin[i] == -1) dfs(dfs, i);
  return scc;
}

signed main() {
  cin.tie(0)->sync_with_stdio(0);

  int n, m;
  cin >> n >> m;

  vector<vi> g(n);
  while (m--) {
    int u, v;
    cin >> u >> v;
    g[u - 1].pb(v - 1);
  }

  vector<vi> scc = tarjan(g);

  int cnt = 0;
  vi id_g(n, -1);
  for (auto &comp : scc) {
    for (auto &u : comp) {
      id_g[u] = cnt;
    }
    cnt++;
  }

  FOR (i, 0, n) if (id_g[i] == -1) {
    id_g[i] = cnt++;
  }

  if (cnt == 1) {
    cout << 0 << ENDL;
    return 0;
  }

  vi in_deg(n, 0), out_deg(n, 0);
  FOR (u, 0, n) {
    for (auto &v : g[u]) if (id_g[u] != id_g[v]) {
      out_deg[id_g[u]]++;
      in_deg[id_g[v]]++;
    }
  }

  int no_in = 0, no_out = 0;
  FOR (i, 0, cnt) {
    no_in += !in_deg[i];
    no_out += !out_deg[i];
  }
  cout << max(no_in, no_out) << ENDL;

  return 0;
}