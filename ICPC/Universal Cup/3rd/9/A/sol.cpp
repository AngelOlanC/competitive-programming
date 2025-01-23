#include <bits/stdc++.h>
using namespace std;
// Pura Gente del Coach Moy

using i64 = long long;

inline int add(int x, int y, int m) {
  int ret = x + y;
  if (ret >= m) {
    ret -= m;
  }
  return ret;
}

inline int sub(int x, int y, int m) {
  int ret = x - y;
  if (ret < 0) {
    ret += m;
  }
  return ret;
}

inline int mul(int x, int y, int m) {
  return (i64) x * y % m;
}

int be(int a, int b, int m) {
  int res = 1;
  while (b) {
    if (b & 1) res = mul(res, a, m);
    a = mul(a, a, m);
    b >>= 1;
  }
  return res;
}

int inverse(int b, int m){
  return be(b, m - 2, m);
}

const int P[2] = { 325255434, 10018302 };
const int M[2] = { 999727999, 1070777777 };
const int I[2] = { inverse(P[0], M[0]), inverse(P[1], M[1]) };

constexpr int maxn = 2e5 + 5;

int pot[2][maxn];
int inv[2][maxn];
int p_pot[2][maxn];

struct STree {
  #define ls (k << 1) + 1
  #define rs (k << 1) + 2
  #define lp ls, s, m
  #define rp rs, m, e

  using T = array<int, 2>;

  int n;
  vector<T> st;
  vector<int> lazy;

  STree(int n) : n(n), st((n << 2) + 5), lazy((n << 2) + 5) {}

  void apply(int k, int s, int e, int x) {
    for (int i = 0; i < 2; ++i) {
      int y = add(x, M[i], M[i]);
      st[k][i] = add(st[k][i], mul(sub(p_pot[i][e], p_pot[i][s], M[i]), y, M[i]), M[i]);
    }
    lazy[k] += x;
  }

  void push(int k, int s, int e) {
    if (!lazy[k]) {
      return;
    }
    int m = (s + e) >> 1;
    apply(lp, lazy[k]);
    apply(rp, lazy[k]);
    lazy[k] = 0;
  }

  T merge(T a, T b) {
    return {
      add(a[0], b[0], M[0]),
      add(a[1], b[1], M[1])
    };
  }

  void pull(int k) {
    st[k] = merge(st[ls], st[rs]);
  }

  void upd(int k, int s, int e, int a, int b, int x) {
    if (a <= s && e <= b) {
      apply(k, s, e, x);
      return;
    }
    push(k, s, e);
    int m = (s + e) >> 1;
    if (a < m) {
      upd(lp, a, b, x);
    }
    if (b > m) {
      upd(rp, a, b, x);
    }
    pull(k);
  }
  void upd(int a, int b, int x) {
    upd(0, 0, n, a, b, x);
  }

  T query(int k, int s, int e, int a, int b) {
    if (a <= s && e <= b) {
      return st[k];
    }
    push(k, s, e);
    int m = (s + e) >> 1;
    if (a < m) {
      if (b > m) {
        return merge(query(lp, a, b), query(rp, a, b));
      }
      return query(lp, a, b);
    }
    return query(rp, a, b);
  }
  T query(int a, int b) {
    return query(0, 0, n, a, b);
  }

  i64 hash(int a, int b, T extra = { 0, 0 }) {
    auto h = query(a, b);
    for (int i = 0; i < 2; ++i) {
      h[i] = add(mul(h[i], inv[i][a], M[i]), extra[i], M[i]);
    }
    return ((i64)h[0] << 32) | h[1];
  }
};

int main() {
  cin.tie(0)->sync_with_stdio(0);

  int n, q, k, b;
  cin >> n >> q >> k >> b;

  pot[0][0] = pot[1][0] = inv[0][0] = inv[1][0] = 1;
  for (int i = 1; i < n; ++i) {
    for (int j = 0; j < 2; ++j) {
      pot[j][i] = mul(pot[j][i - 1], P[j], M[j]);
      inv[j][i] = mul(inv[j][i - 1], I[j], M[j]);
    }
  }

  for (int i = 1; i <= n; ++i) {
    for (int j = 0; j < 2; ++j) {
      p_pot[j][i] = add(p_pot[j][i - 1], pot[j][i - 1], M[j]);
    }
  }

  vector<vector<int>> kb(2, vector<int>(n + 1));
  for (int i = 1; i <= n; ++i) {
    for (int j = 0; j < 2; ++j) {
      kb[j][i] = add(kb[j][i - 1], mul(add(mul(i, k, M[j]), b, M[j]), pot[j][i - 1], M[j]), M[j]);
    }
  }

  STree st(n), str(n);
  for (int i = 0; i < n; ++i) {
    int x;
    cin >> x;
    x += 1000;
    st.upd(i, i + 1, x);
    str.upd(n - i - 1, n - i, x);
  }

  while (q--) {
    int t;
    cin >> t;
    
    if (t == 1) {
      int l, r, v;
      cin >> l >> r >> v;
      --l;
      st.upd(l, r, v);
      str.upd(n - r, n - l, v);
      continue;
    }

    int i;
    cin >> i;
    --i;

    if (!i || i == n - 1) {
      cout << 0 << '\n';
      continue;
    }

    int l = 1, r = min(i, n - i - 1);
    while (l < r) {
      int m = (l + r + 1) >> 1;
      if (st.hash(i + 1, i + 1 + m) == str.hash(n - i, n - i + m, { kb[0][m], kb[1][m] })) {
        l = m;
      } else {
        r = m - 1;
      }
    }

    if (st.hash(i + 1, i + 1 + l) != str.hash(n - i, n - i + l, { kb[0][l], kb[1][l] })) {
      l = 0;
    }
    cout << l << '\n';
  }

  return 0;
}