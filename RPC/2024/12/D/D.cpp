#include <bits/stdc++.h>
using namespace std;
//Pura gente del coach moy
using i64 = long long;
constexpr int MOD = 1e9 + 7;
inline int sub(int x, int y) {
  int ret = x - y;
  if (ret < 0) {
    ret += MOD;
  }
  return ret;
}
inline int add(int x, int y) {
  if (y < 0) {
    return sub(x, -y);
  }
  int ret = x + y;
  if (ret >= MOD) {
    ret -= MOD;
  }
  return ret;
}
inline int mul(int x, int y) {
  return (i64)x * y % MOD;
}
struct STree {
  #define lson (k << 1) + 1
  #define rson (k << 1) + 2
  #define lpart lson, s, m
  #define rpart rson, m, e
  int n;
  vector<int> st, lazy;
  STree(int n) : n(n), st(4 * n + 5), lazy(4 * n + 5) {}
  void apply(int k, int s, int e, int v) {
    st[k] = add(st[k], mul(v, e - s));
    lazy[k] = add(lazy[k], v);
  }
  void push(int k, int s, int e) {
    if (lazy[k]) {
      int m = (s + e) >> 1;
      apply(lpart, lazy[k]);
      apply(rpart, lazy[k]);
      lazy[k] = 0;
    }
  }
  void upd(int k, int s, int e, int a, int b, int v) {
    if (s >= a && e <= b) {
      apply(k, s, e, v);
      return;
    }
    push(k, s, e);
    int m = (s + e) >> 1;
    if (a < m) {
      upd(lpart, a, b, v);
    }
    if (b > m) {
      upd(rpart, a, b, v);
    }
  }
  void upd(int a, int b, int v) {
    upd(0, 0, n, a, b, v);
  }
  int query(int k, int s, int e, int i) {
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
  int query(int i) {
    return query(0, 0, n, i);
  }
};
int be(int a, int b) {
  int res = 1;
  while (b) {
    if (b & 1) {
      res = mul(res, a);
    }
    a = mul(a, a);
    b >>= 1;
  }
  return res;
}
int inv(int b) {
  return be(b, MOD - 2);
}
int main() {
  cin.tie(0)->sync_with_stdio(0);
  int n, q;
  string sp;
  cin >> n >> q >> sp;
  int p;
  for (int i = (int)sp.size() - 1; i >= 0; --i) {
    if (sp[i] == '.') {
      int len = (int)sp.size() - i - 1;
      int pot10 = 1;
      for (int i = 0; i < len; ++i) {
        pot10 *= 10;
      }
      p = mul(stoi(sp.substr(i + 1, len)), inv(pot10));
      break;
    }
  }
  auto f = [&](int e) -> int {
    return be(sub(1, p), e);
  };
  STree st_left(n), st_right(n);
  for (int i = 0; i < q; ++i) {
    char op;
    cin >> op;
    if (op == '?') {
      int x;
      cin >> x;
      --x;
      int a = mul(st_left.query(x), f(x));
      int b = mul(st_right.query(x), f(n - x - 1));
      int ans = add(a, b);
      cout << ans << '\n';
      continue;
    }
    int b, x;
    cin >> b >> x;
    --x;
    int delta_left = mul(b, inv(f(x))), delta_right = mul(b, inv(f(n - x - 1)));
    if (op == '-') {
      delta_left *= -1;
      delta_right *= -1;
    }
    st_left.upd(x, n, delta_left);
    if (x) {
      st_right.upd(0, x, delta_right);
    }
  }
}