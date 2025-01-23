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

using i64 = long long;

struct STree {
  #define ls (k << 1) + 1
  #define rs (k << 1) + 2
  #define lp ls, s, m
  #define rp rs, m, e

  int n;
  vector<i64> st, lazy;

  STree(int n) : n(n), st((n << 2) + 5), lazy((n << 2) + 5) {}

  i64 merge(i64 x, i64 y) {
    return x + y;
  }

  void pull(int k) {
    st[k] = merge(st[ls], st[rs]);
  }

  void apply(int k, int s, int e, i64 v) {
    st[k] += (e - s) * v;
    lazy[k] += v;
  }

  void push(int k, int s, int e) {
    if (lazy[k]) {
      int m = (s + e) >> 1;
      apply(lp, lazy[k]);
      apply(rp, lazy[k]);
      lazy[k] = 0;
    }
  }

  void build(int k, int s, int e, vector<int>& a) {
    if (s + 1 == e) {
      st[k] = a[s];
      return;
    }
    int m = (s + e) >> 1;
    build(lp, a);
    build(rp, a);
    pull(k);
  }

  i64 query(int k, int s, int e, int a, int b) {
    if (a <= s && e <= b) {
      return st[k];
    }
    push(k, s, e);
    int m = (s + e) >> 1;
    if (a >= m) {
      return query(rp, a, b);
    }
    if (b <= m) {
      return query(lp, a, b);
    }
    return merge(query(lp, a, b), query(rp, a, b));
  }

  void upd(int k, int s, int e, int a, int b, int v) {
    if (a <= s && e <= b) {
      apply(k, s, e, v);
      return;
    }
    push(k, s, e);
    int m = (s + e) >> 1;
    if (a < m) {
      upd(lp, a, b, v);
    }
    if (b > m) {
      upd(rp, a, b, v);
    }
    pull(k);
  }

  i64 query(int a, int b) {
    return query(0, 0, n, a, b);
  }
  void upd(int a, int b, int v) {
    upd(0, 0, n, a, b, v);
  }
  void build(vector<int>& a) {
    build(0, 0, n, a);
  }
};

signed main() {
  cin.tie(0)->sync_with_stdio(0);
  
  int n, q;
  cin >> n >> q;
  vi a(n);
  FOR (i, 0, n) cin >> a[i];
  STree st(n); st.build(a);
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