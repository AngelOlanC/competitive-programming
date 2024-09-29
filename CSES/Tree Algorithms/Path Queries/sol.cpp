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

#define NEUT 0
struct STree {
  int n; vector<ll> st;
  STree() {}
  STree(int n) : st(4 * n + 5, NEUT), n(n) {}
  ll comb(ll x, ll y) { return x + y; }
  void init(int k, int s, int e, int *a) {
    if (s + 1 == e) { st[k] = a[s]; return; }
    int m = (s+e)/2;
    init(2*k+1, s, m, a); init(2*k+2, m, e, a);
    st[k] = comb(st[2*k+1], st[2*k+2]);
  }
  ll query(int k, int s, int e, int a, int b) {
    if (a <= s && e <= b) return st[k];
    if (e <= a || s >= b) return NEUT;
    int m = (s+e)/2;
    return comb(query(2*k+1,s,m,a,b),query(2*k+2,m,e,a,b));
  }
  void upd(int k, int s, int e, int i, int v) {
    if (e <= i || s > i) return;
    if (s+1 == e) { st[k] = v; return; }
    int m = (s+e)/2;
    upd(2*k+1,s,m,i,v); upd(2*k+2,m,e,i,v);
    st[k] = comb(st[2*k+1], st[2*k+2]);
  }
  ll query(int a, int b) { return query(0, 0, n, a, b); }
  void upd(int i, int v) { upd(0, 0, n, i, v); }
  void init(int *a) { init(0, 0, n, a); }
};

constexpr int maxn = 2e5 + 5;

int N, Q;
vi G[maxn];
int UP[maxn];
int SZ[maxn];
int D[maxn];

int dfs_size(int u, int p) {
  SZ[u] = 1, UP[u] = p, D[u] = D[p] + 1;
  for (auto &v : G[u]) if (v != p) SZ[u] += dfs_size(v, u);
  return SZ[u];
}

int A[maxn];
int A_ST[maxn];
int H[maxn];
int P[maxn];
int id;

void decompose(int u, int p) {
  P[u] = -1;
  for (auto &v : G[u]) if (v != p) {
    H[v] = 2 * SZ[v] >= SZ[u] ? H[u] : v;
    decompose(v, u);
  }
  if (P[u] == -1) {
    while (u != H[u]) {
      P[u] = id++;
      A_ST[P[u]] = A[u];
      u = UP[u];
    }
    P[u] = id++;
    A_ST[P[u]] = A[u];
  }
}

STree st;

ll query(int u, int v) {
  ll ans = 0;
  while (H[u] != H[v]) {
    if (D[H[u]] < D[H[v]]) swap(u, v);
    ans += st.query(P[u], P[H[u]] + 1);
    u = UP[H[u]];
  }
  if (D[u] < D[v]) swap(u, v);
  ans += st.query(P[u], P[v] + 1);
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
  st = STree(N);
  st.init(A_ST);
  while (Q--) {
    int op;
    cin >> op;
    if (op == 1) {
      int u, x;
      cin >> u >> x;
      --u;
      st.upd(P[u], x);
      continue;
    }
    int u;
    cin >> u;
    --u;
    cout << query(0, u) << ENDL;
  }
  return 0;
}