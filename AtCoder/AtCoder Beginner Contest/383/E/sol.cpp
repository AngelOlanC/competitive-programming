#include <bits/stdc++.h>
using namespace std;

struct DSU {
  vector<int> e;
  vector<int> cntA;
  vector<int> cntB;
  DSU(int n) : e(n, -1), cntA(n, 0), cntB(n, 0) {}
  int get(int x) {
    if (e[x] < 0) {
      return x;
    }
    return e[x] = get(e[x]);
  }
  bool join(int x, int y) {
    x = get(x);
    y = get(y);
    if (e[x] > e[y]) {
      swap(x, y);
    }
    if (x == y) {
      return false;
    }
    e[y] = x;
    cntA[x] += cntA[y];
    cntB[x] += cntB[y];
    return true;
  }
};

using i64 = long long;

int main() {
  cin.tie(0)->sync_with_stdio(0);

  int n, m, k;
  cin >> n >> m >> k;
  
  vector<tuple<int, int, int>> e(m);
  for (auto &[w, u, v] : e) {
    cin >> u >> v >> w;
    --u;
    --v;
  }

  DSU dsu(n);
  for (int i = 0; i < k; ++i) {
    int x;
    cin >> x;
    --x;
    ++dsu.cntA[x];
  }
  for (int i = 0; i < k; ++i) {
    int x;
    cin >> x;
    --x;
    ++dsu.cntB[x];
  }

  sort(e.begin(), e.end());

  i64 ans = 0;
  for (auto &[w, u, v] : e) {
    if (dsu.join(u, v)) {
      int x = dsu.get(u);
      int k = min(dsu.cntA[x], dsu.cntB[x]);
      ans += (i64)w * k;
      dsu.cntA[x] -= k;
      dsu.cntB[x] -= k;
    }
  }
  cout << ans << '\n';
}