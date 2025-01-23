#include <bits/stdc++.h>
using namespace std;
// Pura Gente del Coach Moy

constexpr int INF = 1e9;

struct STree {
  struct Node {
    int mnL, mnR, mxL, mxR, ansL, ansR;

    Node() : mnL(INF), mnR(INF), mxL(-INF), mxR(-INF), ansL(0), ansR(0) {}
  };

  #define ls (k << 1) + 1
  #define rs (k << 1) + 2
  #define lp ls, s, m
  #define rp rs, m, e

  int n;
  vector<Node> st;

  STree(int n) : n(n), st((n << 2) + 5) {}

  // iz + der
  Node merge(Node x, Node y) {
    Node ret = Node();
    ret.mnL = min(x.mnL, y.mnL);
    ret.mnR = min(x.mnR, y.mnR);
    ret.mxL = max(x.mxL, y.mxL);
    ret.mxR = max(x.mxR, y.mxR);
    ret.ansL = max({x.ansL, y.ansL, y.mxL - x.mnL});
    ret.ansR = max({x.ansR, y.ansR, x.mxR - y.mnR});
    return ret;
  }

  void pull(int k) {
    st[k] = merge(st[ls], st[rs]);
  }

  void upd(int k, int s, int e, int i, pair<int, int> v) {
    if (s + 1 == e) {
      auto [x, y] = v;
      st[k].mnL = st[k].mxL = x;
      st[k].mnR = st[k].mxR = y;
      return;
    }
    int m = (s + e) >> 1;
    if (i < m) {
      upd(lp, i, v);
    } else {
      upd(rp, i, v);
    }
    pull(k);
  }
  
  int query() {
    return max(st[0].ansL, st[0].ansR);
  }
  void upd(int i, pair<int, int> v) {
    upd(0, 0, n, i, v);
  }
};

void solve() {
  int n, q;
  cin >> n >> q;

  STree st(n);
  for (int i = 0; i < n; ++i) {
    int x;
    cin >> x;
    st.upd(i, make_pair(x - i, x - n + i + 1));
  }

  cout << st.query() << '\n';

  while (q--) {
    int i, x;
    cin >> i >> x;
    --i;

    st.upd(i, make_pair(x - i, x - n + i + 1));

    cout << st.query() << '\n';
  }
}

int main() {
  cin.tie(0)->sync_with_stdio(0);

  int t;
  cin >> t;
  while (t--) {
    solve();
  }

  return 0;
}