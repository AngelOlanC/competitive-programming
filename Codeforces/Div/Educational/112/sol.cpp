#include <bits/stdc++.h>
using namespace std;
// Pura Gente del Coach Moy y de la Alexbriza

struct STree {
  #define ls (k << 1) + 1
  #define rs (k << 1) + 2
  #define lp ls, s, m
  #define rp rs, m, e

  int n;
  vector<int> st, lazy;

  STree(int n) : n(n), st((n << 2) + 5), lazy((n << 2) + 5) {}

  int merge(int x, int y) {
    return min(x, y);
  }

  void pull(int k) {
    st[k] = merge(st[ls], st[rs]);
  }

  void apply(int k, int s, int e, int v) {
    st[k] += v;
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

  int query() {
    return st[0];
  }
  void upd(int a, int b, int v) {
    upd(0, 0, n, a, b, v);
  }
};

int main() {
  cin.tie(0)->sync_with_stdio(0);

  int n, m;
  cin >> n >> m;

  m = (m - 1) << 1;

  vector<tuple<int, int, int>> a(n);
  for (auto& [l, r, w] : a) {
    cin >> l >> r >> w;
    l = (l - 1) << 1;
    r = (r - 1) << 1;
  }

  #define w(x) get<2>(x)

  sort(a.begin(), a.end(), [&](auto x, auto y) -> bool {
    return w(x) < w(y);
  });

  STree st(m);

  int ans = 1e9;
  for (int pl = 0, pr = 0; pl < n; ++pl) {
    while (pr < n && !st.query()) {
      auto [l, r, w] = a[pr++];
      st.upd(l, r + 1, 1);
    }
    if (st.query()) {
      ans = min(ans, w(a[pr - 1]) - w(a[pl]));
    }
    auto [l, r, w] = a[pl];
    st.upd(l, r + 1, -1);
  }
  cout << ans << '\n';  

  return 0;
}