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
  
#define NEUT -1
struct STree {
  int n; vi st;
  STree(int n) : st(4 * n + 5, NEUT), n(n) {}
  int comb(int x, int y) { return max(x, y); }
  void init(int k, int s, int e, vi& a) {
    if (s + 1 == e) { st[k] = a[s]; return; }
    int m = (s+e)/2;
    init(2*k+1, s, m, a); init(2*k+2, m, e, a);
    st[k] = comb(st[2*k+1], st[2*k+2]);
  }
  int query(int k, int s, int e, int x) {
    if (s + 1 == e) return st[k] >= x ? s : NEUT;
    int m = (s+e)/2;
    return st[2*k+1] >= x ? query(2*k+1,s,m,x) : query(2*k+2,m,e,x);
  }
  void upd(int k, int s, int e, int i, int v) {
    if (e <= i || s > i) return;
    if (s+1 == e) { st[k] -= v; return; }
    int m = (s+e)/2;
    upd(2*k+1,s,m,i,v); upd(2*k+2,m,e,i,v);
    st[k] = comb(st[2*k+1], st[2*k+2]);
  }
  int query(int x) { return query(0, 0, n, x); }
  void upd(int i, int v) { upd(0, 0, n, i, v); }
  void init(vi& a) { init(0, 0, n, a); }
};

signed main() {
  cin.tie(0)->sync_with_stdio(0);

  int n, m;
  cin >> n >> m;
  vi h(n), ans(m);
  FOR (i, 0, n) cin >> h[i];
  STree st(n);
  st.init(h);
  FOR (i, 0, m) {
    int r;
    cin >> r;
    int j = st.query(r);
    cout << j + 1 << " \n"[i == m - 1];
    if (~j) st.upd(j, r);
  }

  return 0;
}