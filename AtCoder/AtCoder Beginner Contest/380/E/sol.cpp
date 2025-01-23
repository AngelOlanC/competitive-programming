#include <bits/stdc++.h>
using namespace std;
// Pura gente del coach moy
struct DSU {
  vector<int> e, l;
  DSU(int n) : e(n, -1), l(n) {
    iota(l.begin(), l.end(), 0);
  }
  int size(int x) {
    return -e[get(x)];
  }
  int left(int x) {
    return l[get(x)];
  }
  int get(int x) {
    return e[x] < 0 ? x : get(e[x]);
  }
  void join(int x, int y) {
    x = get(x);
    y = get(y);
    if (e[x] > e[y]) {
      swap(x, y);
    }
    e[x] += e[y];
    e[y] = x;
    if (l[y] < l[x]) {
      l[x] = l[y];
    }
  }
};
int main() {
  cin.tie(0)->sync_with_stdio(0);
  int n, q;
  cin >> n >> q;
  vector<int> cntColor(n, 1), col(n);
  iota(col.begin(), col.end(), 0);
  DSU dsu(n);
  while (q--) {
    int t;
    cin >> t;
    if (t == 2) {
      int c;
      cin >> c;
      --c;
      cout << cntColor[c] << '\n';
      continue;
    }
    int x, c;
    cin >> x >> c;
    --x;
    --c;
    int p = dsu.get(x), l = dsu.left(x);
    if (col[p] == c) {
      continue;
    }
    cntColor[col[p]] -= dsu.size(p);
    col[p] = c;
    cntColor[col[p]] += dsu.size(p);
    if (l + dsu.size(p) != n) {
      int p2 = dsu.get(l + dsu.size(p));
      if (col[p] == col[p2]) {
        dsu.join(p, p2);
      }
    }
    if (l) {
      int p2 = dsu.get(l - 1);
      if (col[p] == col[p2]) {
        dsu.join(p, p2);
      }
    }
  }
}