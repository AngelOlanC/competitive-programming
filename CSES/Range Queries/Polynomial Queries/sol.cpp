#include <bits/stdc++.h>
using namespace std;
// Pura Gente del Coach Moy
 
using i64 = long long;
 
i64 gauss(int n) {
  return (i64)n * (n + 1) >> 1;
}
 
struct STree {
  #define ls (k << 1) + 1
  #define rs (k << 1) + 2
  #define lp ls, s, m
  #define rp rs, m, e
 
  int n;
  vector<i64> st;
  vector<vector<int>> lazy;
 
  STree(int n) : n(n), st((n << 2) + 5), lazy((n << 2) + 5) {}
 
  i64 merge(i64 x, i64 y) {
    return x + y;
  }
 
  void pull(int k) {
    st[k] = merge(st[ls], st[rs]);
  }
 
  void apply(int k, int s, int e, int v) {
    // [4, 7) gauss(6) - gauss(3) 1+2+3+4+5+6 - 1+2+3
    st[k] += gauss(v + e - s - 1) - gauss(v - 1);
    // cout << s << ' ' << e << ' ' << v << " suma " << gauss(v + e - s - 1) - gauss(v - 1) << '\n';
    lazy[k].push_back(v);
  }
 
  void push(int k, int s, int e) {
    if (!lazy[k].empty()) {
      int m = (s + e) >> 1;
      for (int x : lazy[k]) {
        apply(lp, x);
        apply(rp, x + m - s);
        // 3  [4, 5)
      }
      lazy[k].clear();
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
 
  void upd(int k, int s, int e, int a, int b, int v) {
    if (a <= s && e <= b) {
      // cout << "apply " << s << ' ' << e << ' ' << v << '\n';
      apply(k, s, e, v + s - a);
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
};
 
int main() {
  cin.tie(0)->sync_with_stdio(0);
 
  int n, q;
  cin >> n >> q;
 
  STree st(n);
  for (int i = 0; i < n; ++i) {
    int x;
    cin >> x;
    st.upd(i, i + 1, x);
  }

  // cout << '\n';
  // cout << st.query(0, n) << '\n';
 
  while (q--) {
    int t, a, b;
    cin >> t >> a >> b;
    --a;
 
    if (t == 1) {
      // cout << '\n';
      st.upd(a, b, 1);
    } else {
      cout << st.query(a, b) << '\n';
    }
  }
 
  return 0;
}