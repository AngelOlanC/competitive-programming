#include <bits/stdc++.h>
using namespace std;
// Pura Gente del Coach Moy

struct Node {
  int mx, p;
};

struct STree {
  #define ls (k << 1) + 1
  #define rs (k << 1) + 2
  #define lp ls, s, m
  #define rp rs, m, e

  int n;
  vector<Node> st;
  vector<int> lazy;

  STree(int n) : n(n), st((n << 2) + 5), lazy((n << 2) + 5) {}

  void apply(int k, int x) {
    st[k].mx += x;
    lazy[k] += x;
  }

  void push(int k) {
    if (!lazy[k]) {
      return;
    }
    apply(ls, lazy[k]);
    apply(rs, lazy[k]);
    lazy[k] = 0;
  }

  Node comb(const Node a, const Node b) {
    return a.mx > b.mx ? a : b;
  }

  void pull(int k) {
    st[k] = comb(st[ls], st[rs]);
  }

  void build(int k, int s, int e) {
    if (s + 1 == e) {
      st[k] = { s, s };
      return;
    }
    int m = (s + e) >> 1;
    build(lp);
    build(rp);
    pull(k);
  }
  void build() {
    build(0, 0, n);
  }

  void upd(int k, int s, int e, int r) {
    if (e <= r) {
      apply(k, 1);
      return;
    }
    push(k);
    int m = (s + e) >> 1;
    upd(lp, r);
    if (r > m) {
      upd(rp, r);
    }
    pull(k);
  }
  void upd(int r) {
    upd(0, 0, n, r);
  }

  Node query(int k, int s, int e, int r) {
    if (e <= r) {
      return st[k];
    }
    push(k);
    int m = (s + e) >> 1;
    if (r <= m) {
      return query(lp, r);
    }
    return comb(query(lp, r), query(rp, r));
  }
  Node query(int r) {
    return query(0, 0, n, r);
  }
};

int main() {
  cin.tie(0)->sync_with_stdio(0);

  int n;
  cin >> n;

  vector<int> a(n);
  for (int& x : a) {
    cin >> x;
    --x;
  }

  int q;
  cin >> q;

  vector<vector<pair<int, int>>> queries_at_r(n);
  for (int i = 0; i < q; ++i) {
    int l, r;
    cin >> l >> r;
    --l;
    --r;
    queries_at_r[r].emplace_back(l, i);
  }
  
  STree st(n);
  st.build();

  vector<pair<int, int>> ans(q);
  set<tuple<int, int, int>> waiting;
  vector<int> at(n, -1);
  for (int i = 0; i < n; ++i) {
    at[a[i]] = i;
    
    if (a[i] && at[a[i] - 1] != -1) {
      st.upd(at[a[i] - 1] + 1);
    }
    if (a[i] != n - 1 && at[a[i] + 1] != -1) {
      st.upd(at[a[i] + 1] + 1);
    }

    for (auto [l, ind] : queries_at_r[i]) {
      waiting.emplace(-l, ind, i);
    }

    while (!waiting.empty()) {
      auto [l, ind, r] = *waiting.begin();
      l = -l;
      auto x = st.query(l + 1);
      if (x.mx < i) {
        break;
      }
      ans[ind] = { x.p, i };
      waiting.erase(waiting.begin());
    }
  }

  for (auto [l, r] : ans) {
    cout << l + 1 << ' ' << r + 1 << '\n';
  }

  return 0;
}