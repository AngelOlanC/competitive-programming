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

#define NEUT 1e9
struct STree {
  struct node { ll pre, suf, mx, sum; };
  int n; vector<node> st;
  STree(int n) : st(4 * n + 5), n(n) {}
  node comb(node x, node y) {
    ll pre = max(x.pre, x.sum + y.pre); 
    ll suf = max(y.suf, y.sum + x.suf);
    ll mx = max({x.mx, y.mx, x.suf + y.pre});
    ll sum = x.sum + y.sum;
    return {pre, suf, mx, sum};
  }
  void init(int k, int s, int e, vi& a) {
    if (s + 1 == e) { st[k] = {a[s],a[s],a[s],a[s]}; return; }
    int m = (s+e)/2;
    init(2*k+1, s, m, a); init(2*k+2, m, e, a);
    st[k] = comb(st[2*k+1], st[2*k+2]);
  }
  void upd(int k, int s, int e, int i, int v) {
    if (e <= i || s > i) return;
    if (s+1 == e) { st[k] = {v,v,v,v}; return; }
    int m = (s+e)/2;
    upd(2*k+1,s,m,i,v); upd(2*k+2,m,e,i,v);
    st[k] = comb(st[2*k+1], st[2*k+2]);
  }
  ll query() { return max(0ll, st[0].mx); }
  void upd(int i, int v) { upd(0, 0, n, i, v); }
  void init(vi& a) { init(0, 0, n, a); }
};

signed main() {
  cin.tie(0)->sync_with_stdio(0);

  int n, m;
  cin >> n >> m;
  vi a(n);
  FOR (i, 0, n) cin >> a[i];
  STree st(n); st.init(a);
  while (m--) {
    int k, x;
    cin >> k >> x;
    st.upd(k - 1, x);
    cout << st.query() << ENDL;
  }

  return 0;
}