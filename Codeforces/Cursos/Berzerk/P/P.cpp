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

using ld = long double;

signed main() {
  cin.tie(0)->sync_with_stdio(0);

  int n;
  cin >> n;

  vector<vi> g(n);
  FOR (i, 1, n) {
    int u, v;
    cin >> u >> v;
    g[--u].pb(--v), g[v].pb(u);
  }

  ld ans = 0;
  vi d(n, -1); d[0] = 0;
  vector<ld> p(n); p[0] = 1.0;
  queue<int> q; q.push(0);
  while (!q.empty()) {
    int u = q.front(); q.pop();
    int children = SZ(g[u]) - (u != 0);
    if (!children) {
      ans += p[u] * d[u];
      continue;
    }
    ld prob = p[u] / children;
    // cout << u << ' ' << p[u] << ENDL;
    for (auto &v : g[u]) if (d[v] == -1) {
      q.push(v);
      d[v] = d[u] + 1;
      p[v] = prob;
    }
  }
  cout << setprecision(12) << fixed << ans << ENDL;

  return 0;
}