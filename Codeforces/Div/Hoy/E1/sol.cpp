#include <bits/stdc++.h>
using namespace std;
// Pura Gente del Coach Moy

struct STree {
  #define ls (k << 1) + 1
  #define rs (k << 1) + 2
  #define lp ls, s, m
  #define rp rs, m, e

  int n;
  vector<int> st;

  STree(int n) : n(n), st((n << 2) + 5) {}

  int merge(int x, int y) {
    return x + y;
  }

  void pull(int k) {
    st[k] = merge(st[ls], st[rs]);
  }

  int query(int k, int s, int e, int a, int b) {
    if (a <= s && e <= b) {
      return st[k];
    }
    int m = (s + e) >> 1;
    if (a >= m) {
      return query(rp, a, b);
    }
    if (b <= m) {
      return query(lp, a, b);
    }
    return merge(query(lp, a, b), query(rp, a, b));
  }

  void inc(int k, int s, int e, int i) {
    if (s + 1 == e) {
      ++st[k];
      return;
    }
    int m = (s + e) >> 1;
    if (i < m) {
      inc(lp, i);
    } else {
      inc(rp, i);
    }
    pull(k);
  }

  int query(int a, int b) {
    return query(0, 0, n, a, b);
  }
  void inc(int i) {
    inc(0, 0, n, i);
  }
};

void dfs(int u, int p, int& t, vector<vector<int>>& g, vector<int>& st, vector<int>& en) {
  st[u] = ++t;
  for (int v : g[u]) {
    if (v != p) {
      dfs(v, u, t, g, st, en);
    }
  }
  en[u] = t;
}

void eulerTour(vector<vector<int>>& g, vector<int>& st, vector<int>& en) {
  int t = -1;
  dfs(0, -1, t, g, st, en);
}

void solve() {
  int n;
  cin >> n;

  vector<vector<int>> withWeight(n);
  for (int i = 0; i < n; ++i) {
    int x;
    cin >> x;
    withWeight[x - 1].push_back(i);
  }

  vector<vector<int>> g(n);
  for (int i = 1; i < n; ++i) {
    int u, v;
    cin >> u >> v;
    --u;
    --v;
    g[u].push_back(v);
    g[v].push_back(u);
  }

  vector<int> st(n), en(n);
  eulerTour(g, st, en);

  STree segTree(n);
  for (int i = n - 1, seen = 0; i >= 0; --i) {
    // cout << "w=" << i << ", seen=" << seen << '\n';
    for (int u : withWeight[i]) {
      // cout << "check " << u + 1 << ' ' << segTree.query(st[u], en[u] + 1) << '\n';
      if (segTree.query(st[u], en[u] + 1) < seen) {
        cout << u + 1 << '\n';
        return;
      }
    }
    for (int u : withWeight[i]) {
      segTree.inc(st[u]);
      ++seen;
    }
  }
  cout << "0\n";
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