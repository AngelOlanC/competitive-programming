#include <bits/stdc++.h>
using namespace std;
constexpr int di[4] = {-1, 1, 0, 0}, dj[4] = {0, 0, 1, -1};
int main() {
  cin.tie(0)->sync_with_stdio(0);
  int n, m;
  cin >> n >> m;
  vector<vector<char>> a(n, vector<char>(m));
  for (int i = 0; i < n; ++i) {
    for (int j = 0; j < m; ++j) {
      cin >> a[i][j];
    }
  }
  auto valid = [&](int i, int j) -> bool {
    return i >= 0 && i < n && j >= 0 && j < m;
  };
  auto dfs = [&](auto &&self, int i, int j) -> void {
    a[i][j] = '#';
    for (int dir = 0; dir < 4; ++dir) {
      int ii = i + di[dir], jj = j + dj[dir];
      if (valid(ii, jj) && a[ii][jj] != '#') {
        self(self, ii, jj);
      }
    }
  };
  int ans = 0;
  for (int i = 0; i < n; ++i) {
    for (int j = 0; j < m; ++j) {
      if (a[i][j] != '#') {
        dfs(dfs, i, j);
        ++ans;
      }
    }
  }
  cout << ans << '\n';
}