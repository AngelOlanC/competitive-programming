#include <bits/stdc++.h>
using namespace std;
// Pura Gente del Coach Moy

constexpr int DI[4] = {-1, 0, 1, 0}, DJ[4] = {0, 1, 0, -1};

bool dfs_vert(int i, int j, int dir, vector<string>& maze) {
  int ii = i + DI[dir];
  char c = maze[ii][j]; 
  if (c == '.') {
    return true;
  }
  if (c == '#') {
    return false;
  }
  if (c == '[') {
    return dfs_vert(ii, j, dir, maze) && dfs_vert(ii, j + 1, dir, maze);
  }
  return dfs_vert(ii, j, dir, maze) && dfs_vert(ii, j - 1, dir, maze);
}

void move_vert(int i, int j, int dir, vector<string>& maze, vector<vector<bool>>& vis) {
  if (vis[i][j]) {
    return;
  }
  vis[i][j] = true;
  int ii = i + DI[dir];
  char c = maze[ii][j];
  if (c != '.') {
    move_vert(ii, j, dir, maze, vis);
  }
  if (c == '[') {
    move_vert(ii, j + 1, dir, maze, vis);
  } else if (c == ']') {
    move_vert(ii, j - 1, dir, maze, vis);
  }
  swap(maze[i][j], maze[ii][j]);
}

bool dfs_hor(int i, int j, int dir, vector<string>& maze) {
  int jj = j + DJ[dir];
  char c = maze[i][jj]; 
  if (c == '.') {
    return true;
  }
  if (c == '#') {
    return false;
  }
  return dfs_hor(i, jj + DJ[dir], dir, maze);
}

void move_hor(int i, int j, int dir, vector<string>& maze) {
  int jj = j + DJ[dir];
  if (maze[i][jj] != '.') {
    move_hor(i, jj, dir, maze);
  }
  swap(maze[i][j], maze[i][jj]);
}

int move(int i, int j, int dir, vector<string>& maze) {
  if (dir % 2 == 0) {
    if (!dfs_vert(i, j, dir, maze)) {
      return 0;
    }
    int n = (int)maze.size(), m = (int)maze[0].size();
    vector<vector<bool>> vis(n, vector<bool>(m));
    move_vert(i, j, dir, maze, vis);
    return 1;
  }
  if (!dfs_hor(i, j, dir, maze)) {
    return 0;
  }
  move_hor(i, j, dir, maze);
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
    string line2 = "";
    for (auto &c : line) {
      if (c == '#') {
        line2 += "##";
      } else if (c == 'O') {
        line2 += "[]";
      } else if (c == '.') {
        line2 += "..";
      } else if (c == '@') {
        line2 += "@.";
      }
    }
    maze.push_back(line2);
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
      if (maze[i][j] == '[') {
        ans += 100 * i + j;
      }
    }
  }
  cout << ans << '\n';

  return 0;
}