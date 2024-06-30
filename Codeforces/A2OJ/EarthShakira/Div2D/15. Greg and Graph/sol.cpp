#include <bits/stdc++.h>
using namespace std;
// Pura Gente del Coach Moy
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

constexpr ll INF = 1e16;

signed main() {
  ios_base::sync_with_stdio(0);
  cin.tie(nullptr);

  int n;
  cin >> n;

  int m[n][n];
  FOR (i, 0, n) {
    FOR (j, 0, n) {
      cin >> m[i][j];
    }
  }

  int a[n];
  FOR (i, 0, n) {
    cin >> a[i];
  }

  ll m2[n][n];
  FOR (i, 0, n) {
    m2[i][i] = 0;
    FOR (j, 0, n) {
      m2[i][j] = INF;
    }
  }

  int active[n];
  memset(active, 0, sizeof active);
  ll ans[n];
  ROF (i, n, 0) {
    int x = a[i] - 1;
    active[x] = 1;

    FOR (u, 0, n) if (active[u]) {
      m2[u][x] = m[u][x];
      m2[x][u] = m[x][u];
    }

    FOR (u, 0, n) if (active[u]) {
      FOR (v, 0, n) if (active[v]) {
        m2[u][v] = min(m2[u][v], m2[u][x] + m2[x][v]);
      }
    }

    ans[i] = 0;
    FOR (u, 0, n) {
      FOR (v, 0, n) if (m2[u][v] < INF) {
        ans[i] += m2[u][v];
      }
    }
  }

  FOR (i, 0, n) {
    cout << ans[i] << ' ';
  }
  cout << ENDL;

  return 0;
}