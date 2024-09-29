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
  STree(int n) : st(4 * n + 5, NEUT), n(n) {}
  ll comb(ll x, ll y) { return x + y; }
  void init(int k, int s, int e, vi& a) {
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
  void init(vi& a) { init(0, 0, n, a); }
};

signed main() {
  cin.tie(0)->sync_with_stdio(0);
  int n, q;
  cin >> n >> q;
  vi a(n);
  for (auto &ai : a) cin >> ai;
  vector<vi> g(n);
  FOR (i, 1, n) {
    int u, v;
    cin >> u >> v;
    --u, --v;
    g[u].pb(v), g[v].pb(u);
  }
  vi st(n), en(n), st_a(n);
  {
    int id = -1;
    auto dfs = [&](auto &&self, int u, int p) -> void {
      st[u] = ++id;
      st_a[st[u]] = a[u];
      for (auto &v : g[u]) if (v != p) self(self, v, u);
      en[u] = id;
    };
    dfs(dfs, 0, -1);
  }
  STree stree(n);
  stree.init(st_a);
  while (q--) {
    int op;
    cin >> op;
    int u;
    cin >> u;
    --u;
    if (op == 2) {
      cout << stree.query(st[u], en[u] + 1) << ENDL;
      continue;
    }
    int x;
    cin >> x;
    stree.upd(st[u], x);
  }
  return 0;
}