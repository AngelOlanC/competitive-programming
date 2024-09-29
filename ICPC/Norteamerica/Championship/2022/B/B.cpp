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

constexpr int maxn = 5e4 + 5, maxlog = 25;

int n, q;
int state[maxn];
int d[maxn];
int jmp[maxn][maxlog];
vi g[maxn];
vector<pi> extra;

void dfs(int u, int p) {
  jmp[u][0] = p;
  FOR (j, 1, maxlog) jmp[u][j] = jmp[jmp[u][j-1]][j-1];
  state[u] = 1;
  for (auto &v : g[u]) if (v != p && state[v] != 2) {
    if (state[v] == 1) {
      extra.pb({u, v});
      continue;
    }
    dfs(v, u);
    d[v] = d[u] + 1;
  }
  state[u] = 2;
}

int lca(int u, int v) {
  if (d[u] > d[v]) swap(u, v);
  int df = d[v] - d[u];
  for (int i = 0; i < maxlog; ++i) if ((df >> i) & 1) u = jmp[u][i];
  if (u == v) return u;
  for (int i = maxlog - 1; i >= 0; --i) if (jmp[u][i] != jmp[v][i]) u = jmp[u][i], v = jmp[v][i];
  return jmp[u][0];
}

int f(int u, int v, int w) {
  int l = lca(u, v);
  return lca(w, l) == l && (lca(u, w) == w || lca(v, w) == w);
}

bool check_path(vi& path) {
  vi vis;
  FOR (i, 0, SZ(path) - 1) {
    int u = path[i], v = path[i + 1];
    if (i % 2 == 0 && u != v) for (auto &w : vis) if (f(u, v, w)) return false;
    vis.pb(u);
  }
  return true;
}

int calc(int u, int v) {
  int ans = 0;
  set<vi> seen;
  FOR (a, 0, 4) {
    FOR (b, 0, 4) {
      FOR (c, 0, 2) {
        vi path;
        path.pb(u);
        FOR (d, 1, 3) if (a & d) {
          auto [x, y] = extra[d - 1];
          if (b & d) swap(x, y);
          path.pb(x), path.pb(y);
        }
        if (a == 3 && c) {
          swap(path[1], path[3]);
          swap(path[2], path[4]);
        }
        path.pb(v);
        if (seen.count(path)) continue;
        seen.insert(path);
        cout << "path ";
        for (auto &x : path) cout << x + 1 << ' ';
        cout << "gives " << check_path(path) << ENDL;;
        ans += check_path(path);
      }
    }
  }
  return ans;
}

signed main() {
  cin.tie(0)->sync_with_stdio(0);

  cin >> n >> q;
  FOR (i, 0, n + 1) {
    int u, v;
    cin >> u >> v;
    --u, --v;
    g[u].pb(v), g[v].pb(u);
  }
  
  dfs(0, 0);

  while (q--) {
    int u, v;
    cin >> u >> v;
    --u, --v;
    cout << calc(u, v) << ENDL;
  }

  return 0;
}