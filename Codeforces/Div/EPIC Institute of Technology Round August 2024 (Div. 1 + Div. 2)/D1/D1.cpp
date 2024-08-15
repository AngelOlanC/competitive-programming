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
  int n, q;
  cin >> n >> q;
  vector<vi> g(n);
  vi a(n);
  a[0] = -1;
  FOR (i, 1, n) {
    cin >> a[i];
    g[--a[i]].pb(i);
  }
  vi p(n), rp(n);
  FOR (i, 0, n) {
    cin >> p[i];
    rp[--p[i]] = i;
  }
  vi stsz(n);
  auto dfs = [&](auto &&self, int u) -> void {
    stsz[u]++;
    for (auto &v : g[u]) {
      self(self, v);
      stsz[u] += stsz[v];
    }
  };
  dfs(dfs, 0);
  vi good(n);
  auto check = [&](int i) -> bool {
    if (g[p[i]].empty()) return true;
    int d = (stsz[p[i]] - 1) / 2;
    int g1 = i + 1 < n && a[p[i + 1]] == p[i] && good[i + 1];
    int g2 = i + 1 + d < n && a[p[i + 1 + d]] == p[i] && good[i + 1 + d];
    return g1 && g2;
  };
  ROF (i, n, 0) good[i] = check(i);
  // cout << n << ' ' << q << ENDL;
  // FOR (i, 0, n) cout << good[i] << " \n"[i == n -1];
  while (q--) {
    int x, y;
    cin >> x >> y;
    --x, --y;
    swap(rp[p[x]], rp[p[y]]);
    swap(p[x], p[y]);
    good[x] = good[y] = 0;
    x = p[x], y = p[y];
    while (x != -1) good[rp[x]] = check(rp[x]), x = a[x];
    while (y != -1) good[rp[y]] = check(rp[y]), y = a[y];
    // FOR (i, 0, n) cout << good[i] << " \n"[i == n -1];
    cout << (p[0] == 0 && good[0] ? "YES" : "NO") << ENDL;
  }
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