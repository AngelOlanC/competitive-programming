#include <bits/stdc++.h>
using namespace std;
// Pura Gente del Coach Moy
using ll = long long;
using pi = pair<int, int>;
using vi = vector<int>;
 
#define pb push_back
#define SZ(x) ((int)(x).size())
#define ALL(x) begin(x), end(x)
#define FOR(i, a, b) for (int i = (int)a; i < (int)b; ++i)
#define ROF(i, a, b) for (int i = (int)a - 1; i >= (int)b; --i)
#define ENDL '\n'
 
struct STree {
  #define ls st[k].l
  #define rs st[k].r
  #define lp ls, s, m
  #define rp rs, m, e
  #define NEUT 0

  struct Node {
    int v, l, r;
    Node() : v(NEUT), l(-1), r(-1) {}
  };

  int n;
  vector<Node> st;

  STree(int n) : n(n), st(1) {}

  int merge(int x, int y) {
    return x + y;
  }

  int get(int k) {
    return k == -1 ? NEUT : st[k].v;
  }

  void pull(int k) {
    st[k].v = merge(get(ls), get(rs));
  }

  int addNode() {
    st.emplace_back();
    return (int)st.size() - 1;
  }

  int query(int k, int s, int e, int a, int b) {
    if (k == -1 || e <= a || s >= b) {
      return NEUT;
    }
    if (a <= s && e <= b) {
      return st[k].v;
    }
    int m = (s + e) >> 1;
    return merge(query(lp, a, b), query(rp, a, b));
  }

  void upd(int k, int s, int e, int i, int v) {
    if (s + 1 == e) {
      st[k].v += v;
      return;
    }
    int m = (s + e) >> 1;
    if (i < m) {
      if (ls == -1) {
        ls = addNode();
      }
      upd(lp, i, v);
    } else {
      if (rs == -1) {
        rs = addNode();
      }
      upd(rp, i, v);
    }
    pull(k);
  }

  int query(int a, int b) {
    return query(0, 0, n, a, b);
  }
  void upd(int i, int v) {
    upd(0, 0, n, i, v);
  }
};
 
signed main() {
  cin.tie(0)->sync_with_stdio(0);
 
  int n, q;
  cin >> n >> q;
  vi A(n);
  STree st(1e9 + 5);
  FOR (i, 0, n) {
    cin >> A[i];
    st.upd(A[i], 1);
  }
  while (q--) {
    char op;
    int a, b;
    cin >> op >> a >> b;
    if (op == '?') {
      cout << st.query(a, b + 1) << ENDL ;
      continue;
    }
    st.upd(A[--a], -1);
    st.upd(A[a] = b, 1);
  }
 
  return 0;
}