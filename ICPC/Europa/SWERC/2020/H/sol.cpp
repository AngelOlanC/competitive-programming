#include <bits/stdc++.h>
using namespace std;
// BRO
using ll = long long;
using pi = pair<int, int>;
using vi = vector<int>;

#define pb push_back
#define SZ(x) ((int)(x).size())
#define ALL(x) begin(x), end(x)
#define FOR(i, a, b) for (int i = (int)a; i < (int)b; ++i)
#define ROF(i, a, b) for (int i = (int)a-1; i >= (int)b; --i)
#define ENDL '\n'
#define __   ios_base::sync_with_stdio(0); cin.tie(nullptr);

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
      l = _l;
      r = _r;
    }
  };
 
  int n, lastRoot;
  vector<Node> st;
 
  STree(int n) : n(n), st(1) {}
 
  int merge(int x, int y) {
    return x + y;
  }
 
  void pull(int k) {
    st[k].v = merge(st[ls].v, st[rs].v);
  }
 
  int cloneNode(Node node) {
    st.emplace_back(node.v, node.l, node.r);
    return (int)st.size() - 1;
  }

  int build(int k, int s, int e, vector<int>& a) {
    k = cloneNode(st[k]);
    if (s + 1 == e) {
      st[k].v = a[s];
      return k;
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
 
  int upd(int k, int s, int e, int i, int v) {
    k = cloneNode(st[k]);
    if (s + 1 == e) {
      st[k].v = v;
      return k;
    }
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
    return lastRoot = build(0, 0, n, a);
  }

  int query(int k, int a, int b) {
    return query(k, 0, n, a, b);
  }
  int query(int a, int b) {
    return query(lastRoot, a, b);
  }

  int upd(int k, int i, int v) {
    return lastRoot = upd(k, 0, n, i, v);
  }
  int upd(int i, int v) {
    return upd(lastRoot, i, v);
  }
};

int main() { __
  int N;
  cin >> N;
  STree st(N);
  string line;
  getline(cin, line);
  vi roots(N + 1);
  roots[0] = 0;
  FOR (t, 1, N + 1) {
    getline(cin, line);
    stringstream ss(line);
    char c;
    int x;
    roots[t] = roots[t - 1];
    while(ss >> c >> x) roots[t] = st.upd(x, c == '+');
  }

  int x = 0;
  FOR (i, 0, N) {
    int d;
    cin >> d;
    x = (x + st.query(roots[d], x, N)) % N;
  }
  cout << x << '\n';

  return 0;
}