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
  cin.tie(0)->sync_with_stdio(0);

  int n;
  cin >> n;
  vector<vi> g(n);
  FOR (i, 1, n) {
    int u, v;
    cin >> u >> v;
    g[--u].pb(--v), g[v].pb(u);
  }
  auto solve = [&](auto &&self, int u, int p) -> int {
    int s = 0;
    for (auto &v : g[u]) if (v != p) s += self(self, v, u);
    return s ? s - 1 : 1;
  };
  cout << (solve(solve, 0, -1) ? "Alice" : "Bob") << ENDL;

  return 0;
}