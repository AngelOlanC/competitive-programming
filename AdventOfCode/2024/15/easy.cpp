#include <bits/stdc++.h>
using namespace std;
// Pura Gente del Coach Moy

constexpr int DI[4] = {-1, 0, 1, 0}, DJ[4] = {0, 1, 0, -1};

int move(int i, int j, int dir, vector<string>& maze) {
  int ii = i + DI[dir], jj = j + DJ[dir];
  while (maze[ii][jj] == 'O') {
    ii = ii + DI[dir];
    jj = jj + DJ[dir];
  }
  if (maze[ii][jj] == '#') {
    return 0;
  }
  swap(maze[i + DI[dir]][j + DJ[dir]], maze[ii][jj]);
  swap(maze[i][j], maze[i + DI[dir]][j + DJ[dir]]);
  return 1;
}

signed main() {
  cin.tie(0)->sync_with_stdio(0);

  vector<string> maze;
  string line;
  while (getline(cin, line)) {
    if (line.empty()) {
      break;
    }
    maze.push_back(line);
  }

  int n = (int)maze.size(), m = (int)maze[0].size();

  int ri, rj;
  for (int i = 0; i < n; ++i) {
    for (int j = 0; j < m; ++j) {
      if (maze[i][j] == '@') {
        ri = i;
        rj = j;
        break;
      }
    }
  }

  char mov;
  while (cin >> mov) {
    if (mov == '^') {
      ri -= move(ri, rj, 0, maze);
    } else if (mov == '>') {
      rj += move(ri, rj, 1, maze);
    } else if (mov == 'v') {
      ri += move(ri, rj, 2, maze);
    } else {
      rj -= move(ri, rj, 3, maze);
    }
  }

  int ans = 0;
  for (int i = 0; i < n; ++i) {
    for (int j = 0; j < m; ++j) {
      if (maze[i][j] == 'O') {
        ans += 100 * i + j;
      }
    }
  }
  cout << ans << '\n';

  return 0;
}