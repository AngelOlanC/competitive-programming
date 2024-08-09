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

constexpr int maxn = 2500 + 5;

int x[maxn], y[maxn];
pi g[maxn][4];
int c[maxn][4];
bool last_edge_eliminated;
int u, d;
int ap[maxn][maxn];

void reduce(int u, int d, int amount) {
  int v = g[u][d].first;
  g[u][d].second -= amount;
  g[v][(d + 2) % 4].second -= amount;
  last_edge_eliminated = !g[u][d].second;
  // cout << ' ' << x[v] << ' ' << y[v] << ' ' << d << ' ' << g[u][d].second << ENDL;
}

bool advance() {
  int dle = (d + 3) % 4, dri = (d + 1) % 4;
  auto [vle, wle] = g[u][dle];
  auto [vfr, wfr] = g[u][d];
  auto [vri, wri] = g[u][dri];
  int cnt = (wle != 0) + (wfr != 0) + (wri != 0);
  if (cnt == 0) {
    return false;
  }
  if (cnt == 3) {
    reduce(u, d, 1);
    u = vfr;
    return true;
  }
  if (cnt == 2) {
    if (wle) {
      reduce(u, dle, 1);
      u = vle, d = dle;
      return true;
    }
    reduce(u, d, 1);
    u = vfr;
    return true;
  }
  if (wle) {
    reduce(u, dle, 1);
    u = vle, d = dle;
    return true;
  }
  if (wfr) {
    reduce(u, d, 1);
    u = vfr;
    return true;
  }
  reduce(u, dri, 1);
  u = vri, d = dri;
  return true;
}

signed main() {
  cin.tie(0)->sync_with_stdio(0);

  int n, m;
  cin >> n >> m;
  FOR (i, 0, n) cin >> x[i] >> y[i];

  FOR (i, 0, m) {
    int u, v, w;
    cin >> u >> v >> w;
    u--, v--;
    int du;
    if (x[u] == x[v]) {
      du = (y[u] > y[v]) * 2;
    } else {
      du = 1 + (x[u] > x[v]) * 2;
    }
    g[u][du] = {v, w};
    g[v][dv ^ 2] = {u, w};
  }

  char dir;
  cin >> u >> dir;
  --u;

  if (dir == 'N') d = 0;
  else if (dir == 'E') d = 1;
  else if (dir == 'S') d = 2;
  else d = 3;

  // cout << x[u] << ' ' << y[u] << ' ' << d << ENDL;

  stack<pi> st;
  st.push({u, d});
  int c_id = 1;
  c[u][d] = c_id;
  reduce(u, d, 1);
  if (last_edge_eliminated) {
    st.pop();
    c_id++;
  }
  u = g[u][d].first;
  c[u][d] = c_id;
  st.push({u, d});
  while (advance()) {
    // cout << x[u] << ' ' << y[u] << ' ' << d << ENDL;
    if (last_edge_eliminated) {
      while (!st.empty()) {
        st.pop();
      }
      c[u][d] = c_id++;
    }
    if (c[u][d] != c_id) {
      c[u][d] = c_id;
      st.push({u, d});
      continue;
    }
    // cout << "ciclo" << ENDL;
    // se saca del stack y disminuye en todos los caminos
    vector<pi> cycle_edges;
    int min_w = 1e9, last_d = d;
    while (1) {
      auto [uu, dd] = st.top();
      st.pop();
      cycle_edges.pb({uu, last_d});
      // cout << "ARISTA (" << uu << ' ' << g[uu][last_d].first << ' ' << g[uu][last_d].second << ")" << ENDL; 
      // cout << "ARISTA (" << x[uu] << ", " << y[uu] << ", " << last_d << ", " << g[uu][last_d].second << ")" << ENDL; 
      last_d = dd;
      if (uu == u && dd == d) {
        break;
      }
    }
    assert(!cycle_edges.empty());
    // cout << min_w << ENDL;
    while (!st.empty()) {
      st.pop();
    }

    for (auto [uu, dd] : cycle_edges) {
      int a = uu, b = g[uu][dd].first;
      if (a > b) {
        swap(a, b);
      }
      ap[a][b] = 0;
    }

    for (auto [uu, dd] : cycle_edges) {
      int a = uu, b = g[uu][dd].first;
      if (a > b) {
        swap(a, b);
      }
      ap[a][b]++;
    }

    for (auto [uu, dd] : cycle_edges) {
      int a = uu, b = g[uu][dd].first;
      if (a > b) {
        swap(a, b);
      }
      min_w = min(min_w, g[uu][dd].second / ap[a][b]);
    }

    // cout << min_w << ENDL;
    // cout << " ELIMINANDO" << ENDL;
    for (auto [uu, dd] : cycle_edges) {
      reduce(uu, dd, min_w);
    }
    // cout << " ELIMINADOS" << ENDL;
    st.push({u, d});
    c[u][d] = ++c_id;
  }
  cout << x[u] << ' ' << y[u] << ENDL;

  return 0;
}