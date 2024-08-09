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

#define LAZY_NEUT 0
#define VAL_NEUT 0
struct STree {
  int n; vector<ll> st, lazy;
  STree(int n):st(4*n+5,VAL_NEUT),lazy(4*n+5,LAZY_NEUT),n(n){}
  ll comb(ll x, ll y) { return x + y; }
  void init(int k, int s, int e, vi& a) {
    if (s + 1 == e) { st[k] = a[s]; return; }
    int m = (s+e)/2;
    init(2*k+1, s, m, a); init(2*k+2, m, e, a);
    st[k] = comb(st[2*k+1], st[2*k+2]);
  }
  void push(int k, int s, int e) { 
    if (lazy[k] == LAZY_NEUT) return;
    st[k] += lazy[k] * (e - s);
    if(s+1!=e)lazy[2*k+1]+=lazy[k],lazy[2*k+2]+=lazy[k];
    lazy[k] = LAZY_NEUT;
  }
  ll query(int k, int s, int e, int a, int b) {
    push(k, s, e);
    if (a <= s && e <= b) return st[k];
    if (e <= a || s >= b) return VAL_NEUT;
    int m = (s+e)/2;
    return comb(query(2*k+1,s,m,a,b),query(2*k+2,m,e,a,b));
  }
  void upd(int k, int s, int e, int a, int b, int v) {
    push(k, s, e);
    if (e <= a || s >= b) return;
    if (a<=s && e<=b){lazy[k] += v;push(k,s,e);return;}
    int m = (s+e)/2;
    upd(2*k+1,s,m,a,b,v); upd(2*k+2,m,e,a,b,v);
    st[k] = comb(st[2*k+1], st[2*k+2]);
  }
  ll query(int a, int b) { return query(0, 0, n, a, b); }
  void upd(int a, int b, int v) { upd(0, 0, n, a, b, v); }
  void init(vi& a) { init(0, 0, n, a); }
};

signed main() {
  cin.tie(0)->sync_with_stdio(0);
  
  int n, q;
  cin >> n >> q;
  vi a(n);
  FOR (i, 0, n) cin >> a[i];
  STree st(n); st.init(a);
  while (q--) {
    int op;
    cin >> op;
    if (op == 1) {
      int l, r, v;
      cin >> l >> r >> v;
      st.upd(l - 1, r, v);
      continue;
    }
    int k;
    cin >> k;
    cout << st.query(k - 1, k) << ENDL;
  }

  return 0;
}