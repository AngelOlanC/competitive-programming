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
  vector<ll> a(n);
  for (auto &ai : a) cin >> ai;
  FOR (i, 1, n) {
    int p;
    cin >> p;
    g[--p].pb(i);
  }
  auto dfs = [&](auto &&self, int u) -> void {
    if (g[u].empty()) return;
    ll mn_child = 1e18;
    for (auto &v : g[u]) {
      self(self, v);
      mn_child = min(mn_child, a[v]);
    }
    if (!u) return;
    if (mn_child > a[u]) a[u] = (a[u] + mn_child) / 2;
    else a[u] = mn_child;
  };
  dfs(dfs, 0);
  ll mn_child = 1e18;
  for (auto &v : g[0]) mn_child = min(mn_child, a[v]);
  if (g[0].empty()) mn_child = 0;
  cout << a[0] + mn_child << ENDL;
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