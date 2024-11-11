#include <bits/stdc++.h>
using namespace std;

constexpr int INF = 1e9;

struct STree {
  #define ls (k<<1)+1
  #define rs (k<<1)+2
  #define lp ls, s, m
  #define rp rs, m, e
  int n;
  vector<int> st;
  STree(int n) : n(n), st((n << 2) + 5, INF) {}
  int comb(int x, int y) { return min(x, y); }
  void upd(int k, int s, int e, int i, int x) {
    if (s + 1 == e) {
      st[k] = x;
      return;
    }
    int m = (s + e) >> 1;
    if (i < m) {
      upd(lp, i, x);
    } else {
      upd(rp, i, x);
    }
    st[k] = comb(st[ls], st[rs]);
  }
  void upd(int i, int x) { return upd(0, 0, n, i, x); }
  int query(int k, int s, int e, int a, int b) {
    if (s >= a && e <= b) {
      return st[k];
    }
    int m = (s + e) >> 1, ans = INF;
    if (a < m) {
      ans = comb(ans, query(lp, a, b));
    }
    if (b > m) {
      ans = comb(ans, query(rp, a, b));
    }
    return ans;
  }
  int query(int a, int b) { return query(0, 0, n, a, b); }
};

signed main() {
  cin.tie(0)->sync_with_stdio(0);

  int n, m;
  cin >> n >> m;
  vector<vector<pair<int, int>>> g(n);
  while (m--) {
    int u, v, w;
    cin >> u >> v >> w;
    g[u].push_back({v, w});
    g[v].push_back({u, w});
  }

  vector<vector<int>> d(3, vector(n, INF));
  for (int i = 0; i < 3; ++i) {
    priority_queue<pair<int, int>> pq;
    pq.push({0, i});
    d[i][i] = 0;
    while (!pq.empty()) {
      auto [du, u] = pq.top();
      pq.pop();
      du = -du;
      if (du > d[i][u]) {
        continue;
      }
      for (auto &[v, w] : g[u]) {
        if (du + w < d[i][v]) {
          d[i][v] = du + w;
          pq.push({-d[i][v], v});
        }
      }
    }
  }

  vector<int> v;
  for (int i = 0; i < n; ++i) {
    v.push_back(d[0][i]);
    v.push_back(d[1][i]);
    v.push_back(d[2][i]);
  }

  sort(v.begin(), v.end());
  v.erase(unique(v.begin(), v.end()), v.end());

  auto get = [&](int x) -> int {
    return lower_bound(v.begin(), v.end(), x) - v.begin();
  };

  map<array<int, 3>, int> mp;
  for (int i = 0; i < n; ++i) {
    ++mp[{get(d[0][i]), get(d[1][i]), get(d[2][i])}];
  }

  STree st(v.size());
  int ans = 0;
  for (auto &[a, cnt] : mp) {
    auto [x, y, z] = a;
    if (z < st.query(0, y + 1)) {
      ans += cnt;
      st.upd(y, z);
    }
  }
  cout << ans << '\n';

  return 0;
}