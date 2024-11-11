#include <bits/stdc++.h>
using namespace std;

using i64 = long long;

struct FT {
  vector<i64> s;
  FT(int n) : s(n) {}
  void upd(int pos, i64 dif) { // a[pos] += dif
    for (; pos < (int)s.size(); pos |= pos + 1) s[pos] += dif;
  }
  i64 query(int pos) { // sum of values in [0, pos)
    i64 res = 0;
    for (; pos > 0; pos &= pos - 1) res += s[pos-1];
    return res;
  }
};

signed main() {
  cin.tie(0)->sync_with_stdio(0);

  int n;
  cin >> n;
  vector<vector<int>> a(3, vector<int>(n));
  for (int i = 0; i < 3; ++i) {
    for (int j = 0; j < n; ++j) {
      cin >> a[i][j];
      --a[i][j];
    }
  }

  auto f = [&](int x, int y) -> i64 {
    FT ft(n);
    vector<int> pos(n);
    for (int i = 0; i < n; ++i) {
      pos[a[x][i]] = i;
    }
    i64 ans = 0;
    for (int i = n - 1; i >= 0; --i) {
      ans += ft.query(pos[a[y][i]]);
      ft.upd(pos[a[y][i]], 1);
    }
    return ans;
  };

  i64 ans = (i64)n * (n - 1) / 2;
  ans -= (f(0, 1) + f(1, 2) + f(2, 0)) / 2;
  cout << ans << '\n';

  return 0;
}
