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

constexpr int maxn = 2e5 + 5;

int N, Q;
int id;
vi G[maxn];
int UP[maxn];
int SZ[maxn];
int D[maxn];
int A[maxn];
int H[maxn];
int P[maxn];
int ST[2 * maxn];

void st_upd(int p, int value) {
  for (ST[p += N] = value; p > 1; p >>= 1) ST[p>>1] = max(ST[p], ST[p ^ 1]);
}

int st_query(int l, int r) {
  int res = 0;
  for (l += N, r += N; l < r; l >>= 1, r >>= 1) {
    if (l&1) res = max(res, ST[l++]);
    if (r&1) res = max(res, ST[--r]);
  }
  return res;
}

int dfs_size(int u, int p) {
  SZ[u] = 1, UP[u] = p, D[u] = D[p] + 1;
  for (auto &v : G[u]) if (v != p) SZ[u] += dfs_size(v, u);
  return SZ[u];
}

void decompose(int u, int p) {
  P[u] = id++, st_upd(P[u], A[u]);
  int hc = -1, hw = 0;
  for (auto &v : G[u]) if (v != p) if (SZ[v] > hw) hc = v, hw = SZ[v];
  if (hc != -1) {
    H[hc] = H[u];
    decompose(hc, u);
  }
  for (auto &v : G[u]) if (v != p && v != hc) {
    H[v] = v;
    decompose(v, u);
  }
}

int query(int u, int v) {
  int ans = 0;
  while (H[u] != H[v]) {
    if (D[H[u]] < D[H[v]]) swap(u, v);
    ans = max(ans, st_query(P[H[u]], P[u] + 1));
    u = UP[H[u]];
  }
  if (D[u] < D[v]) swap(u, v);
  ans = max(ans, st_query(P[v], P[u] + 1));
  return ans;
}

signed main() {
  cin.tie(0)->sync_with_stdio(0);
  cin >> N >> Q;
  FOR (i, 0, N) cin >> A[i];
  FOR (i, 1, N) {
    int u, v;
    cin >> u >> v;
    --u, --v;
    G[u].pb(v), G[v].pb(u);
  }
  dfs_size(0, 0);
  decompose(0, 0);
  while (Q--) {
    int op;
    cin >> op;
    if (op == 1) {
      int u, x;
      cin >> u >> x;
      --u;
      st_upd(P[u], x);
      continue;
    }
    int u, v;
    cin >> u >> v;
    --u, --v;
    cout << query(u, v) << " ";
  }
  cout << ENDL;
  return 0;
}