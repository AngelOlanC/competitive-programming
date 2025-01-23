#include <bits/stdc++.h>
using namespace std;

using ll = long long;
using pi = pair<int, int>;
using vi = vector<int>;

#define pb push_back
#define SZ(x) ((int)(x).size())
#define ALL(x) begin(x), end(x)
#define FOR(i, a, b) for (int i = (int)a; i < (int)b; ++i)
#define ROF(i, a, b) for (int i = (int)a - 1; i >= (int)b; --i)
#define ENDL '\n'

void solve(int test_case) {
  int n;
  cin >> n;
  vector<vi> g(n);
  FOR (i, 1, n) {
    int u, v;
    cin >> u >> v;
    --u, --v;
    g[u].pb(v), g[v].pb(u);
  }
  int x;
  cin >> x >> x;
  --x;
  vi nxt(n, -1), d(n), path(n);
  auto dfs = [&](auto &&self, int u, int p) -> void{
    nxt[u] = u;
    for (auto &v : g[u]) if (v != p) {
      d[v] = d[u] + 1;
      self(self, v, u);
      if (nxt[v] == -1) path[u] = max(path[u], 1 + path[v]);
      else nxt[u] = v;
    }
  };
  dfs(dfs, 0, -1);
  auto solve = [&](auto &&self, int u, int p) -> void {
    if (d[u] <= d[x] - d[u]) {
      path[0] = max(path[0], d[u] + path[u]);
    } else {
      path[x] = max(path[x], d[x] - d[u] + path[u]);
    }
    if (u != nxt[u]) self(self, nxt[u], u);
  };
  solve(solve, 0, -1);
  cout << (path[0] > path[x] ? "Alice" : "Bob") << ENDL;
}

signed main() {
  cin.tie(0)->sync_with_stdio(0);

  int tc;
  cin >> tc;
  FOR (test_case, 0, tc) {
    solve(test_case + 1);
  }

  return 0;
}