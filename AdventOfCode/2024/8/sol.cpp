#include <bits/stdc++.h>
using namespace std;
// Pura Gente del Coach Moy
signed main() {
  cin.tie(0)->sync_with_stdio(0);

  vector<string> maze;
  string line;
  while(getline(cin, line)) {
    if (line.empty() || line == "\n") {
      continue;
    }
    maze.push_back(line);
  }
  
  int n = maze.size(), m = maze[0].size();

  auto valid = [&](int i, int j) -> bool {
    return i >= 0 && i < n && j >= 0 && j < m;
  };

  vector<vector<bool>> good(n, vector<bool>(m));
  vector<vector<pair<int, int>>> mp(256);
  for (int i = 0; i < n; ++i) {
    for (int j = 0; j < m; ++j) {
      if (maze[i][j] == '.') {
        continue;
      }
      for (auto [ii, jj] : mp[maze[i][j]]) {
        int di = i - ii, dj = j - jj;
        good[i][j] = true;
        good[ii][jj] = true;
        for (int k = 1; valid(i + di * k, j + dj * k); ++k) {
          good[i + di * k][j + dj * k] = true;
        }
        for (int k = 1; valid(ii - di * k, jj - dj * k); ++k) {
          good[ii - di * k][jj - dj * k] = true;
        }
      }
      mp[maze[i][j]].emplace_back(i, j);
    }
  }
  
  int ans = 0;
  for (int i = 0; i < n; ++i) {
    for (int j = 0; j < m; ++j) {
      if (good[i][j]) {
        ++ans;
      }
    }
  }
  cout << ans << '\n';

  return 0;
}