#include <bits/stdc++.h>
using namespace std;
// Pura Gente del Coach Moy

struct STree {
  #define ls (k << 1) + 1
  #define lp ls, s, m
  #define rs (k << 1) + 2
  #define rp rs, m, e

  int n;
  vector<int> st;
  STree(int n) : n(n), st((n << 2) + 5) {}

  void pull(int k) {
    st[k] = st[ls] + st[rs];
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
  void build(vector<int>& a) {
    build(0, 0, n, a);
  }

  void upd(int k, int s, int e, int i) {
    if (s + 1 == e) {
      st[k] ^= 1;
      return;
    }
    int m = (s + e) >> 1;
    if (i < m) {
      upd(lp, i);
    } else {
      upd(rp, i);
    }
    pull(k);
  }
  void upd(int i) {
    upd(0, 0, n, i);
  }

  int query(int k, int s, int e, int x) {
    if (s + 1 == e) {
      return s;
    }
    int m = (s + e) >> 1;
    if (st[ls] >= x) {
      return query(lp, x);
    }
    return query(rp, x - st[ls]);
  }
  int query(int x) {
    return query(0, 0, n, x);
  }
};

int main() {
  cin.tie(0)->sync_with_stdio(0);

  int n, q;
  cin >> n >> q;

  vector<int> a(n);
  for (int i = 0; i < n; ++i) {
    cin >> a[i];
  }

  STree st(n);
  st.build(a);

  while (q--) {
    int t, x;
    cin >> t >> x;
    if (t == 1) {
      st.upd(x);
    } else {
      cout << st.query(x + 1) << '\n';
    }
  }

  return 0;
}