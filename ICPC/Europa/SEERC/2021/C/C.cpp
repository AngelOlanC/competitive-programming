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

constexpr int MOD = 998244353;

signed main() {
  cin.tie(0)->sync_with_stdio(0);
  int n;
  cin >> n;
  vi c(n);
  FOR (i, 0, n) {
    cin >> c[i];
    --c[i];
  }
  vector<vi> g(n);
  FOR (i, 1, n) {
    int u, v;
    cin >> u >> v;
    g[--u].pb(--v), g[v].pb(u);
  }
  vi topo, p(n);
  queue<int> q; q.push(0);
  while (!q.empty()) {
    int u = q.front(); q.pop();
    topo.pb(u);
    for (auto &v : g[u]) if (v != p[u]) {
      p[v] = u;
      q.push(v);
    }
  }
  reverse(ALL(topo));
  vi sz(n, 1);
  for (auto &u : topo) if (u) sz[p[u]] += sz[u];
  const int OFF = n + 5;
  vector<vi> dp(n, vi(2 * OFF));
  vi aux(2 * OFF);
  int ans = 0;
  FOR (col, 0, n) {
    int cnt_c=0;
    FOR(i,0,n)cnt_c+=c[i]==col;
    for (auto &u : topo) {
      int stsz = 1, mn = min(sz[u], cnt_c);
      FOR(i,-cnt_c,cnt_c+1)dp[u][i+OFF]=aux[i+OFF]=0;
      if (c[u] == col) aux[1+OFF] = dp[u][1+OFF] = 1;
      else aux[-1 + OFF] = dp[u][-1 + OFF] = 1;
      for (auto &v : g[u]) if (v != p[u]) {
        int mn2 = min(stsz, cnt_c), mn3 = min(sz[v], cnt_c);
        FOR (i, -mn2, mn2 + 1) {
          for (int j = max(-mn3, -mn - i); j <= mn3 && i + j <= mn; ++j) {
            dp[u][i+j+OFF]=(dp[u][i+j+OFF]+(ll)dp[v][j+OFF]*aux[i+OFF]%MOD)%MOD;
          }
        }
        FOR (i, -mn, mn + 1) aux[i+OFF]=dp[u][i+OFF];
        stsz += sz[v];
      }
    }
    FOR(i,0,n)FOR(j,1,cnt_c+1)ans=(ans+dp[i][j+OFF])%MOD;
  }
  cout << ans << ENDL;

  return 0;
}