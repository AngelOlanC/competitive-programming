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

using pll = pair<ll, ll>;

#define NEUT 0
struct STree {
  int n; vector<pll> st;
  STree(int n) : st(4 * n + 5, {0, 0}), n(n) {}
  pll comb(pll x, pll y) {return {x.first+y.first,max(x.second,x.first+y.second)};}
  void init(int k, int s, int e, vi& a) {
    if (s + 1 == e) { st[k] = {a[s], a[s]}; return; }
    int m = (s+e)/2;
    init(2*k+1, s, m, a); init(2*k+2, m, e, a);
    st[k] = comb(st[2*k+1], st[2*k+2]);
    // cout << s << ' ' << e << ' ' << st[k].first << ' ' << st[k].second << ENDL;
  }
  ll query(int k, int s, int e, int a, int b, ll& sum) {
    // cout << s << ' ' << e << ' ' << sum << ENDL;
    if (a <= s && e <= b) {sum+=st[k].first;return sum-st[k].first+st[k].second;}
    if (e <= a || s >= b) return NEUT;
    int m = (s+e)/2;
    ll vl = query(2*k+1,s,m,a,b,sum), vr = query(2*k+2,m,e,a,b,sum);
    return max(vl, vr);
  }
  void upd(int k, int s, int e, int i, int v) {
    if (e <= i || s > i) return;
    if (s+1 == e) { st[k] = {v, v}; return; }
    int m = (s+e)/2;
    upd(2*k+1,s,m,i,v); upd(2*k+2,m,e,i,v);
    st[k] = comb(st[2*k+1], st[2*k+2]);
  }
  ll query(int a, int b) { ll sum = 0; return query(0, 0, n, a, b, sum); }
  void upd(int i, int v) { upd(0, 0, n, i, v); }
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
    int op, a, b;
    cin >> op >> a >> b;
    if (op == 1) st.upd(a - 1, b);
    else cout << max(0ll, st.query(a - 1, b)) << ENDL;
  }

  return 0;
}