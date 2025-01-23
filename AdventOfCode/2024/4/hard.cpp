#include <bits/stdc++.h>
using namespace std;

constexpr int di[4] = {1, 1, -1, -1}, dj[4] = {1, -1, -1, 1};

int n, m;
vector<string> maze;

bool valid(int i, int j) {
  return i >= 0 && i < n && j >= 0 && j < m;
}

bool has(string word, int i, int j, int dir) {
  for (auto &c : word) {
    if (!valid(i, j) || maze[i][j] != c) {
      return 0;
    }
    i += di[dir];
    j += dj[dir];
  }
  return true;
}

int main() {
  string line;
  while (cin >> line) {
    maze.push_back(line);
  }
  n = (int)maze.size(), m = (int)maze[0].size();
  int ans = 0;
  for (int i = 0; i < n; ++i) {
    for (int j = 0; j < m; ++j) {
      ans += has("MAS", i, j, 0) && has("MAS", i, j + 2, 1);
      ans += has("MAS", i, j, 0) && has("MAS", i + 2, j, 3);
      ans += has("MAS", i + 2, j + 2, 2) && has("MAS", i, j + 2, 1);
      ans += has("MAS", i + 2, j + 2, 2) && has("MAS", i + 2, j, 3);
    }
  }
  cout << ans << '\n';
}