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

template <typename T>
pair<T, vi> hungarian(const vector<vector<T>> &a) {
#define INF numeric_limits<T>::max()
  if (a.empty()) return {0, {}};
  int n = SZ(a) + 1, m = SZ(a[0]) + 1;
  vi p(m), ans(n - 1);
  vector<T> u(n), v(m);
  FOR(i, 1, n) {
    p[0] = i;
    int j0 = 0;  // agregar trabajador "dummy" 0
    vector<T> dist(m, INF);
    vi pre(m, -1);
    vector<bool> done(m + 1);
    do {  // dijkstra
      done[j0] = true;
      int i0 = p[j0], j1;
      T delta = INF;
      FOR(j, 1, m)
      if (!done[j]) {
        auto cur = a[i0 - 1][j - 1] - u[i0] - v[j];
        if (cur < dist[j]) dist[j] = cur, pre[j] = j0;
        if (dist[j] < delta) delta = dist[j], j1 = j;
      }
      FOR(j, 0, m) {
        if (done[j])
          u[p[j]] += delta, v[j] -= delta;
        else
          dist[j] -= delta;
      }
      j0 = j1;
    } while (p[j0]);
    while (j0) {  // actualizar camino alternativo
      int j1 = pre[j0];
      p[j0] = p[j1], j0 = j1;
    }
  }
  FOR(j, 1, m)
  if (p[j]) ans[p[j] - 1] = j - 1;
  return {-v[0], ans};
}

signed main() {
  ios_base::sync_with_stdio(0);
  cin.tie(nullptr);

  int n, m;
  cin >> n >> m;
  int c[n][m];
  FOR (i, 0, n) {
    FOR (j, 0, m) {
      cin >> c[i][j];
    }
  }

  vector<vi> g(n, vi(n));
  FOR (i, 0, n) {
    FOR (j, 0, n) {
      cin >> g[i][j];
      if (g[i][j] == -1) {
        g[i][j] = 1e7;
      }
    }
  }

  FOR (k, 0, n) {
    FOR (i, 0, n) {
      FOR (j, 0, n) {
        g[i][j] = min(g[i][j], g[i][k] + g[k][j]);
      }
    }
  }

  vector<vi> gr(m, vi(n, 0));
  FOR (i, 0, n) {
    FOR (j, 0, n) {
      FOR (k, 0, m) {
        gr[k][j] = gr[k][j] + 1ll * g[i][j] * c[i][k];
      }
    }
  }
  cout << hungarian<int>(gr).first << ENDL;


  return 0;
}