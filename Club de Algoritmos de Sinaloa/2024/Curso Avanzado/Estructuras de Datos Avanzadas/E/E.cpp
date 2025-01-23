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
    Node() : v(NEUT), l(0), r(0) {}
    Node(int _v, int _l, int _r) {
      v = _v;
      l = _v;
      r = _r;
    }
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
 
  int cloneNode(Node node) {
    st.emplace_back(node.v, node.l, node.r);
    return (int)st.size() - 1;
  }

	int build(int k, int s, int e, vector<int>& a) {
		k = cloneNode(st[k]);
		if (s + 1 == e) {
			st[k].v = a[s];
			return;
		}
		int m = (s + e) >> 1;
		ls = build(lp, a);
		rs = build(rp, a);
		pull(k);
		return k;
	}
 
  int query(int k, int s, int e, int a, int b) {
    if (e <= a || s >= b) {
      return NEUT;
    }
    if (a <= s && e <= b) {
      return st[k].v;
    }
    int m = (s + e) >> 1;
    return merge(query(lp, a, b), query(rp, a, b));
  }
 
  int upd(int k, int s, int e, int a, int b, int v) {
    k = cloneNode(st[k]);
    
    int m = (s + e) >> 1;
    if (i < m) {
      ls = upd(lp, i, v);
    } else {
      rs = upd(rp, i, v);
    }
    pull(k);
    return k;
  }
	
	int build(vector<int>& a) {
		return build(0, 0, n, a);
	}
  int query(int a, int b) {
    return query(0, 0, n, a, b);
  }
  int upd(int a, int b, int v) {
    return upd(0, 0, n, a, b, v);
  }
};

signed main() {
  cin.tie(0)->sync_with_stdio(0);
  
  int n, k;
  cin >> n >> k;

  vi a(n);
  FOR (i, 0, n) cin >> a[i];

  vi roots;
  STree st(n);
  roots.pb(st.build(a));

  int last_root = roots[0];
  while (k--) {
    char op;
    cin >> op;
    if (op == 'U') {
      int l, r, x;
      cin >> l >> r >> x;
      last_root = st.upd(last_root, l - 1, r, x);
      roots.pb(last_root);
      continue;
    }
    if (op == 'Q') {
      int l, r;
      cin >> l >> r;
      cout << st.query(last_root, l - 1, r) << ENDL;
      continue;
    }
    int x;
    cin >> x;
    last_root = roots[x];
  }


  return 0;
}