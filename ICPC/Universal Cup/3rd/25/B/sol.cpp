#include <bits/stdc++.h>
using namespace std;
// Pura Gente del Coach Moy

using u64 = unsigned long long;

constexpr u64 AND_NEUT = ULLONG_MAX;

struct STree {
  struct Data {
    u64 f, g;
    Data() : f(0), g(0) {}
    Data(u64 f, u64 g) : f(f), g(g) {}
  };

  #define ls (k << 1) + 1
  #define rs (k << 1) + 2
  #define lp ls, s, m
  #define rp rs, m, e

  int n;
  vector<Data> st;
  vector<u64> lazy;

  STree(int n) : n(n), st((n << 2) + 5), lazy((n << 2) + 5, AND_NEUT) {}

  Data merge(Data a, Data b) {
    return Data(a.f & b.f, (a.f & b.g) | (a.g & b.f));
  }

  void pull(int k) {
    st[k] = merge(st[ls], st[rs]);
  }

  void apply(int k, int s, int e, u64 v) {
    st[k].f &= v;
    if (s + 1 != e) {
      st[k].g &= v;
      lazy[k] &= v;
    } else {
      st[k].g = ~st[k].f;
    }
  }

  void push(int k, int s, int e) {
    if (lazy[k] != AND_NEUT) {
      int m = (s + e) >> 1;
      apply(lp, lazy[k]);
      apply(rp, lazy[k]);
      lazy[k] = AND_NEUT;
    }
  }

  Data getG(int k, int s, int e, int a, int b) {
    if (a <= s && e <= b) {
      return st[k];
    }
    push(k, s, e);
    int m = (s + e) >> 1;
    if (b <= m) {
      return getG(lp, a, b);
    }
    if (a >= m) {
      return getG(rp, a, b);
    }
    return merge(getG(lp, a, b), getG(rp, a, b));
  }

  u64 getAns(int k, int s, int e, int a, int b, u64 bit) {
    // cout << s << ' ' << e << ' ' << st[k].f << ' ' << st[k].g << '\n';
    if (a <= s && e <= b && (!bit || (st[k].f & bit))) {
      return st[k].f;
    }
    if (s + 1 == e) {
      return AND_NEUT;
    }
    push(k, s, e);
    int m = (s + e) >> 1;
    if (b <= m) {
      return getAns(lp, a, b, bit);
    }
    if (a >= m) {
      return getAns(rp, a, b, bit);
    }
    return getAns(lp, a, b, bit) & getAns(rp, a, b, bit);
  }

  void set(int k, int s, int e, int i, u64 v) {
    if (s + 1 == e) {
      st[k].f = v;
      st[k].g = ~v;
      return;
    }
    push(k, s, e);
    int m = (s + e) >> 1;
    if (i < m) {
      set(lp, i, v);
    } else {
      set(rp, i, v);
    }
    pull(k);
  }

  void upd(int k, int s, int e, int a, int b, u64 v) {
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

  u64 query(int a, int b) {
    u64 g = getG(0, 0, n, a, b).g, bit = 0;
    for (int i = 63; i >= 0; --i) {
      if ((g >> i) & 1) {
        bit = 1ull << i;
        break;
      }
    }
    // cout << "bit=" << bit << '\n';
    return getAns(0, 0, n, a, b, bit);
  }
  void set(int i, u64 v) {
    set(0, 0, n, i, v);
  }
  void upd(int a, int b, u64 v) {
    upd(0, 0, n, a, b, v);
  }
};

int main() {
  cin.tie(0)->sync_with_stdio(0);

  int n, q;
  cin >> n >> q;

  STree st(n);

  for (int i = 0; i < n; ++i) {
    u64 x;
    cin >> x;
    st.set(i, x);
  }

  while (q--) {
    int t;
    cin >> t;

    if (t == 1) {
      int l, r;
      u64 x;
      cin >> l >> r >> x;
      st.upd(l - 1, r, x);
    } else if (t == 2) {
      int s;
      u64 x;
      cin >> s >> x;
      st.set(s - 1, x);
    } else {
      int l, r;
      cin >> l >> r;
      cout << st.query(l - 1, r) << '\n';
    }
  }

  return 0;
}