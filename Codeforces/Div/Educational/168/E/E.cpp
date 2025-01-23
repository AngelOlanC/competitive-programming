#include <bits/stdc++.h>
using namespace std;

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
#define oper(a, b) max(a, b)
template <class T>
struct SegTree {
  int n;
  vector<T> A;
  vector<vector<T>> st;

  inline int lc(int p) { return (p << 1) + 1; }
  inline int rc(int p) { return (p << 1) + 2; }

  void init(vector<T> v) {
    A = v;
    n = SZ(A);
    st.resize(n * 4);
    build(0, 0, n - 1);
  }

  void build(int p, int L, int R) {
    if (L == R) {
      st[p] = {A[L]};
      return;
    }
    int m = (L + R) >> 1;
    build(lc(p), L, m);
    build(rc(p), m + 1, R);
    merge(ALL(st[lc(p)]), ALL(st[rc(p)]), st[p].begin());
  }

  pi merge(pi a, pi b) {
    return {b.second, a.first + b.first};
  }

  T query(int l, int k, int x, int p, int L, int R) { // Minima i tal que i >= l y en [l, i] hay al menos k valores mayores a x
    if (l > R || !k) return {NEUT, NEUT};
    if (L == R) return A[L] > x ? {1, L};
    int m = (L + R) >> 1;
    pi vl = query(l, k, x, l(p), L, R);
    if (vl.first >= x) return vl.first;
    pi vr = query(l, k - vl.first, x, r(p), L, R);
    return merge(vl, vr);
  }
  T query(int l, int k, int x) { return query(l, x, 0, 0, n - 1); }
};

signed main() {
  cin.tie(0)->sync_with_stdio(0);

  int n, q;
  cin >> n >> q;
  vi a(n);
  for (auto &ai : a) cin >> ai;

  SegTree<int> st;
  st.init(a);

  vector<vi> inc(n);
  FOR (x, 1, n + 1) {
    int i = 0, v = 1, cnt = 0;
    while (i < n) {
      int j = st.query(i, v);
      if (j == NEUT) break;
      i = j + 1;
      inc[x - 1].pb(j + 1);
      if (++cnt == x) v++, cnt = 0;
    }
  }
  
  while (q--) {
    int i, x;
    cin >> i >> x;
    cout << (binary_search(ALL(inc[x - 1]), i) ? "YES" : "NO") << ENDL;
  }

  return 0;
}