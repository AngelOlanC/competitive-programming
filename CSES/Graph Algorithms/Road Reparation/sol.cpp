#include <bits/stdc++.h>
using namespace std;
struct DSU {
  vector<int> e;
  DSU(int n) : e(n, -1) {}
  int get(int x) {
    if (e[x] < 0) {
      return x;
    }
    return get(e[x]);
  }
  void join(int x, int y) {
    x = get(x);
    y = get(y);
    if (e[x] > e[y]) {
      swap(x, y);
    }
    e[x] += e[y];
    e[y] = x;
  }
};
using i64 = long long;
int main() {
  cin.tie(0)->sync_with_stdio(0);
  int n, m;
  cin >> n >> m;
  vector<tuple<int, int, int>> e(m);
  for (auto &[w, u, v] : e) {
    cin >> u >> v >> w;
    --u;
    --v;
  }
  sort(e.begin(), e.end());
  DSU dsu(n);
  i64 cost = 0;
  for (auto &[w, u, v] : e) {
    if (dsu.get(u) != dsu.get(v)) {
      dsu.join(u, v);
      cost += w;
      --n;
    }
  }
  if (n > 1) {
    cout << "IMPOSSIBLE\n";
    return 0;
  }
  cout << cost << '\n';
}