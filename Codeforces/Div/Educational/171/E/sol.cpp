#include <bits/stdc++.h>
using namespace std;
// Pura Gente del Coach Moy y de la Alexbriza

template<typename T>
struct Dinic {
  #define INF numeric_limits<T>::max()
  struct Edge {
    int to, rev;
    T c, oc;
    T flow() { return max(oc - c, T(0)); }  // if you need flows
  };
  vector<int> lvl, ptr, q;
  vector<vector<Edge>> adj;
  Dinic(int n) : lvl(n), ptr(n), q(n), adj(n) {}
  void addEdge(int a, int b, T c = INF, T rcap = 0) {
    adj[a].push_back({b, (int)adj[b].size(), c, c});
    adj[b].push_back({a, (int)adj[a].size() - 1, rcap, rcap});
  }
  T dfs(int v, int t, T f) {
    if (v == t || !f) return f;
    for (int& i = ptr[v]; i < (int)adj[v].size(); i++) {
      Edge& e = adj[v][i];
      if (lvl[e.to] == lvl[v] + 1) if (T p = dfs(e.to, t, min(f, e.c))) {
        e.c -= p, adj[e.to][e.rev].c += p;
        return p;
      }
    }
    return 0;
  }
  T calc(int s, int t) {
    T flow = 0;
    q[0] = s;
    for (int L = 0; L < 31; ++L) do {  // 'int L=30' maybe faster for random data
      lvl = ptr = vector<int>((int)q.size());
      int qi = 0, qe = lvl[s] = 1;
      while (qi < qe && !lvl[t]) {
        int v = q[qi++];
        for (Edge e : adj[v]) if (!lvl[e.to] && e.c >> (30 - L)) q[qe++] = e.to, lvl[e.to] = lvl[v] + 1;
      }
      while (T p = dfs(s, t, INF)) flow += p;
    }
    while (lvl[t]);
    return flow;
  }
  bool leftOfMinCut(int a) { return lvl[a] != 0; }
};

using i64 = long long;

void solve() {
  int n;
  cin >> n;

  Dinic<int> d(1 + n + 60 + 1);
  for (int i = 0; i < 60; ++i) {
    d.addEdge(1 + n + i, 1 + n + 60, 1);
  }

  for (int i = 0; i < n; ++i) {
    i64 x;
    cin >> x;
    d.addEdge(0, 1 + i, 1);
    for (int j = 0; j < 60; ++j) {
      if ((x >> j) & 1) {
        d.addEdge(1 + i, 1 + n + j);
      }
    }
  }
  cout << max(0, n - d.calc(0, 1 + n + 60)) << '\n';
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