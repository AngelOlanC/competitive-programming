#include <bits/stdc++.h>
using namespace std;
struct DSU {
  vector<int> e;
  DSU(int n) : e(n, -1) {}
  int size(int x) {
    return -e[get(x)];
  }
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
  DSU dsu(n);
  int max_comp = 1;
  for (int i = 0; i < m; ++i) {
    int u, v;
    cin >> u >> v;
    --u;
    --v;
    if (dsu.get(u) != dsu.get(v)) {
      dsu.join(u, v);
      --n;
      max_comp = max(max_comp, dsu.size(u));
    }
    cout << n << ' ' << max_comp << '\n';
  }
}