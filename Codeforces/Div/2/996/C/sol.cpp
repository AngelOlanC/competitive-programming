#include <bits/stdc++.h>
using namespace std;
// Pura Gente del Coach Moy

using i64 = long long;

void solve() {
  int n, m;
  string path;
  cin >> n >> m >> path;

  vector<vector<i64>> a(n, vector<i64>(m));
  vector<i64> r(n), c(m);
  for (int i = 0; i < n; ++i) {
    for (int j = 0; j < m; ++j) {
      cin >> a[i][j];
      r[i] += a[i][j];
      c[j] += a[i][j];
    }
  }

  {
    int i = 0, j = 0;
    for (char mov : path) {
      if (mov == 'D') {
        c[j] -= a[i][j];
        a[i][j] = -r[i];
        r[i] = 0;
        c[j] += a[i][j];
        ++i;
      } else {
        r[i] -= a[i][j];
        a[i][j] = -c[j];
        c[j] = 0;
        r[i] += a[i][j];
        ++j;
      }
    }
    a.back().back() = -r.back();
    c.back() -= r.back();
    r.back() = 0;
  }

  for (int i = 0; i < n; ++i) {
    for (int j = 0; j < m; ++j) {
      cout << a[i][j] << " \n"[j == m - 1];
    }
  }

  for (int i = 0; i < n; ++i) {
    assert(!r[i]);
  }
  for (int j = 0; j < m; ++j) {
    assert(!c[j]);
  }
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