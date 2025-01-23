#include <bits/stdc++.h>
using namespace std;
// Pura Gente del Coach Moy
using i64 = long long;
constexpr int DI[4] = {-1, 1, 0, 0}, DJ[4] = {0, 0, 1, -1};
int main() {
  vector<vector<int>> maze;
  string line;
  while (cin >> line) {
    vector<int> row;
    for (char c : line) {
      row.push_back(c - '0');
    }
    maze.push_back(row);
  }
  int n = maze.size(), m = maze[0].size();
  vector<vector<pair<int, int>>> oc(10);
  for (int i = 0; i < n; ++i) {
    for (int j = 0; j < m; ++j) {
      oc[maze[i][j]].emplace_back(i, j);
    }
  }
  vector<vector<i64>> dp(n, vector<i64>(m));
  for (int i = 0; i < n; ++i) {
    for (int j = 0; j < m; ++j) {
      if (maze[i][j] == 9) {
        dp[i][j] = 1;
      }
    }
  }
  auto valid = [&](int i, int j) -> bool {
    return i >= 0 && i < n && j >= 0 && j < m;
  };
  for (int k = 9; k >= 1; --k) {
    for (auto &[i, j] : oc[k]) {
      for (int dir = 0; dir < 4; ++dir) {
        int ii = i + DI[dir], jj = j + DJ[dir];
        if (valid(ii, jj) && maze[ii][jj] == k - 1) {
          dp[ii][jj] += dp[i][j];
        }
      }
    }
  }
  i64 ans = 0;
  for (auto &[i, j] : oc[0]) {
    ans += dp[i][j];
  }
  cout << ans << '\n';
  return 0;
}