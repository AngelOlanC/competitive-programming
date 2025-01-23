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
  vector<i64> sum;
  vector<int> lazy;
  
  STree(int n) : n(n), sum((n << 2) + 5), lazy((n << 2) + 5) {}

  void pull(int k) {
    sum[k] = sum[ls] + sum[rs];
  }

  void apply(int k, int x) {
    sum[k] <<= x;
    lazy[k] += x;
  }

  void push(int k) {
    if (!lazy[k]) {
      return;
    }
    apply(ls, lazy[k]);
    apply(rs, lazy[k]);
    lazy[k] = 0;
  }

  void build(int k, int s, int e) {
    if (s + 1 == e) {
      sum[k] = 1;
      return;
    }
    int m = (s + e) >> 1;
    build(lp);
    build(rp);
    pull(k);
  }
  void build() {
    build(0, 0, n);
  }

  void upd(int k, int s, int e, i64 a, i64 b) {
    if (s + 1 == e) {
      sum[k] += min(sum[k], b) - max(a - 1, 0ll); 
      return;
    }
    if (a <= 0 && sum[k] <= b) {
      apply(k, 1);
      return;
    }
    push(k);
    int m = (s + e) >> 1;
    if (sum[ls] < a) {
      upd(rp,  a - sum[ls], b - sum[ls]);
      pull(k);
      return;
    }
    if (b > sum[ls]) {
      upd(rp, a - sum[ls], b - sum[ls]);
    }
    upd(lp, a, b);
    pull(k);
  }
  void upd(i64 a, i64 b) {
    upd(0, 0, n, a, b);
  }

  int query(int k, int s, int e, i64 x) {
    if (s + 1 == e) {
      return s;
    }
    push(k);
    int m = (s + e) >> 1;
    if (sum[ls] >= x) {
      return query(lp, x);
    }
    return query(rp, x - sum[ls]);
  }
  int query(i64 x) {
    return query(0, 0, n, x);
  }
};

signed main() {
  cin.tie(0)->sync_with_stdio(0);

  int n, q;
  string s;
  cin >> n >> q >> s;

  STree st(n);
  st.build();

  while (q--) {
    int t;
    cin >> t;
    if (t == 2) {
      i64 x;
      cin >> x;
      cout << s[st.query(x)] << '\n';
      continue;
    }
    i64 a, b;
    cin >> a >> b;
    st.upd(a, b);
  }

  return 0;
}