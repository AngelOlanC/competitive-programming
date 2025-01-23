#include <bits/stdc++.h>
using namespace std;
// Pura Gente del Coach Moy
constexpr int DI[4] = {-1, 1, 0, 0}, DJ[4] = {0, 0, 1, -1};
vector<vector<int>> maze;
int n, m;
bool valid(int i, int j, int last) {
  return i >= 0 && i < n && j >= 0 && j < m && maze[i][j] == last + 1;
}
int dfs(int i, int j) {
  if (maze[i][j] == 9) {
    return 1;
  }
  int ret = 0;
  for (int dir = 0; dir < 4; ++dir) {
    int ii = i + DI[dir], jj = j + DJ[dir];
    if (valid(ii, jj, maze[i][j])) {
      ret += dfs(ii, jj);
    }
  }
  return ret;
}
int main() {
  string line;
  while (cin >> line) {
    vector<int> row;
    for (char c : line) {
      row.push_back(c - '0');
    }
    maze.push_back(row);
  }
  n = maze.size(), m = maze[0].size();
  vector<vector<bool>> vis(n, vector<bool>(m));
  int ans = 0;
  for (int i = 0; i < n; ++i) {
    for (int j = 0; j < m; ++j) {
      if (maze[i][j] == 0) {
        ans += dfs(i, j);
        for (int k = 0; k < n; ++k) {
          for (int l = 0; l < m; ++l) {
            vis[k][l] = false;
          }
        }
      }
    }
  }
  cout << ans << '\n';
  return 0;
}