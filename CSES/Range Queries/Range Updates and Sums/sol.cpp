#include <bits/stdc++.h>
using namespace std;
// Pura Gente del Coach Moy

using i64 = long long;

struct STree {
  #define ls (k << 1) + 1
  #define rs (k << 1) + 2
  #define lp ls, s, m
  #define rp rs, m, e

  int n;
  vector<i64> st, lazyInc;
  vector<int> lazyChange;

  STree(int n) : n(n), st((n << 2) + 5), lazyInc((n << 2) + 5), lazyChange((n << 2) + 5) {}

  i64 merge(i64 x, i64 y) {
    return x + y;
  }

  void pull(int k) {
    st[k] = merge(st[ls], st[rs]);
  }

  void apply(int k, int s, int e, i64 inc, int change) {
    if (change) {
      lazyInc[k] = 0;
      lazyChange[k] = change;
      st[k] = (i64)(e - s) * change;
    }
    if (!inc) {
      return;
    }
    st[k] += (e - s) * inc;
    lazyInc[k] += inc;
  }

  void push(int k, int s, int e) {
    if (lazyInc[k] || lazyChange[k]) {
      int m = (s + e) >> 1;
      apply(lp, lazyInc[k], lazyChange[k]);
      apply(rp, lazyInc[k], lazyChange[k]);
      lazyInc[k] = lazyChange[k] = 0;
    }
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

  void upd(int k, int s, int e, int a, int b, int v, bool inc) {
    if (a <= s && e <= b) {
      if (inc) {
        apply(k, s, e, v, 0);
      } else {
        apply(k, s, e, 0, v);
      }
      return;
    }
    push(k, s, e);
    int m = (s + e) >> 1;
    if (a < m) {
      upd(lp, a, b, v, inc);
    }
    if (b > m) {
      upd(rp, a, b, v, inc);
    }
    pull(k);
  }

  i64 query(int a, int b) {
    return query(0, 0, n, a, b);
  }
  void upd(int a, int b, int v, bool inc) {
    upd(0, 0, n, a, b, v, inc);
  }
};

int main() {
  cin.tie(0)->sync_with_stdio(0);

  int n, q;
  cin >> n >> q;

  STree st(n);
  for (int i = 0; i < n; ++i) {
    int x;
    cin >> x;
    st.upd(i, i + 1, x, true);
  }

  while (q--) {
    int op;
    cin >> op;

    int a, b;
    cin >> a >> b;
    --a;

    if (op == 3) {
      cout << st.query(a, b) << '\n';
      continue;
    }
    int x;
    cin >> x;

    st.upd(a, b, x, op == 1);
  }

  return 0;
}