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

#define INF 1e7

template <typename T>
pair<T, vi> hungarian(const vector<vector<T>> &a) {
  if (a.empty()) return {0, {}};
  int n = SZ(a) + 1, m = SZ(a[0]) + 1;
  vi p(m), ans(n - 1, -1);
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

  int n;
  cin >> n;

  vector<vi> a(n, vi(2 * n));
  FOR (i, 0, n) {
    FOR (j, 0, 2 * n) {
      cin >> a[i][j];
    }
  } 

  vector<vi> b(n, vi(2 * n));
  FOR (i, 0, n) {
    FOR (j, 0, 2 * n) {
      cin >> b[i][j];
    }
  }

  int cost = INF;
  vector<string> gate(n);
  vi workstation(2 * n);
  FOR (k, 0, n + 1) {
    vector<vi> aa(n, vi(2 * n, INF)), bb(n, vi(2 * n, INF));
    FOR (i, 0, n) {
      FOR (j, 0, n) {
        bool is_b = j >= k;
        aa[i][2 * j + is_b] = a[i][2 * j + is_b];
        bb[i][2 * j + is_b] = b[i][2 * j + is_b];
      }
    }
    auto [c1, atob1] = hungarian<int>(aa);
    auto [c2, atob2] = hungarian<int>(bb);

    int c = c1 + c2;
    if (c >= cost) {
      continue;
    }
    cost = c;

    FOR (i, 0, n) {
      int b = atob1[i] / 2;
      char ch = b >= k ? 'B' : 'A';
      gate[i] = to_string(b + 1) + ch;
    }
    FOR (i, 0, n) {
      int b = atob2[i] / 2;
      workstation[b] = i + 1;
    }
  }
  cout << cost << ENDL;
  FOR (i, 0, n) {
    int gate_int = stoi(gate[i].substr(0, SZ(gate[i]) - 1)) - 1;
    cout << i + 1 << ' ' << gate[i] << ' ' << workstation[gate_int] << ENDL;
  }

  return 0;
}