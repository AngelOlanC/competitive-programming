#include <bits/stdc++.h>
using namespace std;
using i64 = long long;
constexpr i64 INF = 1e18;
struct STree {
  struct Node {
    i64 ans;
    i64 single;
    i64 single_suffix;
    i64 suffix;
    i64 prefix_single;
    i64 prefix;
    i64 all;
    i64 prefix_suffix;
    int l;
    int r;
    Node() {
      ans = single = single_suffix = suffix = prefix_single = prefix = all = prefix_suffix = -INF;
    }
  };
  #define lson (k << 1) + 1
  #define rson (k << 1) + 2
  #define lpart lson, s, m
  #define rpart rson, m, e
  int n;
  vector<Node> st;
  vector<int> A, B;
  STree(vector<int> A, vector<int> B) : n((int)A.size()), st(4 * n + 5), A(A.begin(), A.end()), B(B.begin(), B.end()) {}
  Node merge(Node a, Node b) {
    Node c;
    c.ans = max({ a.ans,
                  b.ans,
                  a.single + b.single,
                  a.single_suffix + b.prefix,
                  a.suffix + b.prefix_single});
    c.single = max({ a.single,
                     b.single,
                     a.suffix + b.prefix
    });
    c.single_suffix = max({ a.suffix + b.prefix_suffix,
                            b.single_suffix,
                            a.single + b.suffix,
                            a.single_suffix + b.all - B[b.l]
    });
    c.suffix = max({ b.suffix,
                     a.suffix + b.all - B[b.l]
    });
    c.prefix_single = max({ a.prefix_suffix + b.prefix,
                            a.prefix_single,
                            a.prefix + b.single,
                            a.all - B[a.r - 1] + b.prefix_suffix
    });
    c.prefix = max({ a.prefix,
                     a.all - B[a.r - 1] + b.prefix
    });
    c.all = a.all - B[a.r - 1] + b.all - B[b.l];
    c.prefix_suffix = max({ a.prefix + b.suffix,
                            a.all - B[a.r - 1] + a.prefix_suffix,
                            a.prefix_suffix + b.all - B[b.l]
    });
    c.l = a.l;
    c.r = b.r;
    return c;
  }
  Node createLeafNode(int s) {
    Node ret = Node();
    ret.single = ret.all = (i64)A[s] + 2 * B[s];
    ret.prefix = ret.suffix = A[s] + B[s];
    ret.l = s;
    ret.r = s + 1;
    return ret;
  }
  void build(int k, int s, int e) {
    if (s + 1 == e) {
      st[k] = createLeafNode(s);
      return;
    }
    int m = (s + e) >> 1;
    build(lpart);
    build(rpart);
    st[k] = merge(st[lson], st[rson]);
    cout << s << ' ' << e << '\n' << st[k].ans << '\n';
  }
  void build() {
    build(0, 0, n);
  }
  void upd(int k, int s, int e, int i, int v, bool is_a) {
    if (s + 1 == e) {
      if (is_a) {
        A[s] = v;
      } else {
        B[s] = v;
      }
      st[k] = createLeafNode(s);
      return;
    }
    int m = (s + e) >> 1;
    if (m < i) {
      upd(lpart, i, v, is_a);
    } else {
      upd(rpart, i, v, is_a);
    }
    st[k] = merge(st[lson], st[rson]);
  }
  void upd(int i, int v, bool is_a) {
    upd(0, 0, n, i, v, is_a);
  }
  Node query(int k, int s, int e, int a, int b) {
    if (s >= a && e <= b) {
      return st[k];
    }
    int m = (s + e) >> 1;
    if (a < m) {
      if (b > m) {
        return merge(query(lpart, a, b), query(rpart, a, b));   
      }
      return query(lpart, a, b);
    }
    return query(rpart, a, b);
  }
  i64 query(int a, int b) {
    return query(0, 0, n, a, b).ans;
  }
};
int main() {
  cin.tie(0)->sync_with_stdio(0);
  int n;
  cin >> n;
  vector<int> A(n), B(n);
  for (int i = 0; i < n; ++i) {
    cin >> A[i];
  }
  for (int i = 0; i < n; ++i) {
    cin >> B[i];
  }
  STree st(A, B);
  st.build();
  int q;
  cin >> q;
  while (q--) {
    int t, a, b;
    cin >> t >> a >> b;
    if (t == 1) {
      st.upd(a - 1, b, true);
      continue;
    }
    if (t == 2) {
      st.upd(a - 1, b, false);
      continue;
    }
    cout << st.query(a - 1, b) << '\n';
  }
}