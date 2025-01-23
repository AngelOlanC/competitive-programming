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

struct STree {
  #define ls (k << 1) + 1
  #define rs (k << 1) + 2
  #define lp ls, s, m
  #define rp rs, m, e

  int n;
  vector<int> st;

  STree(int n) : n(n), st((n << 2) + 5) {}

  int merge(int x, int y) {
    return min(x, y);
  }

  void pull(int k) {
    st[k] = merge(st[ls], st[rs]);
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

  int query(int k, int s, int e, int a, int b) {
    if (a <= s && e <= b) {
      return st[k];
    }
    int m = (s + e) >> 1;
    if (a >= m) {
      return query(rp, a, b);
    }
    if (b <= m) {
      return query(lp, a, b);
    }
    return merge(query(lp, a, b), query(rp, a, b));
  }

  void upd(int k, int s, int e, int i, int v) {
    if (s + 1 == e) {
      st[k] = v;
      return;
    }
    int m = (s + e) >> 1;
    if (i < m) {
      upd(lp, i, v);
    } else {
      upd(rp, i, v);
    }
    pull(k);
  }

  int query(int a, int b) {
    return query(0, 0, n, a, b);
  }
  void upd(int i, int v) {
    upd(0, 0, n, i, v);
  }
  void build(vector<int>& a) {
    build(0, 0, n, a);
  }
};

signed main() {
  cin.tie(0)->sync_with_stdio(0);

  int n, q;
  cin >> n >> q;
  vi a(n), b(n), c(n);
  FOR (i, 0, n) {
    cin >> a[i];
    b[i] = a[i] + i;
    c[i] = a[i] + n - i;
  }
  STree stl(n), str(n); stl.build(c); str.build(b);
  while (q--) {
    int t;
    cin >> t;
    if (t == 1) {
      int k, x;
      cin >> k >> x;
      --k;
      str.upd(k, x + k), stl.upd(k, x + n - k);
      continue;
    }
    int k;
    cin >> k;
    --k;
    int l = stl.query(0, k + 1) - (n - k), r = str.query(k, n) - k;
    cout << min(l, r) << ENDL; 
  }

  return 0;
}