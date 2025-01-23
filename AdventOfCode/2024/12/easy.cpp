#include <bits/stdc++.h>
using namespace std;
// Pura Gente del Coach Moy

using i64 = long long;

constexpr int DI[4] = {-1, 1, 0, 0}, DJ[4] = {0, 0, 1, -1};

int n, m;
vector<string> maze;
vector<vector<int>> comp;
vector<int> area, perimeter;

bool valid(int i, int j) {
  return i >= 0 && i < n && j >= 0 && j < m;
}

void dfs(int i, int j) {
  comp[i][j] = area.size() - 1;
  ++area.back();
  for (int dir = 0; dir < 4; ++dir) {
    int ii = i + DI[dir], jj = j + DJ[dir];
    if (valid(ii, jj) && comp[ii][jj] == -1 && maze[ii][jj] == maze[i][j]) {
      dfs(ii, jj);
    } else if (!valid(ii, jj) || maze[ii][jj] != maze[i][j]) {
      ++perimeter.back();
    }
  }
}

signed main() {
  cin.tie(0)->sync_with_stdio(0);

  string line;
  while (cin >> line) {
    maze.push_back(line);
    ++n;
  }
  m = maze[0].size();

  comp.assign(n, vector<int>(m, -1));
  i64 ans = 0;
  for (int i = 0; i < n; ++i) {
    for (int j = 0; j < m; ++j) {
      if (comp[i][j] != -1) {
        continue;
      }
      area.push_back(0);
      perimeter.push_back(0);
      dfs(i, j);
      ans += (i64)area.back() * perimeter.back();
    }
  }
  cout << ans << '\n';

  return 0;
}