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

constexpr int MOD = 1e9 + 7;

int be(int a, int b, int m) {
  int res = 1;
  a %= m;
  while (b) {
    if (b & 1) {
      res = 1ll * res * a % m;
    }
    a = 1ll * a * a % m;
    b >>= 1;
  }
  return res;
}

int modInverse(int b) { return be(b, MOD - 2, MOD); }

constexpr int maxn = 1e5 + 5;

int n;
int sz[maxn];
vi g[maxn];

void dfs(int u, int p) {
  sz[u]++;
  for (auto &v : g[u]) if (v != p) {
    dfs(v, u);
    sz[u] += sz[v];
  }
}

signed main() {
  cin.tie(0)->sync_with_stdio(0);

  cin >> n;
  vector<vi> d(n, vi(n, 1e6));
  FOR (i, 1, n) {
    int u, v;
    cin >> u >> v;
    g[--u].pb(--v), g[v].pb(u);
    d[u][v] = d[v][u] = 1;
  }

  FOR (i, 0, n) d[i][i] = 0;
  FOR (k, 0, n) FOR (i, 0, n) FOR (j, 0, n) d[i][j] = min(d[i][j], d[i][k] + d[k][j]);

  int s = 0;
  FOR (i, 0, n) FOR (j, 0, n) {
    cout << d[i][j] << " \n"[j == n - 1];
    s += d[i][j];
  }
  cout << s << ENDL;

  dfs(0, -1);

  int ans = 0;
  FOR (i, 0, n) {
    for (auto &j : g[i]) if (i < j) {
      int u = i, v = j;
      if (sz[u] < sz[v]) swap(u, v);
      ans += 1ll * (sz[0] - sz[u] + 1) * sz[v] % MOD;
      ans %= MOD;
    }
  }
  cout << ans << ENDL;  
  ans = 1ll * ans * modInverse(1ll * n * n % MOD) % MOD;
  cout << ans << ' ' << 20ll * modInverse(5) % MOD << ENDL;

  return 0;
}