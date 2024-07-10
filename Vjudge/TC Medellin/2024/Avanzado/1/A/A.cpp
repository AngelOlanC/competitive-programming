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

ll be(ll a, ll b, ll m) {
  ll res = 1;
  a %= m;
  while (b) {
    if (b & 1) {
      res = res * a % m;
    }
    a = a * a % m;
    b >>= 1;
  }
  return res;
}


ll modInverse(ll b, ll m) { return be(b, m - 2, m) % m; }

constexpr ll MOD = 1e9 + 7;

void solve(int test_case) {
  int n;
  cin >> n;
  vector<vi> g(n);
  FOR (i, 1, n) {
    int u, v;
    cin >> u >> v;
    u--, v--;
    g[u].pb(v);
    g[v].pb(u);
  }
  ll s = 0;
  auto dfs = [&](auto &&self, int u, int p) -> int {
    int d = 0;
    for (auto &v : g[u]) if (v != p) {
      d = max(d, self(self, v, u));
    }
    s += d + 1;
    s %= MOD;
    return d + 1;
  };
  
  dfs(dfs, 0, -1);
  ll ans = be(2, n, MOD) * s % MOD;
  ans = ans * modInverse(2, MOD) % MOD;

  cout << ans << ENDL;
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