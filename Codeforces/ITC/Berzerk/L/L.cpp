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

int add(int a, int b) {
  return a + b >= MOD ? a + b - MOD : a + b;
}

int sub(int a, int b) {
  return a < b ? a - b + MOD : a - b;
}

int mul(int a, int b) {
  return 1ll * a * b % MOD;
}

int be(int a, int b, int m) {
  int res = 1;
  while (b) {
    if (b & 1) res = mul(res, a);
    a = mul(a, a);
    b >>= 1;
  }
  return res;
}

int modInverse(int b) { return be(b, MOD - 2, MOD); }

constexpr int maxn = 200005;

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
  FOR (i, 1, n) {
    int u, v;
    cin >> u >> v;
    g[--u].pb(--v), g[v].pb(u);
  }

  dfs(0, -1);

  int ans = 0;
  FOR (i, 0, n) {
    for (auto &j : g[i]) if (i < j) {
      int u = i, v = j;
      if (sz[u] < sz[v]) swap(u, v);
      ans = add(ans, mul(sz[0] - sz[v], sz[v]));
    }
  }
  ans = mul(ans, modInverse(mul(mul(n, n + 1), modInverse(2))));
  cout << ans << ENDL;

  return 0;
}