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

signed main() {
  ios_base::sync_with_stdio(0);
  cin.tie(nullptr);

  int n;
  cin >> n;
  
  vi g(n);
  FOR (i, 0, n) {
    cin >> g[i];
    --g[i];
  }

  vi val(n, -1), sz(n, 0);

  int cycle = 0, last_in_cycle, cycle_sz = 0;
  auto solve = [&](auto self, int u) -> int {
    if (~val[u]) {
      return val[u];
    }
    if (g[u] == u) {
      return val[u] = 1;
    }
    if (g[g[u]] == u) {
      return val[u] = val[g[u]] = 2;
    }
    if (val[g[u]] == -2) {
      cycle = 1;
      cycle_sz = sz[u] - sz[g[u]] + 1;
      last_in_cycle = g[u];
      return val[u] = cycle_sz;
    }
    val[u] = -2;
    sz[g[u]] = sz[u] + 1;
    self(self, g[u]);
    if (cycle) {
      if (last_in_cycle == u) {
        cycle = 0;
      }
      return val[u] = cycle_sz;
    }
    return val[u] = 1 + val[g[u]];
  };

  ll ans = 0;
  FOR (i, 0, n) {
    sz[i] = 1;
    cycle = 0;
    ans += solve(solve, i);
  }
  cout << ans << ENDL;

  return 0;
}