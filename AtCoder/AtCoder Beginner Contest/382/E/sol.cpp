#include <bits/stdc++.h>
using namespace std;
// Pura gente del coach moy
using i64 = long long;
struct STree {
  #define lson  (k << 1) + 1
  #define rson  (k << 1) + 2
  #define lpart lson, s, m
  #define rpart rson, m, e
  int n;
  vector<i64> st, lazy;
  STree(int n) : n(n), st(4 * n + 5), lazy(4 * n + 5) {}
  void apply(int k, int s, int e, i64 v) {
    lazy[k] += v;
    st[k] += v * (e - s); 
  }
  void push(int k, int s, int e) {
    if (s + 1 != e && lazy[k]) {
      int m = (s + e) >> 1;
      apply(lson, s, m, lazy[k]);
      apply(rson, m, e, lazy[k]);
    }
    lazy[k] = 0;
  }
  void pull(int k) {
    st[k] = st[lson] + st[rson];
  }
  void upd(int k, int s, int e, int a, int b, int x) {
    if (s >= a && e <= b) {
      apply(k, s, e, x);
      return;
    }
    push(k, s, e);
    int m = (s + e) >> 1;
    if (m > a) {
      upd(lpart, a, b, x);
    }
    if (m < b) {
      upd(rpart, a, b, x);
    }
    pull(k);
  }
  void upd(int a, int b, int x) {
    upd(0, 0, n, a, b, x);
  }
  i64 query(int k, int s, int e, int i) {
    if (s + 1 == e) {
      return st[k];
    }
    push(k, s, e);
    int m = (s + e) >> 1;
    if (i < m) {
      return query(lpart, i);
    }
    return query(rpart, i);
  }
  i64 query(int i) {
    return query(0, 0, n, i);
  }
};
int main() {
  cin.tie(0)->sync_with_stdio(0);
  int n;
  string s;
  cin >> n >> s;
  STree st(n + 125);
  for (int i = 0; i < n; ++i) {
    int l = i + 1, r = n - i - 1, d = s[i] - '0';
    st.upd(0, r + 1, d * l);
  }
  n += 125;
  vector<int> ans(n);
  i64 carry = 0;
  for (int i = 0; i < n; ++i) {
    i64 x = st.query(i) + carry;
    ans[i] = x % 10;
    carry = x / 10; 
  }
  reverse(ans.begin(), ans.end());
  for (int i = 0; i < n; ++i) {
    if (!ans[i]) {
      continue;
    }
    while (i < (int)ans.size()) {
      cout << ans[i];
      ++i;
    }
    cout << '\n';
    break;
  }
}