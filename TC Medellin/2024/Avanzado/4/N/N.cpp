#include <bits/stdc++.h>
using namespace std;

using ll = long long;
using pi = pair<int, int>;
using vi = vector<int>;

#define fi first
#define se second
#define pb push_back
#define SZ(x) ((int)(x).size())
#define ALL(x) begin(x), end(x)
#define FOR(i, a, b) for (int i = (int)a; i < (int)b; ++i)
#define ROF(i, a, b) for (int i = (int)a - 1; i >= (int)b; --i)
#define ENDL '\n'

constexpr ll INF = 1e12;

signed main() {
  cin.tie(0)->sync_with_stdio(0);

  int n, m, q;
  cin >> n >> m >> q;
  
  vector<vector<ll>> a(n, vector<ll>(n, INF));
  while (m--) {
    ll u, v, w;
    cin >> u >> v >> w;
    a[u][v] = min(a[u][v], w);
    a[v][u] = min(a[v][u], w);
  }

  FOR (k, 0, n) {
    FOR (i, 0, n) {
      FOR (j, 0, n) {
        a[i][j] = min(a[i][j], a[i][k] + a[k][j]);
      }
    }
  }

  while (q--) {
    int u, v;
    cin >> u >> v;
    if (a[u][v] == INF) {
      cout << 
    }
  }

  return 0;
}