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

struct DSU {
  vector<int> e;
  vector<pair<int, int>> st;
  void init(int n) { e = vi(n, -1); }
  int size(int x) { return -e[get(x)]; }
  int get(int x) { return e[x] < 0 ? x : e[x] = get(e[x]); }
  bool join(int a, int b) {
    a = get(a), b = get(b);
    if (a == b)
      return false;
    if (e[a] > e[b])
      swap(a, b);
    e[a] += e[b];
    e[b] = a;
    return true;
  }
};

constexpr int maxn = 1e5 + 5, maxlog = 28;
vector<pi> g[maxn];
int jmp[maxn][maxlog];
int val[maxn][maxlog];
int depth[maxn];

void dfs(int u, int p = -1, int vp = 0, int d = 0) {
  depth[u] = d;
  jmp[u][0] = p;
  val[u][0] = vp;
  for (auto &[v, w] : g[u]) if (v != p) dfs(v, u, w, d + 1);
}

void build(int n) {
  dfs(0);

  for (int i = 1; i < maxlog; i++)
    for (int u = 0; u < n; u++)
      if (jmp[u][i - 1] != -1) {
        jmp[u][i] = jmp[jmp[u][i - 1]][i - 1];
        val[u][i] = max(val[u][i - 1], val[jmp[u][i - 1]][i - 1]);
      }
}

int query(int p, int q) {
  if (depth[p] < depth[q])
    swap(p, q);

  int ans = 0;
  int dist = depth[p] - depth[q];
  for (int i = maxlog - 1; i >= 0; i--)
    if ((dist >> i) & 1)
      ans = max(ans, val[p][i]), p = jmp[p][i];

  if (p == q)
    return ans;

  for (int i = maxlog - 1; i >= 0; i--)
    if (jmp[p][i] != jmp[q][i]) {
      ans = max(ans, val[p][i]);
      ans = max(ans, val[q][i]);
      p = jmp[p][i];
      q = jmp[q][i];
    }
  ans = max(ans, val[p][0]);
  ans = max(ans, val[q][0]);
  return ans;
}

signed main() {
  cin.tie(0)->sync_with_stdio(0);

  int n;
  cin >> n;
  
  vector<vi> a(n, vi(n));
  FOR (i, 0, n) {
    FOR (j, 0, n) {
      cin >> a[i][j];
    }
  }

  auto bad = [&]() -> void {
    cout << "NOT MAGIC" << ENDL;
    exit(0);
  };

  FOR (i, 0, n) {
    if (a[i][i]) bad();
    FOR (j, 0, n) {
      if (a[i][j] != a[j][i]) bad();
    }
  }

  vector<array<int, 3>> e;
  FOR (i, 0, n) {
    FOR (j, 0, n) {
      e.pb({a[i][j], i, j});
    }
  }

  sort(ALL(e));

  DSU dsu;
  dsu.init(n);

  for (auto &[w, u, v] : e) if (dsu.get(u) != dsu.get(v)) {
    g[u].pb({v, w}), g[v].pb({u, w});
    dsu.join(u, v);

    // cout << "taking " << u << ' ' << v << ' ' << w << ENDL;
  }

  build(n);

  FOR (i, 0, n) {
    FOR (j, i + 1, n) {
      // cout << i << ' ' << j << ' ' << a[i][j] << ' ' << query(i, j) << ENDL;
      if (query(i, j) != a[i][j]) bad();
    }
  }
  cout << "MAGIC" << ENDL;

  return 0;
}