#include <bits/stdc++.h>
using namespace std;
// Pura Gente del Coach Moy

struct DSU {
  vector<int> e;

  DSU(int n) : e(n, -1) {}

  int get(int x) {
    return e[x] < 0 ? x : get(e[x]);
  }

  void join(int x, int y) {
    x = get(x);
    y = get(y);
    if (e[x] > e[y]) {
      swap(x, y);
    }
    if (x != y) {
      e[x] += e[y];
      e[y] = x;
    }
  }

  int components() {
    int ret = 0;
    for (int i = 0; i < (int)e.size(); ++i) {
      if (e[i] < 0) {
        ++ret;
      }
    }
    return ret;
  }
};

void solve() {
  int n, m1, m2;
  cin >> n >> m1 >> m2;

  vector<pair<int, int>> eF(m1);
  for (auto& [u, v] : eF) {
    cin >> u >> v;
    --u;
    --v;
  }

  DSU dsuG(n);
  for (int i = 0; i < m2; ++i) {
    int u, v;
    cin >> u >> v;
    --u;
    --v;
    dsuG.join(u, v);
  }

  DSU dsuF(n);
  int ans = 0;
  for (auto [u, v] : eF) {
    if (dsuG.get(u) == dsuG.get(v)) {
      dsuF.join(u, v);
    } else {
      ++ans;
    }
  }
  ans += dsuF.components() - dsuG.components();
  cout << ans << '\n';
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