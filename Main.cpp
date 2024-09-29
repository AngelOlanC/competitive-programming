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

constexpr int LAZY_NEUT = -1e9 - 5;
#define NEUT 0
struct STree {
  vector<ll> st;
  vi lazy, L, R; int n, sz, rt;
  STree(int n):st(1,NEUT),lazy(1, LAZY_NEUT),L(1,0),R(1,0),n(n),rt(0),sz(1){}
  ll comb(ll x, ll y) { return x + y; }
  int new_node(ll v, int l = 0, int r = 0) {
    int ks = SZ(st); st.pb(v);L.pb(l);R.pb(r); lazy.pb(LAZY_NEUT);
    return ks;
  }
  int init(int s, int e, vi &a) {
    if (s + 1 == e)return new_node(a[s]);
    int m = (s+e)/2, l = init(s,m,a), r = init(m,e,a);
    return new_node(comb(st[l], st[r]), l, r);
  }
  void push(int k, int s, int e) {
    if (lazy[k] == LAZY_NEUT) return;
    st[k] = (ll)(e - s) * lazy[k];
    if (s + 1 != e) {
      int m = (s + e) / 2;
      L[k] = new_node(L[k], s, m), R[k] = new_node(R[k], s, m);
      lazy[L[k]] = lazy[R[k]] = lazy[k];
    }
    lazy[k] = LAZY_NEUT;
  }
  int upd(int k, int s, int e, int a, int b, int v) {
    push(k, s, e);
    if (e <= a || b <= s) return k;
    int ks = new_node(st[k], L[k], R[k]);
    if (a <= s && e <= b) { lazy[ks] = v; return ks; }
    int m = (s + e) / 2;
    L[ks] = upd(L[ks], s, m, a, b, v), R[ks] = upd(R[ks], m, e, a, b, v);
    st[ks] = comb(st[L[ks]], st[R[ks]]);
    return ks;
  }
  ll query(int k, int s, int e, int a, int b) {
    push(k, s, e);
    if (e <= a || b <= s)return NEUT;
    if (a <= s && e <= b)return st[k];
    int m = (s + e) / 2;
    return comb(query(L[k],s,m,a,b),query(R[k],m,e,a,b));
  }
  int init(vi &a) { return rt=init(0, n, a); }
  int upd(int k, int a, int b, int v){return rt=upd(k,0,n,a,b,v);}
  int upd(int a, int b, int v){return rt=upd(rt,a,b,v);}
  ll query(int k, int a, int b){return query(k,0,n,a,b);};
  ll query(int a, int b){return query(rt, a, b);};
};


signed main() {
  cin.tie(0)->sync_with_stdio(0);
  
  int n, k;
  cin >> n >> k;

  vi a(n);
  FOR (i, 0, n) cin >> a[i];

  vi roots;
  STree st(n);
  roots.pb(st.init(a));

  int last_root = roots[0];
  while (k--) {
    char op;
    cin >> op;
    if (op == 'U') {
      int l, r, x;
      cin >> l >> r >> x;
      last_root = st.upd(last_root, l - 1, r, x);
      roots.pb(last_root);
      continue;
    }
    if (op == 'Q') {
      int l, r;
      cin >> l >> r;
      cout << st.query(last_root, l - 1, r) << ENDL;
      continue;
    }
    int x;
    cin >> x;
    last_root = roots[x];
  }
  return 0;
}