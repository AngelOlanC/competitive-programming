#include <bits/stdc++.h>
using namespace std;

constexpr int di[8] = {0, -1, -1, -1, 0, 1, 1, 1}, dj[8] = {-1, -1, 0, 1, 1, 1, 0, -1};

int n, m;
vector<string> maze;

bool valid(int i, int j) {
  return i >= 0 && i < n && j >= 0 && j < m;
}

bool has(string word, int dir, int i, int j) {
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
      for (int dir = 0; dir < 8; ++dir) {
        ans += has("XMAS", dir, i, j);
      }
    }
  }
  cout << ans << '\n';
}