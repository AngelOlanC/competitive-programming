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

constexpr int maxn = 2e5 + 5;
const int P[2] = { 29, 33 };
const int M[2] = { (int)1e9 + 7, (int)1e9 + 9 };
const int I[2] = { inverse(P[0], M[0]), inverse(P[1], M[1]) };

int pot[2][maxn], inv[2][maxn];

struct STree {
  #define ls (k << 1) + 1
  #define rs (k << 1) + 2
  #define lp ls, s, m
  #define rp rs, m, e

  int n;
  vector<pair<int, int>> st;

  STree(int n) : n(n), st((n << 2) + 5) {}

  pair<int, int> comb(pair<int, int> a, pair<int, int> b) {
    return {
      add(a.first, b.first, M[0]),
      add(a.second, b.second, M[1])
    };
  }

  void pull(int k) {
    st[k] = comb(st[ls], st[rs]);
  }

  void upd(int k, int s, int e, int i, char x) {
    if (s + 1 == e) {
      st[k] = {
        mul(x - 'a' + 1, pot[0][s], M[0]),
        mul(x - 'a' + 1, pot[1][s], M[1])
      };
      return;
    }
    int m = (s + e) >> 1;
    if (i < m) {
      upd(lp, i, x);
    } else {
      upd(rp, i, x);
    }
    pull(k);
  }
  void upd(int i, char x) {
    upd(0, 0, n, i, x);
  }

  pair<int, int> query(int k, int s, int e, int a, int b) {
    if (a <= s && e <= b) {
      return st[k];
    }
    int m = (s + e) >> 1;
    if (a < m) {
      if (b > m) {
        return comb(query(lp, a, b), query(rp, a, b));
      }
      return query(lp, a, b);
    }
    return query(rp, a, b);
  }
  pair<int, int> query(int a, int b) {
    return query(0, 0, n, a, b);
  }

  i64 hash(int a, int b) {
    auto p = query(a, b);
    int x = mul(p.first, inv[0][a], M[0]), y = mul(p.second, inv[1][a], M[1]);
    return ((i64)x << 32) | y;
  }
};

int main() {
  cin.tie(0)->sync_with_stdio(0);

  int n, q;
  cin >> n >> q;

  pot[0][0] = pot[1][0] = inv[0][0] = inv[1][0] = 1;
  for (int i = 1; i < n; ++i) {
    for (int j = 0; j < 2; ++j) {
      pot[j][i] = mul(pot[j][i - 1], P[j], M[j]);
      inv[j][i] = mul(inv[j][i - 1], I[j], M[j]);
    }
  }

  STree st(n), str(n);
  for (int i = 0; i < n; ++i) {
    char c;
    cin >> c;
    st.upd(i, c);
    str.upd(n - i - 1, c);
  }

  while (q--) {
    int t;
    cin >> t;
    if (t == 1) {
      int k;
      char x;
      cin >> k >> x;
      --k;
      st.upd(k, x);
      str.upd(n - k - 1, x);
      continue;
    }
    int a, b;
    cin >> a >> b;
    --a;
    int m = (a + b) >> 1;
    // cout << "query " << a << ' ' << b << ": " << m << ' ' << b << " y " << n - m - ((b - a) & 1) << ' ' << n - a << '\n';
    cout << (st.hash(m, b) == str.hash(n - m - ((b - a) & 1), n - a) ? "YES" : "NO") << '\n';
  }

  return 0;
}