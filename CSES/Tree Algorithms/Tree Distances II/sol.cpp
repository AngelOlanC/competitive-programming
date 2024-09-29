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
    --u, --v;
    g[u].pb(v), g[v].pb(u);
  }
  vi sz(n);
  auto calc_sz = [&](auto &&self, int u, int p) -> ll {
    sz[u] = 1;
    ll sum = 0;
    for (auto &v : g[u]) if (v != p) sum += self(self, v, u), sz[u] += sz[v];
    return sum + sz[u];
  };
  vector<ll> ans(n);
  auto calc_ans = [&](auto &&self, int u, int p, ll val) -> void {
    ans[u] = val;
    for (auto &v : g[u]) if (v != p) self(self, v, u, val - sz[v] + sz[0] - sz[v]);
  };
  calc_ans(calc_ans, 0, -1, calc_sz(calc_sz, 0, -1));
  FOR (i, 0, n) cout << ans[i] - n << " \n"[i == n - 1];
  return 0;
}